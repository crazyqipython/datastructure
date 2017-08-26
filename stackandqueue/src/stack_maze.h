/*
 * stack_maze.h
 *
 *  Created on: 2017��7��10��
 *      Author: Dick
 */

#ifndef STACK_MAZE_H_
#define STACK_MAZE_H_

#define MaxSize 64



bool mgpath(int xi,int yi, int xe, int ye);

typedef struct{
	int i;
	int j;
	int di;
}Box;

typedef struct{
	Box data[MaxSize];
	int top;
}StType;



#endif /* STACK_MAZE_H_ */
