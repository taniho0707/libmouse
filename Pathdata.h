/**
 * @file Pathdata.h
 * @brief パスを管理するクラス
 */
#ifndef INCLUDED_PATHDATA_H
#define INCLUDED_PATHDATA_H

#include "const.h"
#include "Graph.h"

class Pathdata{
private:

	unsigned int currentPos;

public:

	Pathdata();

//	MouseMotion data[128];
	unsigned char data[256];
	unsigned char division[256];


	MouseMotion getNext();

	/// @todo パスを綺麗に生成する
	void setNext(EMotion next);

	void resetPos();

	~Pathdata();
};

#endif

