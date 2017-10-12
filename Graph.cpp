#include "Graph.h"

using namespace std;

Graph::Graph() :
	WEIGHT_STRAIGHT(90),
	WEIGHT_DIAGO(63)
{
	nodes.reserve(1984+2);
	for (int i=0; i<(1984+2); ++i) {
		nodes.push_back(Node(i));
	}
}
Graph::Graph(uint16_t num) :
	WEIGHT_STRAIGHT(90),
	WEIGHT_DIAGO(63)
{
	nodes.reserve(num);
	for (int i=0; i<num; ++i) {
		nodes.push_back(Node(i));
	}
}

Graph::~Graph(){}


/// @todo 範囲外アクセスしないようにあれこれする
uint16_t Graph::cnvCoordinateToNum(int16_t x, int16_t y, MazeAngle angle){
	if (x == 0 && y == 0 && angle == MazeAngle::SOUTH) return 1984;
	if (x > 31 || x < 0 || y > 31 || y < 0
		|| (angle == MazeAngle::NORTH && x == 31)
		|| (angle == MazeAngle::EAST && y == 31)
		) {
		return 1985;
	}

	if (angle == MazeAngle::SOUTH) return cnvCoordinateToNum(x, y-1, MazeAngle::NORTH);
	else if (angle == MazeAngle::WEST) return cnvCoordinateToNum(x-1, y, MazeAngle::EAST);
	else if (angle == MazeAngle::NORTH) return 63*x + y*2 + 1;
	else return 63*x + y*2;
}

void Graph::cnvNumToCoordinate(uint16_t num, int16_t& x, int16_t& y, MazeAngle& angle){
	if (num == 1984) {
		x = 0; y = 0; angle = MazeAngle::SOUTH;
		return;
	}

	x = num/63;
	if ((num%63)%2 == 0) {
		angle = MazeAngle::EAST;
		y = (num%63)/2;
	} else {
		angle = MazeAngle::NORTH;
		y = (num%63-1)/2;
	}
}


void Graph::connectNodes(const uint16_t node1, const uint16_t node2, const uint16_t weight){
	nodes.at(node1).edges_to.push_back(node2);
	nodes.at(node1).edges_cost.push_back(weight);
	nodes.at(node2).edges_to.push_back(node1);
	nodes.at(node2).edges_cost.push_back(weight);
}
void Graph::connectNodes(int16_t from_x, int16_t from_y, MazeAngle from_angle,
						 int16_t to_x, int16_t to_y, MazeAngle to_angle,
						 const uint16_t weight){
	connectNodes(cnvCoordinateToNum(from_x, from_y, from_angle), cnvCoordinateToNum(to_x, to_y, to_angle), weight);
}


void Graph::disconnectNodes(const uint16_t node1, const uint16_t node2){
	//
}


uint16_t Graph::getCost(int16_t x, int16_t y, MazeAngle angle){
	uint16_t num = cnvCoordinateToNum(x, y, angle);
	return nodes.at(num).cost;
}


void Graph::connectWithMap(Map& map){
	connectNodes(0, 0, MazeAngle::SOUTH, 0, 0, MazeAngle::NORTH, WEIGHT_STRAIGHT);
	for (int i=0; i<31; ++i) {
		for (int j=0; j<31; ++j) {
			if (!map.isExistWall(i, j, MazeAngle::NORTH)) {
				if ((!map.isExistWall(i, j+1, MazeAngle::EAST )) && map.hasWatched(i, j+1, MazeAngle::EAST)) connectNodes(i, j+1, MazeAngle::SOUTH, i, j+1, MazeAngle::EAST, WEIGHT_DIAGO);
				if ((!map.isExistWall(i, j+1, MazeAngle::NORTH)) && map.hasWatched(i, j+1, MazeAngle::NORTH)) connectNodes(i, j+1, MazeAngle::SOUTH, i, j+1, MazeAngle::NORTH, WEIGHT_STRAIGHT);
				if ((!map.isExistWall(i, j+1, MazeAngle::WEST )) && map.hasWatched(i, j+1, MazeAngle::WEST)) connectNodes(i, j+1, MazeAngle::SOUTH, i, j+1, MazeAngle::WEST, WEIGHT_DIAGO);
				if ((!map.isExistWall(i, j,   MazeAngle::EAST )) && map.hasWatched(i, j  , MazeAngle::EAST)) connectNodes(i, j+1, MazeAngle::SOUTH, i, j, MazeAngle::EAST, WEIGHT_DIAGO);
				if ((!map.isExistWall(i, j,   MazeAngle::WEST )) && map.hasWatched(i, j  , MazeAngle::WEST)) connectNodes(i, j+1, MazeAngle::SOUTH, i, j, MazeAngle::WEST, WEIGHT_DIAGO);
			}
		}
	}
	for (int i=0; i<30; ++i) {
		for (int j=0; j<32; ++j) {
			if (!map.isExistWall(i, j, MazeAngle::EAST)) {
				if ((!map.isExistWall(i+1, j, MazeAngle::EAST)) && map.hasWatched(i+1, j, MazeAngle::EAST)) connectNodes(i, j, MazeAngle::EAST, i+1, j, MazeAngle::EAST, WEIGHT_STRAIGHT);
			}
		}
	}
}


vector<uint16_t> Graph::dijkstra(uint16_t start, uint16_t end){
	auto comparator = [](Node* left, Node* right){
		return left->cost < right->cost;
	};
	priority_queue<Node*, vector<Node*>, decltype(comparator) > q(comparator);

	nodes.at(start).cost = 0;
	q.push(&nodes.at(start));

	while (!q.empty()) {
		Node* node_done = q.top(); q.pop();
		if (node_done->done) continue;
		node_done->done = true;
		
		for (uint16_t i=0; i<node_done->edges_to.size(); ++i) {
			uint16_t to = node_done->edges_to.at(i);
			uint16_t cost = node_done->edges_cost.at(i) + node_done->cost;
			uint16_t from = node_done->num;
			if (cost < nodes.at(to).cost) {
				nodes.at(to).cost = cost;
				nodes.at(to).from = from;
				q.push(&nodes.at(to));
			}
		}
	}

	vector<uint16_t> ret;
	Node* node_ret;
	node_ret = &nodes.at(end);
	while(node_ret->cost != 0) {
		ret.push_back(node_ret->num);
		node_ret = &nodes.at(node_ret->from);
	}
	return ret;
}
