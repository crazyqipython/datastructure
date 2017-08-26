#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100

int mg[6][6]= //M=4 ，N=4
{ {1, 1, 1, 1, 1, 1},
{1, 0, 0, 0, 1, 1},
{1, 0, 1, 0, 0, 1},
{1, 0, 0, 0, 1 ,1},
{1, 1, 0, 0, 0, 1},
{1, 1, 1, 1, 1, 1} };

typedef struct{
	int i;
	int j;
}Box;

typedef struct{
	Box data[MaxSize];
	int length;
}PathType;

void mgmath(int xi, int yi, int xe,int ye,PathType path){
	int di,k,i,j;
	if(xi==xe&&yi==ye){
		path.data[path.length].i = xi;
		path.data[path.length].j = yi;
		path.length++;
		printf(" 迷宫路 如下:\n");
		for (k=0;k<path.length;k++)
		{
			printf("\t(%d,%d)",path.data[k].i, path.data[k].j);
			if ((k+1)%5==0) // 每输出每5 个方块后换一行
				printf("\n");
		}
		printf("\n");
	}
	else{
		if(mg[xi][yi]==0){
			di=0;
			while(di<4){
				switch(di){
					case 0:
						i = xi-1;
						j = yi;
						break;
					case 1:i=xi; j=yi+1; break;
					case 2:i=xi+1; j=yi; break;
					case 3:i=xi; j=yi-1; break;
				}
				path.data[path.length].i = xi;
				path.data[path.length].j = yi;
				path.length++;
				mg[xi][yi] = -1;
				mgmath(i,j,xe,xe,path);
				path.length--;
				if(!(xi==3&&yi==2)){
					mg[xi][yi] = 0;
				}
				di++;
			}
		}
	}
}

int s=0;
int add1(int n){
	if(n==1){
		return 1;
	}
	else{
		return n+add1(n-1);
	}
}

int main(){
	PathType path;
	path.length=0;
	mgmath(1,1,4,4,path);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
//	s =add1(6);
//	printf("he wei %d.\n",s);
}
