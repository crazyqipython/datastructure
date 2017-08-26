#include <stdio.h>
#include <stdlib.h>
#include "stack_maze.h"

int mg1[10][10] = {
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

bool mgpath(int xi,int yi, int xe, int ye){
	int i,j,k,di,find;
	StType st;
	st.top = -1;
	st.top +=1;
	st.data[st.top].i = xi;
	st.data[st.top].j = yi;
	st.data[st.top].di = -1;
	mg1[xi][yi] = -1;

    //set mg1
	while(st.top>-1){
		i = st.data[st.top].i;
		j = st.data[st.top].j;
		di = st.data[st.top].di;
		//find out
		if(i==xe && j==ye){
			printf("�Թ�·������:\n");
			for(k=0; k<=st.top; k++){
				printf("\t(%d,%d)", st.data[k].i, st.data[k].j);
				if((k+1)%5==0){
					printf("\n");
				}
			}
			printf("\n");
			return true;
		}
		//û���ҵ�����
		find = 0;
		while(di<4&&find==0){
			di++;
			switch(di){
				case 0:
					i=st.data[st.top].i -1;
					j=st.data[st.top].j;
					break;
				case 1:
					i = st.data[st.top].i;
					j = st.data[st.top].j +1;
					break;
				case 2:
					i = st.data[st.top].i + 1;
					j = st.data[st.top].j;
					break;
				case 3:
					i = st.data[st.top].i;
					j = st.data[st.top].j -1;
					break;
			}
			if(mg1[i][j] == 0){
				find =1;
			}
		}
		//�ҵ���һ������
		if(find==1){
			st.data[st.top].di = di;
			st.top++;
			st.data[st.top].i = i;
			st.data[st.top].j = j;
			st.data[st.top].di = -1;
			mg1[i][j] = -1;
		}
		else{
			mg1[st.data[st.top].i][st.data[st.top].j] =0;
			st.top--;
		}
	}
	return false;
}
