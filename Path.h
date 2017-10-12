/*
 * @file Path.h
 */
#pragma once

#include <vector>
#include <cmath>

#include "Position.h"
#include "SlalomParams.h"

struct Motion{
	slalomparams::RunType type;
	uint16_t length;

	bool isDiagoType(){
		if(type == slalomparams::RunType::SLALOM45IN_RIGHT ||
		   type == slalomparams::RunType::SLALOM45IN_LEFT ||
		   type == slalomparams::RunType::SLALOM135IN_RIGHT ||
		   type == slalomparams::RunType::SLALOM135IN_LEFT ||
		   type == slalomparams::RunType::SLALOM90OBL_RIGHT ||
		   type == slalomparams::RunType::SLALOM90OBL_LEFT ||
		   type == slalomparams::RunType::TRAPDIAGO)
			return true;
		else return false;
	}

	inline bool operator==(const Motion& m) const {
		return (type == m.type && length == m.length);
	}
	inline bool operator!=(const Motion& m) const {
		return (type != m.type && length != m.length);
	}
};

enum class PathType : uint8_t {
	SMALL,
	BIG,
	DIAGO,
};

class Path{
private:
	std::vector<Motion> path;
	std::vector< std::pair<float, float> > positions;
	std::vector<float> angles;

	Motion goalmotion;

	PathType pathtype;

public:
	Path(PathType);
	Path();

	/// @todo 分離したい
	float rad(float p);

	void format();

	int16_t getPathLength();

	Motion getMotion(int16_t num);
	void putMotion(Motion motion);
	std::pair<float, float> getPosition(int16_t num);

	/// @todo 斜めの前後の座標は信用できない
	std::pair<int8_t, int8_t> getPositionCoordinate(int16_t num);
	MousePosition getPositionCoordinateSide(int16_t num);
	MouseDirection getAngleCoordinate(int16_t num);

	void putPosition(std::pair<float, float> position);
	float getAngle(int16_t num);
	void putAngle(float angle);

	void updatePositions();

	/// @todo 速度パラメータが違うと計算できないバグ
	uint32_t getFullTime();

	inline bool operator==(const Path& p) const {
		return path == p.path;
	}
	inline bool operator!=(const Path& p) const {
		return path != p.path;
	}
};

