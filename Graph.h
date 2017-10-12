/**
 * @file Graph.h
 * @brief 迷路データを構成するノードの集合体
 *        迷路とノード番号の管理も担う
 */

#pragma once

#include <utility>
#include <vector>
#include <queue>

#include "Node.h"
#include "Map.h"
#include "Position.h"

class Graph{
private:
	uint16_t cnvCoordinateToNum(int16_t x, int16_t y, MazeAngle angle);
	void cnvNumToCoordinate(uint16_t num, int16_t& x, int16_t& y, MazeAngle& angle);

public:
	std::vector<Node> nodes;

	Graph();
	Graph(uint16_t num);
	~Graph();

	void connectNodes(uint16_t node1, uint16_t node2, uint16_t weight);
	void connectNodes(int16_t from_x, int16_t from_y, MazeAngle from_angle,
					  int16_t to_x, int16_t to_y, MazeAngle to_angle,
					  uint16_t weight);

	void disconnectNodes(uint16_t node1, uint16_t node2);

	uint16_t getCost(int16_t x, int16_t y, MazeAngle angle);

	// Algorithms
	std::vector<uint16_t> dijkstra(uint16_t start, uint16_t end);
};
