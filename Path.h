/*
 * @file Path.h
 */
#pragma once

#include <vector>

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
	std::vector<MouseAngle> angles;

	Motion goalmotion;

	PathType pathtype;

public:
	Path(PathType);
	Path();

	void format();

	int16_t getPathLength();

	Motion getMotion(int16_t num);
	void putMotion(Motion motion);
	std::pair<float, float> getPosition(int16_t num);
	void putPosition(std::pair<float, float> position);
	MouseAngle getAngle(int16_t num);
	void putAngle(MouseAngle angle);

	inline bool operator==(const Path& p) const {
		return path == p.path;
	}
	inline bool operator!=(const Path& p) const {
		return path != p.path;
	}
};

