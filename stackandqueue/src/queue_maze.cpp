#include <stdio.h>
#include <stdlib.h>
#include "queue_maze.h"



void print(QuType q, int front){
	while(front !=-1){
		printf("(%d,%d) ", q.data[front].i, q.data[front].j);
		front = q.data[front].pre;
	}
}

bool mgpath1(int xi, int yi, int xe, int ye){
	int i,j,find=0,di;
	QuType qu;
	qu.front = qu.rear = -1;
	qu.rear++;
	qu.data[qu.rear].i = xi;
	qu.data[qu.rear].j = yi;
	qu.data[qu.rear].pre = -1;
	mg[xi][yi] = -1;

	while(qu.front !=qu.rear&&!find){
		qu.front++;
		i = qu.data[qu.front].i;
		j = qu.data[qu.front].j;
		if(i==xe && j == ye){
			find =1;
			print(qu,qu.front);
			return true;
		}
		for(di=0;di<4;di++){
			switch(di){
				case 0:
					i = qu.data[qu.front].i -1;
					j = qu.data[qu.front].j;
					break;
				case 1:
					i = qu.data[qu.front].i;
					j = qu.data[qu.front].j+1;
					break;
				case 2:
					i = qu.data[qu.front].i+1;
					j = qu.data[qu.front].j;
					break;
				case 3:
					i = qu.data[qu.front].i;
					j = qu.data[qu.front].j-1;
			}
			if(mg[i][j]==0){
				qu.rear++;
				qu.data[qu.rear].i = i;
				qu.data[qu.rear].j = j;
				qu.data[qu.rear].pre = qu.front;
				mg[i][j] = -1;
			}
		}

	}
	return false;
}
