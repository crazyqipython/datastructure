/*
 * main.cpp
 *
 *  Created on: 2017Äê8ÔÂ12ÈÕ
 *      Author: Dick
 */
#include <stdio.h>
#include "search.h"

int main(){

	{
	int R[10] = {0,1,2,3,4,5,6,7,8,9};
	int i = BinSearch(R, 0, 10, 12);
	printf("%d", i);
	}
}


