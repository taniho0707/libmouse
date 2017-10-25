/*
 * @file Map.h
 */
#pragma once

#include "SlalomParams.h"
#include "Walldata.h"
#include "Position.h"

enum class ClassType : uint8_t {
	CLASSIC,
	HALF,
	QUARTER,
};

class Map{
private:
	/**
	 * @brief 迷路の競技を指定
	 */
	ClassType type;

	bool enabled_autoinsert;
	
public:
	Map();

	/**
	 * @brief 一番左の壁がMSB，右から2番目の壁がLSB，下から順
	 */
	uint32_t column[31];
	/**
	 * @brief 一番左の壁がMSB，右から2番目の壁がLSB，下から順
	 */
	uint32_t row[31];
	/**
	 * @brief 一番左のマスがMSB，一番右のマスがLSB，下から順
	 */
	uint32_t reached[32];

	/**
	 * @brief ゴール座標を指定
	 */
	MultiplePosition goals;


	void format();
	/**
	 * @brief 迷路データを初期化する
	 */
	void formatWall();
	/**
	 * @brief 到達マップを初期化する
	 */
	void formatReached();

	void setType(ClassType newtype);
	ClassType getType();

	void addGoal(int16_t x, int16_t y);


	/**
	 * @brief 壁を追加します
	 * @param x 壁を追加する区画のx座標
	 * @param y 壁を追加する区画のy座標
	 * @param angle 今自分が向いている絶対方向
	 * @param wall 今見えている壁情報
	 */
	void addWall(int8_t x, int8_t y, MazeAngle angle, Walldata wall);

	/**
	 * @brief 壁を設定します
	 * @param x 壁を追加する区画のx座標
	 * @param y 壁を追加する区画のy座標
	 * @param angle 今自分が向いている絶対方向
	 * @param wall 今見えている壁情報
	 */
	void setWall(int8_t x, int8_t y, MazeAngle angle, Walldata wall);

	/**
	 * @brief 壁を追加します。絶対方向でのみ指定が可能です。
	 * @param x 壁を追加する区画のx座標
	 * @param y 壁を追加する区画のy座標
	 * @param angle 今自分が向いている絶対方向
	 */
	void addSingleWall(int8_t x, int8_t y, MazeAngle angle);

	/**
	 * @brief 壁を設定します。絶対方向でのみ指定が可能です。
	 * @param x 壁を追加する区画のx座標
	 * @param y 壁を追加する区画のy座標
	 * @param angle 今自分が向いている絶対方向
	 * @param wall 今見えている壁情報
	 * @bug まだaddSingleWallと同じ関数
	 */
	void setSingleWall(int8_t x, int8_t y, MazeAngle angle, bool wall);

	Walldata getWalldata(int8_t x, int8_t y);
	Walldata getKnownWalldata(int8_t x, int8_t y);


	/**
	 * @brief 絶対方向から見て壁があるか確認します
	 * @param x 壁を追加する区画のx座標
	 * @param y 壁を追加する区画のy座標
	 * @param angle 今自分が見ている絶対方向
	 * @return 壁が存在したらtrue
	 */
	bool isExistWall(int8_t x, int8_t y, MazeAngle angle);
	
	/**
	 * @brief マウスから見て壁があるか確認します
	 * @param x マウスのx座標
	 * @param y マウスのy座標
	 * @param angle マウスの方角
	 * @param mousex マウスからのx座標
	 * @param mousey マウスからのy座標
	 * @param mouseangle マウスから見た壁の方角
	 * @return 壁が存在したらtrue
	 */
	bool isExistWallFromMouse(int8_t x, int8_t y, MazeAngle angle,
							  int8_t mousex, int8_t mousey, MazeAngle mouseangle);


	/**
	 * @brief 到達マップを設定します
	 * @param x 到達設定する区画のx座標
	 * @param y 到達設定する区画のy座標
	 */
	void setReached(int8_t, int8_t);

	/**
	 * @brief 到達したか確認します
	 * @param x 到達確認する区画のx座標
	 * @param y 到達確認する区画のy座標
	 * @return 到達していたら1，していなかったら0を返します
	 */
	bool hasReached(int8_t, int8_t);

	bool hasWatched(int8_t, int8_t, MazeAngle);

	void enableAutoInsert();
	void disableAutoInsert();

	void copyFrom(const Map&);


	/**
	 * @brief =演算子のオーバーロード。Mapクラスを代入します
	 * @bug できない
	 */
	/* Map& operator= (Map tmp){ */
	/* 	for(int i=0; i<31; i++){ */
	/* 		column[i] = tmp.column[i]; */
	/* 		row[i] = tmp.row[i]; */
	/* 	} */
	/* 	for(int i=0; i<32; i++){ */
	/* 		reached[i] = tmp.reached[i]; */
	/* 	} */
	/* 	return *this; */
	/* } */
};
