/*
 * @file Position.h
 */

#pragma once

#include <vector>

#include "SlalomParams.h"

enum class MazeAngle : uint8_t{
	NORTH,
	EAST,
	SOUTH,
	WEST,
};

enum class MouseAngle : uint8_t{
	FRONT,
	RIGHT,
	BACK,
	LEFT,
};

enum class MousePosition : uint8_t {
	NORTH,
	EAST,
	SOUTH,
	WEST,
	CENTER,
};

enum class MouseDirection : uint8_t {
	NORTH,
	NORTHEAST,
	EAST,
	SOUTHEAST,
	SOUTH,
	SOUTHWEST,
	WEST,
	NORTHWEST,
};

class MultiplePosition {
public:
	std::vector< std::pair<int16_t, int16_t> > curs;

	void clear();
	bool isInclude(std::pair<int16_t, int16_t> cur);
	void add(int16_t x, int16_t y);
	uint8_t size();

	MultiplePosition();
	MultiplePosition(std::vector< std::pair<int16_t, int16_t> >);
	~MultiplePosition();
};

class Position{
private:
	int16_t cur_x;
	int16_t cur_y;

	/// @todo 撤廃する
	MazeAngle cur_angle;

	MouseDirection cur_dir;

public:
	void setPosition(int8_t x, int8_t y);
	void setPosition(int8_t x, int8_t y, MazeAngle angle);
	void setAngle(MazeAngle angle);
	void setAngle(MouseDirection dir);

	void setNextPosition(slalomparams::RunType type);

	int16_t getPositionX();
	int16_t getPositionY();
	std::pair<int16_t, int16_t> getPosition();

	MazeAngle getAngle();

	// 斜め中ならtrue
	bool isDiago();

	static MazeAngle cnvMouseDirectionToMazeAngle(MouseDirection);
	static MouseDirection cnvMazeAngleToMouseDirection(MazeAngle);

	Position();
	~Position();
};

