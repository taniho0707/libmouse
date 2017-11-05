#include "Graph.h"

using namespace std;

Graph::Graph() :
	WEIGHT_STRAIGHT(90),
	WEIGHT_DIAGO(63)
{
	nodes = new std::vector<Node>;
	nodes->reserve(1984+2);
	for (int i=0; i<(1984+2); ++i) {
		nodes->push_back(Node(i));
	}
}
Graph::Graph(uint16_t num) :
	WEIGHT_STRAIGHT(90),
	WEIGHT_DIAGO(63)
{
	nodes = new std::vector<Node>;
	nodes->reserve(num);
	for (int i=0; i<num; ++i) {
		nodes->push_back(Node(i));
	}
}

Graph::~Graph(){
	delete nodes;
}


/// @todo 範囲外アクセスしないようにあれこれする
uint16_t Graph::cnvCoordinateToNum(int16_t x, int16_t y, MazeAngle angle){
	if (x == 0 && y == 0 && angle == MazeAngle::SOUTH) return 1984;
	if (x > 31 || x < 0 || y > 31 || y < 0
		|| (angle == MazeAngle::NORTH && y == 31)
		|| (angle == MazeAngle::EAST && x == 31)
		) {
		return 1985;
	}

	if (x == 31 && angle == MazeAngle::NORTH) {
		return (1953 + y);
	} else if (x == 31 && angle == MazeAngle::SOUTH) {
		return (1953 + y - 1);
	}

	uint16_t ret = 1985;
	if (angle == MazeAngle::SOUTH) return cnvCoordinateToNum(x, y-1, MazeAngle::NORTH);
	else if (angle == MazeAngle::WEST) return cnvCoordinateToNum(x-1, y, MazeAngle::EAST);
	else if (angle == MazeAngle::NORTH) ret = 63*x + y*2 + 1;
	else ret = 63*x + y*2;
	if (ret >= 1985) ret = 1985;
	return ret;
}

