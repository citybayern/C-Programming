#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void Insert(int idx,int list[], int searchnum)	 // insert 함수를 만들어서 값을 복사한 후 뒤쪽에 붙임.
{
	
	memmove(list + idx + 1, list + idx, sizeof(int) * (6-idx));   // memmove(목적지,복사시작위치,복사할byte)를 이용하여 이동시킨다.
	list[idx] = searchnum;			// 원하는 원소 값을 넣는다.
}

void main(void)
{
	int list[7] = { 1,4,9,15,30,0,0 };	// list는 list[0] ~ list[6] 까지 있다.
	Insert(3, list, 10);			// list[3]자리에 10의 값을 넣기위해, 
    						// list[3~6]을 memmove를 통해 복사한 후 list[4~6]에 붙여넣는다.
	for (int i = 0; i < 7; i++) {
		printf("%d ", list[i]);		// 결과값 : 1 4 9 10 15 30 0 
	}
}
