#include "Node.h"

Node::Node(uint16_t n){
	from = MAX;
	num = n;
}

Node::~Node(){}

// std::vector<uint16_t> getConnectedNodes(){
	
// }

bool Node::isConnected(uint16_t num){
	for (int i=0; i<edges_to.size(); ++i) {
		if (edges_to.at(i) == num) {
			return true;
		}
	}
	return false;
}

// uint16_t Node::getCost(uint16_t num){
	
// }

void Node::pushCost(uint16_t num) {
	for (int i=0; i<6; ++i) {
		if (edges_cost.at(i) == MAX) {
			edges_cost.at(i) = num;
			return;
		}
	}
}

void Node::pushTo(uint16_t num) {
	for (int i=0; i<6; ++i) {
		if (edges_to.at(i) == MAX) {
			edges_to.at(i) = num;
			return;
		}
	}
}

