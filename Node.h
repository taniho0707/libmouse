/**
 * @file Node.h
 */

#pragma once

#include <vector>
#include <cstdint>

class Node{
private:
	static const uint16_t MAX = 65535;
	
	uint16_t num;
	std::vector<Node *> edges_to;
	std::vector<uint16_t> edges_cost;

	bool done; // 確定ノードか否か
	uint16_t cost; // このノードへの現時点で判明している最小コスト

public:
	Node(uint16_t n);
	
	std::vector<Node *> getConnectedNodes();
	bool isConnectedNode(Node&);
	uint16_t getCost(Node *);
	uint16_t getNumber();
	
	~Node();
};
