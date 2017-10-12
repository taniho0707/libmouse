#include "Graph.h"

using namespace std;

Graph::Graph(){
	nodes.reserve(1984+2);
	Node node;
	for (int i=0; i<(1984+2); ++i) {
		nodes.push_back(node);
	}
}
Graph::Graph(uint16_t num){
	nodes.reserve(num);
	Node node;
	for (int i=0; i<num; ++i) {
		nodes.push_back(node);
	}
}

Graph::~Graph(){}


/// @todo 範囲外アクセスしないようにあれこれする
uint16_t Graph::cnvCoordinateToNum(int16_t x, int16_t y, MazeAngle angle){
	if (x == 0 && y == 0 && angle == MazeAngle::SOUTH) return 1984;
	if (angle == MazeAngle::SOUTH) return cnvCoordinateToNum(x, y-1, MazeAngle::NORTH);
	else if (angle == MazeAngle::WEST) return cnvCoordinateToNum(x-1, y, MazeAngle::EAST);
	else if (angle == MazeAngle::NORTH) return 63*x + y*2 + 1;
	else return 63*x + y*2;
}

void Graph::cnvNumToCoordinate(uint16_t num, int16_t& x, int16_t& y, MazeAngle& angle){
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
		
		for (uint16_t i=0; i<node_done->edges_to.size()-1; ++i) {
			uint16_t to = node_done->edges_to.at(i);
			uint16_t cost = node_done->edges_cost.at(i);
			if (nodes.at(to).cost == Node::MAX || cost < nodes.at(to).cost) {
				nodes.at(to).cost = cost;
				q.push(&nodes.at(to));
			}
		}
	}
}
