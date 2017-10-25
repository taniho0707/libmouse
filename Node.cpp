#include "Node.h"

Node::Node(uint16_t n){
	done = false;
	cost = MAX;
	from = MAX;
	num = n;
}

Node::~Node(){}

// std::vector<uint16_t> getConnectedNodes(){
	
// }

// bool Node::isConnected(uint16_t num){
	
// }

// uint16_t Node::getCost(uint16_t num){
	
// }

bool Node::operator< (const Node& input) const{
	if (cost < input.cost) return true;
	else return false;
}

bool Node::operator> (const Node& input) const{
	if (cost > input.cost) return true;
	else return false;
}

bool Node::operator< (const Node* input) const{
	if (cost < input->cost) return true;
	else return false;
}

bool Node::operator> (const Node* input) const{
	if (cost > input->cost) return true;
	else return false;
}