void Graph::cnvNumToCoordinate(uint16_t num, int16_t& x, int16_t& y, MazeAngle& angle){
	if (num == 1984) {
		x = 0; y = 0; angle = MazeAngle::SOUTH;
		return;
	} else if (num > 1984) {
		x = 0; y = 0; angle = MazeAngle::SOUTH; /// @todo この返り値でいいの？
		return;
	} else if (num >= 1953) {
		x = 31; y = num-1953; angle = MazeAngle::NORTH;
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

void Graph::cnvNumToPosition(uint16_t num, float& x, float& y) {
	/// @todo ハーフサイズにしか対応していない
	if (num == 1984) {
		x = 0.045f;
		y = 0.0f;
		return;
	}
	if (num >= 1985) {
		x = 10.0f;
		y = 10.0f;
		return;
	}

	int16_t coor_x, coor_y;
	MazeAngle coor_a;
	cnvNumToCoordinate(num, coor_x, coor_y, coor_a);
	if (coor_a == MazeAngle::NORTH) {
		x = 0.09 * coor_x + 0.045;
		y = 0.09 * (coor_y + 1);
	} else { // coor_a == MazeAngle::EAST
		x = 0.09 * (coor_x + 1);
		y = 0.09 * coor_y + 0.045;
	}
}


void Graph::connectNodes(const uint16_t node1, const uint16_t node2, const uint16_t weight){
	if (node1 >= 1985 || node2 >= 1985) return;
	nodes->at(node1).edges_to.push_back(node2);
	nodes->at(node1).edges_cost.push_back(weight);
	nodes->at(node2).edges_to.push_back(node1);
	nodes->at(node2).edges_cost.push_back(weight);
}
void Graph::connectNodes(int16_t from_x, int16_t from_y, MazeAngle from_angle,
						 int16_t to_x, int16_t to_y, MazeAngle to_angle,
						 const uint16_t weight){
	connectNodes(cnvCoordinateToNum(from_x, from_y, from_angle), cnvCoordinateToNum(to_x, to_y, to_angle), weight);
}


/// @todo 動作検証
void Graph::disconnectNodes(const uint16_t node1, const uint16_t node2){
	for (int i=0; i<nodes->at(node1).edges_to.size(); ++i) {
		if (nodes->at(node1).edges_to.at(i) == node2) {
			nodes->at(node1).edges_to.erase(nodes->at(node1).edges_to.begin()+i);
			nodes->at(node1).edges_cost.erase(nodes->at(node1).edges_cost.begin()+i);
		}
	}
	for (int i=0; i<nodes->at(node2).edges_to.size(); ++i) {
		if (nodes->at(node2).edges_to.at(i) == node1) {
			nodes->at(node2).edges_to.erase(nodes->at(node2).edges_to.begin()+i);
			nodes->at(node2).edges_cost.erase(nodes->at(node2).edges_cost.begin()+i);
		}
	}
}

void Graph::disconnectNodes(const uint16_t node1) {
	int node2 = 1985;
	for (int j=0; j<nodes->at(node1).edges_to.size(); ++j) {
		node2 = nodes->at(node1).edges_to.at(j);
		for (int i=0; i<nodes->at(node2).edges_to.size(); ++i) {
			if (nodes->at(node2).edges_to.at(i) == node1) {
				nodes->at(node2).edges_to.erase(nodes->at(node2).edges_to.begin()+i);
				nodes->at(node2).edges_cost.erase(nodes->at(node2).edges_cost.begin()+i);
			}
		}
	}
	nodes->at(node1).edges_to.clear();
	nodes->at(node1).edges_cost.clear();
}

void Graph::disconnectNodesFromWalldata(int16_t x, int16_t y, MazeAngle a, Walldata wall) {
	Walldata walldata = Walldata::rotateWallToAbsolute(wall, a);
	if (walldata.isExistWall(MouseAngle::FRONT)) disconnectNodes(cnvCoordinateToNum(x, y, MazeAngle::NORTH));
	if (walldata.isExistWall(MouseAngle::RIGHT)) disconnectNodes(cnvCoordinateToNum(x, y, MazeAngle::EAST));
	if (walldata.isExistWall(MouseAngle::BACK)) disconnectNodes(cnvCoordinateToNum(x, y, MazeAngle::SOUTH));
	if (walldata.isExistWall(MouseAngle::LEFT)) disconnectNodes(cnvCoordinateToNum(x, y, MazeAngle::WEST));
}


uint16_t Graph::getCost(int16_t x, int16_t y, MazeAngle angle){
	uint16_t num = cnvCoordinateToNum(x, y, angle);
	if (num >= 1985) return Node::MAX;
	return nodes->at(num).cost;
}


uint16_t Graph::getNextNodeStraight(uint16_t from, uint16_t current) {
	int16_t s_from = static_cast<int16_t>(from);
	int16_t s_current = static_cast<int16_t>(current);
	int16_t s_ret;
	int16_t dif = s_current - s_from;
	int16_t from_x, from_y, current_x, current_y;
	MazeAngle from_a, current_a;
	cnvNumToCoordinate(from, from_x, from_y, from_a);
	cnvNumToCoordinate(current, current_x, current_y, current_a);

	if (abs(dif) == 62) {
		dif = -1 * (dif/abs(dif));
	} else if(abs(dif) == 64) {
		dif = (dif/abs(dif));
	} else if(abs(dif) == 1) {
		if (from_x == current_x && from_y == current_y) {
			dif = -62 * (dif/abs(dif));
		} else {
			dif = 64 * (dif/abs(dif));
		}
	}
	if (from == 3 && current == 1) {
		s_ret = 1984;
	} else {
		s_ret = s_current + dif;
	}

	if (s_ret < 0 || s_ret > 1984) {
		s_ret = 1985;
	}
	return static_cast<uint16_t>(s_ret);
}


void Graph::connectWithMap(Map& map, bool enable_unwatched){
	saved_map = map;
	connectNodes(0, 0, MazeAngle::SOUTH, 0, 0, MazeAngle::NORTH, WEIGHT_STRAIGHT);
	for (int i=0; i<32; ++i) {
		for (int j=0; j<31; ++j) {
			if (!map.isExistWall(i, j, MazeAngle::NORTH)) {
				if ((!map.isExistWall(i, j+1, MazeAngle::EAST ))
					&& (enable_unwatched || map.hasWatched(i, j+1, MazeAngle::EAST))
					)
					connectNodes(i, j+1, MazeAngle::SOUTH, i, j+1, MazeAngle::EAST, WEIGHT_DIAGO);
				if ((!map.isExistWall(i, j+1, MazeAngle::NORTH))
					&& (enable_unwatched || map.hasWatched(i, j+1, MazeAngle::NORTH))
					)
					connectNodes(i, j+1, MazeAngle::SOUTH, i, j+1, MazeAngle::NORTH, WEIGHT_STRAIGHT);
				if ((!map.isExistWall(i, j+1, MazeAngle::WEST ))
					&& (enable_unwatched || map.hasWatched(i, j+1, MazeAngle::WEST))
					)
					connectNodes(i, j+1, MazeAngle::SOUTH, i, j+1, MazeAngle::WEST, WEIGHT_DIAGO);
				if ((!map.isExistWall(i, j,   MazeAngle::EAST ))
					&& (enable_unwatched || map.hasWatched(i, j  , MazeAngle::EAST))
					)
					connectNodes(i, j+1, MazeAngle::SOUTH, i, j, MazeAngle::EAST, WEIGHT_DIAGO);
				if ((!map.isExistWall(i, j,   MazeAngle::WEST ))
					&& (enable_unwatched || map.hasWatched(i, j  , MazeAngle::WEST))
					)
					connectNodes(i, j+1, MazeAngle::SOUTH, i, j, MazeAngle::WEST, WEIGHT_DIAGO);
			}
		}
	}
	for (int i=0; i<30; ++i) {
		for (int j=0; j<32; ++j) {
			if (!map.isExistWall(i, j, MazeAngle::EAST)) {
				if ((!map.isExistWall(i+1, j, MazeAngle::EAST))
					&& (enable_unwatched || map.hasWatched(i+1, j, MazeAngle::EAST))
					)
					connectNodes(i, j, MazeAngle::EAST, i+1, j, MazeAngle::EAST, WEIGHT_STRAIGHT);
			}
		}
	}
}


Footmap Graph::cnvGraphToFootmap(const vector<uint16_t>& graph){
	Path path;
	int16_t x = 0;
	int16_t y = 0;
	MazeAngle a = MazeAngle::EAST;
	Footmap fm;
	for (int i=graph.size()-1; i>=0; --i) {
		if (nodes->at(graph.at(i)).cost != 0){
			Graph::cnvNumToCoordinate(graph.at(i), x, y, a);
			if (a == MazeAngle::EAST) {
				fm.setFootmap(x, y, 0);
				fm.setFootmap(x+1, y, 0);
			} else { // NORTH
				fm.setFootmap(x, y, 0);
				fm.setFootmap(x, y+1, 0);
			}
		}
	}
	x=4; y=4;
	for (int i=0; i<1024; ++i) {
		/// @todo ゴール座標は4か9マス
		fm.setFootmap(x, y, i);
		if (x == 0 && y == 0) break;
		if (fm.getFootmap(x-1, y, 1024) == 0 && ((x-1) != 5 || y != 5)){
			x -= 1;
		} else if (fm.getFootmap(x+1, y, 1024) == 0 && ((x+1) != 5 || y != 5)){
			x += 1;
		} else if (fm.getFootmap(x, y-1, 1024) == 0 && (x != 5 || (y-1) != 5)){
			y -= 1;
		} else if (fm.getFootmap(x, y+1, 1024) == 0 && (x != 5 || (y+1) != 5)){
			y += 1;
		}
	}
	return fm;
}


vector<uint16_t> Graph::dijkstra(uint16_t start, uint16_t end){
	auto comparator = [](Node* left, Node* right){
		return left->cost > right->cost;
	};
	priority_queue<Node*, vector<Node*>, decltype(comparator) > q(comparator);

	nodes->at(start).cost = 0;
	q.push(&nodes->at(start));

	while (!q.empty()) {
		Node* node_done = q.top(); q.pop();
		if (node_done->done) continue;
		node_done->done = true;

		for (uint16_t i=0; i<node_done->edges_to.size(); ++i) {
			uint16_t to = node_done->edges_to.at(i);
			uint16_t cost = node_done->edges_cost.at(i) + node_done->cost;
			uint16_t from = node_done->num;
			int j=0;
			while (j++ < 30) {
				if (cost < nodes->at(to).cost) {
					nodes->at(to).cost = cost;
					nodes->at(to).from = from;
					q.push(&nodes->at(to));
				}

				if (!nodes->at(to).isConnected(getNextNodeStraight(from, nodes->at(to).num))) {
					break;
				} else {
					Node* node_next = &nodes->at(to);
					to = getNextNodeStraight(from, nodes->at(to).num);
					cost = node_done->edges_cost.at(i) + node_next->cost - 10; /// @todo 適当な値を減算しているけど適当すぎてポ！！！
					from = node_next->num;
				}
			}
		}
	}

	vector<uint16_t> ret;
	Node* node_ret;
	node_ret = &nodes->at(end);
	if (node_ret->cost != Node::MAX) {
		int i=0;
		while(node_ret->cost != 0 && i++ < 300) { /// @todo 300はてきとう
			ret.push_back(node_ret->num);
			node_ret = &nodes->at(node_ret->from);
		}
	}
	
	return ret;
}
