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
#include "Walldata.h"

#include "Footmap.h"
#include "Path.h"

class Graph{
private:
	const uint16_t WEIGHT_STRAIGHT;
	const uint16_t WEIGHT_DIAGO;

	Map saved_map;
	
public:
	std::vector<Node>* nodes;

	Graph();
	Graph(uint16_t num);
	~Graph();

	static uint16_t cnvCoordinateToNum(int16_t x, int16_t y, MazeAngle angle);
	static void cnvNumToCoordinate(uint16_t num, int16_t& x, int16_t& y, MazeAngle& angle);

	uint16_t getNextNodeStraight(uint16_t from, uint16_t current);

	void connectWithMap(Map& map, bool enable_unwatched = false);

	void connectNodes(uint16_t node1, uint16_t node2, uint16_t weight);
	void connectNodes(int16_t from_x, int16_t from_y, MazeAngle from_angle,
					  int16_t to_x, int16_t to_y, MazeAngle to_angle,
					  uint16_t weight);

	void disconnectNodes(uint16_t node1, uint16_t node2);
	void disconnectNodes(uint16_t node1);
	void disconnectNodesFromWalldata(int16_t x, int16_t y, MazeAngle a, Walldata wall);

	uint16_t getCost(int16_t x, int16_t y, MazeAngle angle);

	Footmap cnvGraphToFootmap(const std::vector<uint16_t>&);

	// Algorithms
	std::vector<uint16_t> dijkstra(uint16_t start, uint16_t end);
};
