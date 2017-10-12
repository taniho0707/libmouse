/**
 * @file Node.h
 */

#pragma once

#include <vector>
#include <cstdint>

class Node{
private:

public:
	static const uint16_t MAX = 65535;

	std::vector<uint16_t> edges_to;
	std::vector<uint16_t> edges_cost;

	// for Dijkstra
	bool done; // 確定ノードか否か
	uint16_t cost; // このノードへの現時点で判明している最小コスト
	uint16_t from; // このノードへ接続したノード番号

	Node();
	
	/* std::vector<uint16_t> getConnectedNodes(); */
	/* bool isConnected(uint16_t num); */
	/* uint16_t getCost(uint16_t num); */

	bool operator< (const Node& input) const;
	bool operator> (const Node& input) const;
	bool operator< (const Node* input) const;
	bool operator> (const Node* input) const;
	
	~Node();
};
