/**
 * @file Position.cpp
 */

#include "Position.h"

using namespace std;
using namespace slalomparams;


MultiplePosition::MultiplePosition(std::vector< std::pair<int16_t, int16_t> > cur){
	curs = cur;
}
MultiplePosition::MultiplePosition(){
	
}
MultiplePosition::~MultiplePosition(){
	
}

void MultiplePosition::clear(){
	vector< pair<int16_t, int16_t> >().swap(curs);
}

void MultiplePosition::add(int16_t x, int16_t y){
	pair<int16_t, int16_t> tmp(x, y);
	curs.push_back(tmp);
}

uint8_t MultiplePosition::size(){
	return curs.size();
}

bool MultiplePosition::isInclude(pair<int16_t, int16_t> cur){
	for (auto ite : curs) {
		if (ite.first == cur.first && ite.second == cur.second)
			return true;
	}
	return false;
}


Position::Position(){
	cur_x = 0;
	cur_y = 1;

	cur_angle = MazeAngle::NORTH;
}

Position::~Position(){
	
}

void Position::setPosition(int8_t x, int8_t y){
	cur_x = x;
	cur_y = y;
}
void Position::setAngle(MazeAngle angle){
	cur_angle = angle;
}
void Position::setPosition(int8_t x, int8_t y, MazeAngle angle){
	setPosition(x, y);
	setAngle(angle);
}

void Position::setNextPosition(slalomparams::RunType type){
	switch(type){
	case RunType::SLALOM90SML_RIGHT:
		if(cur_angle == MazeAngle::NORTH){
			++ cur_x;
			cur_angle = MazeAngle::EAST;
		} else if(cur_angle == MazeAngle::EAST){
			-- cur_y;
			cur_angle = MazeAngle::SOUTH;
		} else if(cur_angle == MazeAngle::SOUTH){
			-- cur_x;
			cur_angle = MazeAngle::WEST;
		} else if(cur_angle == MazeAngle::WEST){
			++ cur_y;
			cur_angle = MazeAngle::NORTH;
		}
		break;
	case RunType::SLALOM90SML_LEFT:
		if(cur_angle == MazeAngle::NORTH){
			-- cur_x;
			cur_angle = MazeAngle::WEST;
		} else if(cur_angle == MazeAngle::EAST){
			++ cur_y;
			cur_angle = MazeAngle::NORTH;
		} else if(cur_angle == MazeAngle::SOUTH){
			++ cur_x;
			cur_angle = MazeAngle::EAST;
		} else if(cur_angle == MazeAngle::WEST){
			-- cur_y;
			cur_angle = MazeAngle::SOUTH;
		}
		break;
	case RunType::TRAPACCEL:
		if(cur_angle == MazeAngle::NORTH){
			++ cur_y;
		} else if(cur_angle == MazeAngle::EAST){
			++ cur_x;
		} else if(cur_angle == MazeAngle::SOUTH){
			-- cur_y;
		} else if(cur_angle == MazeAngle::WEST){
			-- cur_x;
		}
		break;
	case RunType::PIVOTTURN:
		if(cur_angle == MazeAngle::NORTH){
			-- cur_y;
			cur_angle = MazeAngle::SOUTH;
		} else if(cur_angle == MazeAngle::EAST){
			-- cur_x;
			cur_angle = MazeAngle::WEST;
		} else if(cur_angle == MazeAngle::SOUTH){
			++ cur_y;
			cur_angle = MazeAngle::NORTH;
		} else if(cur_angle == MazeAngle::WEST){
			++ cur_x;
			cur_angle = MazeAngle::EAST;
		}
		break;
	}
}

int16_t Position::getPositionX(){
	return cur_x;
}
int16_t Position::getPositionY(){
	return cur_y;
}
std::pair<int16_t, int16_t> Position::getPosition(){
	return std::pair<int16_t, int16_t>(cur_x, cur_y);
}

MazeAngle Position::getAngle(){
	return cur_angle;
}

