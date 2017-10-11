#pragma once

#include <array>
#include <map>

namespace slalomparams{
	enum class RunType : uint8_t {
		SLALOM90SML_RIGHT = 0,
		SLALOM90SML_LEFT,
		SLALOM90_RIGHT,
		SLALOM90_LEFT,
		SLALOM180_RIGHT,
		SLALOM180_LEFT,
		SLALOM45IN_RIGHT,
		SLALOM45IN_LEFT,
		SLALOM45OUT_RIGHT,
		SLALOM45OUT_LEFT,
		SLALOM135IN_RIGHT,
		SLALOM135IN_LEFT,
		SLALOM135OUT_RIGHT,
		SLALOM135OUT_LEFT,
		SLALOM90OBL_RIGHT,
		SLALOM90OBL_LEFT,
		TRAPACCEL,
		PIVOTTURN,
		TRAPDIAGO,
	};

	// angle: 前向きを支点に左回りが正方向
	struct typepack {
		float x;
		float y;
		float angle;
	};

	// ハーフサイズを基準にベクトルと回転角(degree)を記述
	const std::array<struct typepack, 19> param_vectors = {{
		//       {      x,     y,   angle }, // RunType
		/*  0 */ {  45.0f, 45.0f,  -90.0f }, // SLALOM90SML_RIGHT
		/*  1 */ { -45.0f, 45.0f,   90.0f }, // SLALOM90SML_LEFT
		/*  2 */ {  90.0f, 90.0f,  -90.0f }, // SLALOM90_RIGHT
		/*  3 */ { -90.0f, 90.0f,   90.0f }, // SLALOM90_LEFT
		/*  4 */ {  90.0f,  0.0f, -180.0f }, // SLALOM180_RIGHT
		/*  5 */ { -90.0f,  0.0f,  180.0f }, // SLALOM180_LEFT
		/*  6 */ {  45.0f, 90.0f,  -45.0f }, // SLALOM45IN_RIGHT
		/*  7 */ { -45.0f, 90.0f,   45.0f }, // SLALOM45IN_LEFT
		/*  8 */ {  31.819805153f,  95.459415460f, -45.0f }, // SLALOM45OUT_RIGHT
		/*  9 */ { -31.819805153f,  95.459415460f,  45.0f }, // SLALOM45OUT_LEFT
		/* 10 */ {  90.0f, 45.0f, -135.0f }, // SLALOM135IN_RIGHT
		/* 11 */ { -90.0f, 45.0f,  135.0f }, // SLALOM135IN_LEFT
		/* 12 */ {  95.459415460f, 31.819805153f, -135.0f }, // SLALOM135OUT_RIGHT
		/* 13 */ { -95.459415460f, 31.819805153f,  135.0f }, // SLALOM135OUT_LEFT
		/* 14 */ {  63.639610307f, 63.639610307f,  -90.0f }, // SLALOM90OBL_RIGHT
		/* 15 */ { -63.639610307f, 63.639610307f,   90.0f }, // SLALOM90OBL_LEFT
		/* 16 */ {   0.0f, 45.0f,    0.0f }, // TRAPACCEL
		/* 17 */ {   0.0f,  0.0f,  180.0f }, // PIVOTTURN
		/* 18 */ {   0.0f, 63.639610307f, 0.0f } // TRAPDIAGO
		}};

	struct pack {
		float d_before;
		float d_after;
		float acc_rad;
		float deg;
		float const_deg;
		float in_vel;
		float out_vel;
		float min_vel;
		float acc_lin;
	};
	typedef struct pack pack_t;

	using namespace std;

	array< map<float,pack_t>* , 16> getParams();

	/// @todo acc_downはまだ未対応
	struct paramset {
		float acc_up;
		float acc_down;
		array<float, 19> vels;
	};
	typedef struct paramset paramset_t;
}
