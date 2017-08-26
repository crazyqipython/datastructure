#ifndef QUEUE_MAZE_H_
#define QUEUE_MAZE_H_
#define MaxSize 64

int mg[10][10] = {
		{1, 1,1,1,1,1,1,1,1, 1},
		{1, 0,0,1,0,0,0,1,0, 1},
		{1, 0,0,1,0,0,0,1,0, 1},
		{1, 0,0,0,0,1,1,0,0, 1},
		{1, 0,1,1,1,0,0,0,0, 1},
		{1, 0,0,0,1,0,0,0,0, 1},
		{1, 0,1,0,0,0,1,0,0, 1},
		{1, 0,1,1,1,0,1,1,0, 1},
		{1, 1,0,0,0,0,0,0,0, 1},
		{1, 1,1,1,1,1,1,1,1, 1}
};

typedef struct{
	int i,j;
	int pre;
}Box;

typedef struct{
	Box data[MaxSize];
	int front,rear;
}QuType;

bool mgpath1(int xi, int yi, int xe, int ye);
void print(QuType q, int i);
#endif /* QUEUE_MAZE_H_ */
