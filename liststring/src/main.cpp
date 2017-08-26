#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxSize 100
typedef struct {
	char data[MaxSize];
	int length;
} SqString;

typedef struct LNode {
	char data;
	struct LNode *next;
} LString;

int Strcmp(SqString s, SqString t) {
	int i, comlen;
	if (s.length < t.length) {
		comlen = s.length;
	} else {
		comlen = t.length;
	}
	for (i = 0; i < comlen; i++) {
		if (s.data[i] > t.data[i]) {
			return 1;
		} else if (s.data[i] < t.data[i]) {
			return -1;
		}
	}
	if (s.length == t.length) {
		return 0;
	} else if (s.length > t.length) {
		return 1;
	} else {
		return -1;
	}
}

bool initstring(SqString &s) {
	s.length = 0;
	return true;
}

bool strinsert(SqString &s, char e) {
	if (s.length == MaxSize) {
		return false;
	}
	s.data[s.length] = e;
	s.length++;
	return true;
}

void Repl(LString *&L) {
	LString *p, *q;
	int find = 0;
	char c = 'y';
	q = (LString *) malloc(sizeof(LString));
	q->data = c;
	p = L->next;
	while (p->next != NULL && find == 0) {
		if (p->data == 'a' && p->next->data == 'b') {
			p->data = 'x';
			p->next->data = 'z';
			q->next = p->next;
			p->next = q;
			find = 1;
		} else {
			p = p->next;
		}
	}
}

//brute force
int index(SqString s, SqString t) {
	int i = 0, j = 0;
	while (i < s.length && j < t.length) {
		if (s.data[i] == t.data[j]) {
			i++;
			j++;
		} else {
			i = i - j + 1;
			j = 0;
		}
	}
	if (j >= t.length) {
		return (i - t.length);
	} else {
		return -1;
	}
}

void computeLPSArray(char *pat, int M, int *lps){
	int len = 0;
	lps[0] = 0;
	int i = 1;
	while(i<M){
		if(pat[i] == pat[len]){
			len++;
			lps[i] = len;
			i++;
		}
		else{
			if(len!=0){
				len = lps[len-1];
			}
			else{
				lps[i] = 0;
				i++;
			}
		}
	}

}

void KMPSearch(char *pat, char *txt){
	int M = strlen(pat);
	int N = strlen(txt);

	int lps[M];
	computeLPSArray(pat, M, lps);

	int i = 0;
	int j = 0;
	while(i<N){
		if(pat[j] == txt[i]){
			i++;
			j++;
		}
		if(j==M){
			printf("find pattern at index %d \n",i-j);
			j = lps[j-1];
		}
		else if(i<N&& pat[j]!=txt[i]){
			if(j!=0){
				j = lps[j-1];
			}
			else{
				i = i+1;
			}
		}
	}

}

int main() {
//	printf("hello world");
//	SqString s, s1;
//
//	char c;
//	int i;
//	printf("test init string");
//	{
//		initstring(s);
//		initstring(s1);
//		printf("the lenght of s is %d\n", s.length);
//	}
//	printf("test insert string\n");
//	{
//		for (i = 65; i < 80; i++) {
//			c = i;
//			strinsert(s, c);
////			strinsert(s1,c);
//		}
//		for (i = 70; i < 80; i++) {
//			c = i;
//			strinsert(s1, c);
//		}
//	}
//	printf("display s\n");
//	{
//		for (i = 0; i < s.length; i++) {
//			printf("%c ", s.data[i]);
//		}
//	}
//	printf("test strcmp s\n");
//	{
//		if (Strcmp(s, s1) == 1) {
//			printf("s 大于 s1\n");
//		} else if (Strcmp(s, s1) == -1) {
//			printf("s 小于 s1\n");
//		} else {
//			printf("s 等于s1\n");
//		}
//	}
//	printf("test brute force s\n");
//	{
//		i = index(s, s1);
//		printf("在 %d", i);
//	}
//	char txt[] = "ABABDABACDABABCABAB";
//	char pat[] = "ABABCABAB";
//	printf("hello kmpsearch");
//	KMPSearch(pat, txt);
//	return 0;
	int a[1][3];
	a[0][0]=1;
	printf("%d",a[0][0]);
}
