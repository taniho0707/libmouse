#include "SlalomParams.h"

using namespace std;
using namespace slalomparams;

array< map<float,pack_t>* , 16> slalomparams::getParams(){
	static map<float, pack_t> SLALOM90SML_RIGHT = {
	//  { vel, {d_bef, d_aft, a_rad, deg, cnsdeg, in_vel, out_vel, min_vel, acc_lin}},
		{0.10, {0.003,0.000,  3700,94.0,     40,   0.10,    0.10,    0.10,     0.0}},
		{0.25, {0.007,0.009,  6500,91.2,     30,   0.25,    0.25,    0.25,     0.0}},
		{ 0.3, {0.002,0.002, 10000,92.0,     30,    0.3,     0.3,     0.3,     0.0}},
	};
	
	static map<float, pack_t> SLALOM90SML_LEFT = {
	//  { vel, {d_bef, d_aft, a_rad, deg, cnsdeg, in_vel, out_vel, min_vel, acc_lin}},
		{0.10, {0.004,0.002,  3500,92.2,     40,   0.10,    0.10,    0.10,     0.0}},
		{0.25, {0.007,0.010,  6500,92.2,     30,   0.25,    0.25,    0.25,     0.0}},
		{ 0.3, {0.002,0.010, 10000,92.0,     30,    0.3,     0.3,     0.3,     0.0}},
	};
	
	static map<float, pack_t> SLALOM90_RIGHT = {
	//  { vel, {d_bef, d_aft, a_rad, deg, cnsdeg, in_vel, out_vel, min_vel, acc_lin}},
		{ 0.3, {0.022,0.024,   3000,91.0,     30,    0.3,     0.3,     0.3,     0.0}},
		{ 0.5, {0.020,0.020,   8000,93.4,     30,    0.5,     0.5,     0.5,     0.0}},
		{ 0.7, {0.000,0.022,  13000,93.4,     30,    0.7,     0.7,     0.7,     0.0}},
	};
	
	static map<float, pack_t> SLALOM90_LEFT = {
	//  { vel, {d_bef, d_aft, a_rad, deg, cnsdeg, in_vel, out_vel, min_vel, acc_lin}},
		{ 0.3, {0.020,0.024,   3000,90.0,     30,    0.3,     0.3,     0.3,     0.0}},
		{ 0.5, {0.024,0.020,   8000,93.4,     30,    0.5,     0.5,     0.5,     0.0}},
		{ 0.7, {0.000,0.022,  13000,93.4,     30,    0.7,     0.7,     0.7,     0.0}},
	};
	
	static map<float, pack_t> SLALOM180_RIGHT = {
	//  { vel, {d_bef, d_aft, a_rad, deg, cnsdeg, in_vel, out_vel, min_vel, acc_lin}},
		{ 0.3, {0.006,0.004,   1540, 182,     60,    0.3,     0.3,     0.3,     0.0}},
		{ 0.5, {0.000,0.000,   4400, 181,     60,    0.5,     0.5,     0.5,     0.0}},
		{ 0.7, {0.000,0.022,   8100, 182,     60,    0.7,     0.7,     0.7,     0.0}},
	};
	
	static map<float, pack_t> SLALOM180_LEFT = {
	//  { vel, {d_bef, d_aft, a_rad, deg, cnsdeg, in_vel, out_vel, min_vel, acc_lin}},
		{ 0.3, {0.005,0.004,   1540, 182,     60,    0.3,     0.3,     0.3,     0.0}},
		{ 0.5, {0.000,0.000,   4400, 182,     60,    0.5,     0.5,     0.5,     0.0}},
		{ 0.7, {0.000,0.022,   8100, 182,     60,    0.7,     0.7,     0.7,     0.0}},
	};
	
	static map<float, pack_t> SLALOM45IN_RIGHT = {
	//  { vel, {d_bef, d_aft, a_rad, deg, cnsdeg, in_vel, out_vel, min_vel, acc_lin}},
		{ 0.3, {0.013,0.00,   6000,46.0,     15,    0.3,     0.3,     0.3,     0.0}},
		{ 0.5, {0.002,0.000,   8000,47.0,     15,    0.5,     0.5,     0.5,     0.0}},
		{ 0.7, {0.002,0.000,  20000,47.5,     23,    0.7,     0.7,     0.7,     0.0}},
	};
	
	static map<float, pack_t> SLALOM45IN_LEFT = {
	//  { vel, {d_bef, d_aft, a_rad, deg, cnsdeg, in_vel, out_vel, min_vel, acc_lin}},
		{ 0.3, {0.017,0.000,   6000,47.0,     15,    0.3,     0.3,     0.3,     0.0}},
		{ 0.5, {0.012,0.000,   8500,47.0,     15,    0.5,     0.5,     0.5,     0.0}},
		{ 0.7, {0.002,0.000,  17000,47.0,     20,    0.7,     0.7,     0.7,     0.0}},
	};
	
	static map<float, pack_t> SLALOM45OUT_RIGHT = {
	//  { vel, {d_bef, d_aft, a_rad, deg, cnsdeg, in_vel, out_vel, min_vel, acc_lin}},
		{ 0.3, {0.018,0.015,   5000,47.0,     15,    0.3,     0.3,     0.3,     0.0}},
		{ 0.5, {0.020,0.000,   8000,46.5,     15,    0.5,     0.5,     0.5,     0.0}},
		{ 0.7, {0.015,0.000,  17000,47.0,     20,    0.7,     0.7,     0.7,     0.0}},
	};
	
	static map<float, pack_t> SLALOM45OUT_LEFT = {
	//  { vel, {d_bef, d_aft, a_rad, deg, cnsdeg, in_vel, out_vel, min_vel, acc_lin}},
		{ 0.3, {0.012,0.020,   5000,47.0,     15,    0.3,     0.3,     0.3,     0.0}},
		{ 0.5, {0.020,0.000,   8000,46.5,     15,    0.5,     0.5,     0.5,     0.0}},
		{ 0.7, {0.010,0.000,  17000,47.0,     20,    0.7,     0.7,     0.7,     0.0}},
	};
	
	static map<float, pack_t> SLALOM135IN_RIGHT = {
	//  { vel, {d_bef, d_aft, a_rad, deg, cnsdeg, in_vel, out_vel, min_vel, acc_lin}},
		{ 0.3, {0.030,0.000,   4000, 135,     45,    0.3,     0.3,     0.3,     0.0}},
		{ 0.5, {0.025,0.000,  11500, 138,     45,    0.5,     0.5,     0.5,     0.0}},
		{ 0.7, {0.002,0.000,  15500, 137,     65,    0.7,     0.7,     0.7,     0.0}},
	};
	
	static map<float, pack_t> SLALOM135IN_LEFT = {
	//  { vel, {d_bef, d_aft, a_rad, deg, cnsdeg, in_vel, out_vel, min_vel, acc_lin}},
		{ 0.3, {0.008,0.000,   4000, 136,     45,    0.3,     0.3,     0.3,     0.0}},
		{ 0.5, {0.025,0.000,  11500, 137,     45,    0.5,     0.5,     0.5,     0.0}},
		{ 0.7, {0.008,0.000,  15000, 137,     65,    0.7,     0.7,     0.7,     0.0}},
	};
	
	static map<float, pack_t> SLALOM135OUT_RIGHT = {
	//  { vel, {d_bef, d_aft, a_rad, deg, cnsdeg, in_vel, out_vel, min_vel, acc_lin}},
		{ 0.3, {0.039,0.040,   5000, 136,     45,    0.3,     0.3,     0.3,     0.0}},
		{ 0.5, {0.030,0.030,  11500, 140,     45,    0.5,     0.5,     0.5,     0.0}},
		{ 0.7, {0.001,0.000,  18000, 136,     67,    0.7,     0.7,     0.7,     0.0}},
	};
	
	static map<float, pack_t> SLALOM135OUT_LEFT = {
	//  { vel, {d_bef, d_aft, a_rad, deg, cnsdeg, in_vel, out_vel, min_vel, acc_lin}},
		{ 0.3, {0.030,0.017,   5000, 137,     45,    0.3,     0.3,     0.3,     0.0}},
		{ 0.5, {0.025,0.030,  11500, 137,     45,    0.5,     0.5,     0.5,     0.0}},
		{ 0.7, {0.001,0.000,  18000, 136,     67,    0.7,     0.7,     0.7,     0.0}},
	};
	
	static map<float, pack_t> SLALOM90OBL_RIGHT = {
	//  { vel, {d_bef, d_aft, a_rad, deg, cnsdeg, in_vel, out_vel, min_vel, acc_lin}},
		{ 0.3, {0.000, 0.000,  4000,  93,     30,    0.3,     0.3,     0.3,     0.0}},
		{ 0.5, {0.015, 0.000, 16000,94.4,     30,    0.5,     0.5,     0.5,     0.0}},
		{ 0.7, {0.002, 0.010, 25000,93.8,     45,    0.7,     0.7,     0.7,     0.0}},
	};
	
	static map<float, pack_t> SLALOM90OBL_LEFT = {
	//  { vel, {d_bef, d_aft, a_rad, deg, cnsdeg, in_vel, out_vel, min_vel, acc_lin}},
		{ 0.3, {0.000, 0.000,  4000,  95,     30,    0.3,     0.3,     0.3,     0.0}},
		{ 0.5, {0.015, 0.000, 16000,94.4,     30,    0.5,     0.5,     0.5,     0.0}},
		{ 0.7, {0.002, 0.010, 26000,94.4,     45,    0.7,     0.7,     0.7,     0.0}},
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
