/**
 * @file Node.h
 */

#pragma once

#include <array>
#include <cstdint>

class Node{
private:

public:
	static const uint16_t MAX = 65535;

	std::array<uint16_t, 6> edges_to;
	std::array<uint16_t, 6> edges_cost;

	// for Dijkstra
	/* bool done; // 確定ノードか否か */
	/* uint16_t cost; // このノードへの現時点で判明している最小コスト */
	uint16_t from; // このノードへ接続したノード番号
	uint16_t num; // このノードの番号

	Node(uint16_t n);
	
	/* std::vector<uint16_t> getConnectedNodes(); */
	bool isConnected(uint16_t num);
	/* uint16_t getCost(uint16_t num); */

	void pushCost(uint16_t);
	void pushTo(uint16_t);
	
	~Node();
};
