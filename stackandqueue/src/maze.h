/*
 * maze.h
 *
 *  Created on: 2017Äê7ÔÂ8ÈÕ
 *      Author: Dick
 */

#ifndef MAZE_H_
#define MAZE_H_
#include <time.h>
#include "sq_stack.h"

#define N 15
#define X 4
#define SleepTime 2

typedef enum
{
	Wall,
	Obstacle,
	Way,
	DeadLock,
	East, South,West,North
}MazeNode;

typedef struct {
	int x;
	int y;
}PosType;

typedef struct{
	int ord;
	PosType seat;
	int di;
}SElemType;

typedef int MazeType;

Status MazePath(MazeType maze[][N], PosType start, PosType end);

void InitMaze(MazeType maze[][N], PosType *start, PosType *end);

Status EqualPosType(PosType a, PosType b);

void PaintMaze(MazeType maze[][N]);

void ShowMaze(MazeType maze[][N]);

Status Pass(PosType seat, MazeType[][N]);

void FootPrint(PosType seat, MazeType[][N]);

void SetSElemType(SElemType_Sq *e, int ord, PosType seat, int di);

PosType NextPos(PosType seat, int di);

Status IsCross(PosType seat);

void MakePrint(PosType seat, MazeType maze[][N]);




#endif /* MAZE_H_ */
