#include "SlalomParams.h"

using namespace std;
using namespace slalomparams;

array< map<float,pack_t>* , 16> slalomparams::getParams(){
	static map<float, pack_t> SLALOM90SML_RIGHT = {
	//  { vel, {d_bef, d_aft, a_rad, deg, cnsdeg, in_vel, out_vel, min_vel, acc_lin}},
		{0.10, {0.003,0.000,  3700,94.0,     40,   0.10,    0.10,    0.10,     0.0}},
		{0.25, {0.010,0.010,  6500,92.7,     30,   0.25,    0.25,    0.25,     0.0}},
		{ 0.3, {0.002,0.002, 10000,92.0,     30,    0.3,     0.3,     0.3,     0.0}},
	};
	
	static map<float, pack_t> SLALOM90SML_LEFT = {
	//  { vel, {d_bef, d_aft, a_rad, deg, cnsdeg, in_vel, out_vel, min_vel, acc_lin}},
		{0.10, {0.004,0.002,  3500,92.2,     40,   0.10,    0.10,    0.10,     0.0}},
		{0.25, {0.008,0.011,  6500,93.0,     30,   0.25,    0.25,    0.25,     0.0}},
		{ 0.3, {0.002,0.010, 10000,92.0,     30,    0.3,     0.3,     0.3,     0.0}},
	};
	
	static map<float, pack_t> SLALOM90_RIGHT = {
	//  { vel, {d_bef, d_aft, a_rad, deg, cnsdeg, in_vel, out_vel, min_vel, acc_lin}},
		{ 0.3, {0.022,0.024,   3000,91.0,     30,    0.3,     0.3,     0.3,     0.0}},
		{ 0.4, {0.020,0.016,   4000,  92,     30,    0.4,     0.4,     0.4,     0.0}},
		{ 0.55,{0.000,0.014,   6000,93.4,     30,   0.55,    0.55,    0.55,     0.0}},
	};
	
	static map<float, pack_t> SLALOM90_LEFT = {
	//  { vel, {d_bef, d_aft, a_rad, deg, cnsdeg, in_vel, out_vel, min_vel, acc_lin}},
		{ 0.3, {0.023,0.026,   3000,90.0,     30,    0.3,     0.3,     0.3,     0.0}},
		{ 0.4, {0.020,0.022,   4000,  92,     30,    0.4,     0.4,     0.4,     0.0}},
		{ 0.55,{0.000,0.014,   6000,92.0,     30,   0.55,    0.55,    0.55,     0.0}},
	};
	
	static map<float, pack_t> SLALOM180_RIGHT = {
	//  { vel, {d_bef, d_aft, a_rad, deg, cnsdeg, in_vel, out_vel, min_vel, acc_lin}},
		{ 0.3, {0.006,0.004,   1540, 182,     60,    0.3,     0.3,     0.3,     0.0}},
		{ 0.4, {0.005,0.005,   2700, 182,     60,    0.4,     0.4,     0.4,     0.0}},
		{ 0.55,{0.000,0.010,   3700, 182,     60,   0.55,    0.55,    0.55,     0.0}},
	};
	
	static map<float, pack_t> SLALOM180_LEFT = {
	//  { vel, {d_bef, d_aft, a_rad, deg, cnsdeg, in_vel, out_vel, min_vel, acc_lin}},
		{ 0.3, {0.005,0.004,   1500, 182,     60,    0.3,     0.3,     0.3,     0.0}},
		{ 0.4, {0.004,0.007,   2700, 182,     60,    0.4,     0.4,     0.4,     0.0}},
		{ 0.55,{0.000,0.030,   3700, 182,     60,   0.55,    0.55,    0.55,     0.0}},
	};
	
	static map<float, pack_t> SLALOM45IN_RIGHT = {
	//  { vel, {d_bef, d_aft, a_rad, deg, cnsdeg, in_vel, out_vel, min_vel, acc_lin}},
		{ 0.3, {0.013,0.000,   6000,46.0,     15,    0.3,     0.3,     0.3,     0.0}},
		{ 0.4, {0.000,0.000,   5000,46.0,     20,    0.4,     0.4,     0.4,     0.0}},
		{ 0.55,{0.000,0.000,  18000,47.0,     22,   0.55,    0.55,    0.55,     0.0}},
	};
	
	static map<float, pack_t> SLALOM45IN_LEFT = {
	//  { vel, {d_bef, d_aft, a_rad, deg, cnsdeg, in_vel, out_vel, min_vel, acc_lin}},
		{ 0.3, {0.017,0.000,   3000,47.0,     15,    0.3,     0.3,     0.3,     0.0}},
		{ 0.4, {0.000,0.000,   5000,47.0,     20,    0.4,     0.4,     0.4,     0.0}},
		{ 0.55,{0.000,0.000,  18000,47.0,     22,   0.55,    0.55,    0.55,     0.0}},
	};
	
	static map<float, pack_t> SLALOM45OUT_RIGHT = {
	//  { vel, {d_bef, d_aft, a_rad, deg, cnsdeg, in_vel, out_vel, min_vel, acc_lin}},
		{ 0.3, {0.015,0.015,   5000,47.0,     15,    0.3,     0.3,     0.3,     0.0}},
		{ 0.4, {0.002,0.010,   5000,46.0,     20,    0.4,     0.4,     0.4,     0.0}},
		{ 0.55,{0.000,0.000,  18000,47.0,     22,   0.55,    0.55,    0.55,     0.0}},
	};
	
	static map<float, pack_t> SLALOM45OUT_LEFT = {
	//  { vel, {d_bef, d_aft, a_rad, deg, cnsdeg, in_vel, out_vel, min_vel, acc_lin}},
		{ 0.3, {0.008,0.020,   3000,47.0,     15,    0.3,     0.3,     0.3,     0.0}},
		{ 0.4, {0.002,0.005,   5000,47.0,     20,    0.4,     0.4,     0.4,     0.0}},
		{ 0.55,{0.000,0.000,  18000,47.0,     22,   0.55,    0.55,    0.55,     0.0}},
	};
	
	static map<float, pack_t> SLALOM135IN_RIGHT = {
	//  { vel, {d_bef, d_aft, a_rad, deg, cnsdeg, in_vel, out_vel, min_vel, acc_lin}},
		{ 0.3, {0.030,0.000,   4000, 135,     45,    0.3,     0.3,     0.3,     0.0}},
		{ 0.4, {0.010,0.000,   4500, 137,     45,    0.4,     0.4,     0.4,     0.0}},
		{ 0.55,{0.015,0.000,  12000, 138,     45,   0.55,    0.55,    0.55,     0.0}},
	};
	
	static map<float, pack_t> SLALOM135IN_LEFT = {
	//  { vel, {d_bef, d_aft, a_rad, deg, cnsdeg, in_vel, out_vel, min_vel, acc_lin}},
		{ 0.3, {0.030,0.000,   3000, 137,     45,    0.3,     0.3,     0.3,     0.0}},
		{ 0.4, {0.010,0.000,   4500, 137,     45,    0.4,     0.4,     0.4,     0.0}},
		{ 0.55,{0.015,0.000,  12000, 138,     45,   0.55,    0.55,    0.55,     0.0}},
	};
	
	static map<float, pack_t> SLALOM135OUT_RIGHT = {
	//  { vel, {d_bef, d_aft, a_rad, deg, cnsdeg, in_vel, out_vel, min_vel, acc_lin}},
		{ 0.3, {0.020,0.070,   5000, 135,     45,    0.3,     0.3,     0.3,     0.0}},
		{ 0.4, {0.000,0.010,   5000, 137,     45,    0.4,     0.4,     0.4,     0.0}},
		{ 0.55,{0.000,0.015,  12000, 138,     45,   0.55,    0.55,    0.55,     0.0}},
	};
	
	static map<float, pack_t> SLALOM135OUT_LEFT = {
	//  { vel, {d_bef, d_aft, a_rad, deg, cnsdeg, in_vel, out_vel, min_vel, acc_lin}},
		{ 0.3, {0.015,0.045,   3000, 135,     45,    0.3,     0.3,     0.3,     0.0}},
		{ 0.4, {0.000,0.010,   5000, 137,     45,    0.4,     0.4,     0.4,     0.0}},
		{ 0.55,{0.000,0.015,  12000, 138,     45,   0.55,    0.55,    0.55,     0.0}},
	};
	
	static map<float, pack_t> SLALOM90OBL_RIGHT = {
	//  { vel, {d_bef, d_aft, a_rad, deg, cnsdeg, in_vel, out_vel, min_vel, acc_lin}},
		{ 0.3, {0.000, 0.000,  5000,  93,     30,    0.3,     0.3,     0.3,     0.0}},
		{ 0.4, {0.000, 0.000, 10000,  91,     45,    0.4,     0.4,     0.4,     0.0}},
		{ 0.55,{0.000, 0.000,  8000,94.5,     40,   0.55,    0.55,    0.55,     0.0}},
	};
	
	static map<float, pack_t> SLALOM90OBL_LEFT = {
	//  { vel, {d_bef, d_aft, a_rad, deg, cnsdeg, in_vel, out_vel, min_vel, acc_lin}},
		{ 0.3, {0.000, 0.000,  5000,  95,     30,    0.3,     0.3,     0.3,     0.0}},
		{ 0.4, {0.000, 0.000, 10000,  91,     45,    0.4,     0.4,     0.4,     0.0}},
		{ 0.55,{0.000, 0.000,  8000,94.5,     40,   0.55,    0.55,    0.55,     0.0}},
	};
	
	static array< map<float,pack_t>* , 16> params = {
		&SLALOM90SML_RIGHT,
		&SLALOM90SML_LEFT,
		&SLALOM90_RIGHT,
		&SLALOM90_LEFT,
		&SLALOM180_RIGHT,
		&SLALOM180_LEFT,
		&SLALOM45IN_RIGHT,
		&SLALOM45IN_LEFT,
		&SLALOM45OUT_RIGHT,
		&SLALOM45OUT_LEFT,
		&SLALOM135IN_RIGHT,
		&SLALOM135IN_LEFT,
		&SLALOM135OUT_RIGHT,
		&SLALOM135OUT_LEFT,
		&SLALOM90OBL_RIGHT,
		&SLALOM90OBL_LEFT,
	};

	return params;
}
