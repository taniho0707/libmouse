/**
 * @file Graph.h
 * @brief 迷路データを構成するノードの集合体
 *        迷路とノード番号の管理も担う
 */

#pragma once

#include <utility>
#include <vector>

#include "Node.h"
#include "Map.h"

class Graph{
private:
	std::vector<Node> nodes;
	

public:
	Graph();
	~Graph();

	int connectNodes(const int coor1, const int coor2);
	int disconnectNodes(const int coor1, const int coor2);
};
