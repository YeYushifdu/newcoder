#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	int N, M;		//¸ß ¿í
	int i, j;
	scanf("%d %d", &N, &M);
	int board[100][100] = { 0 };
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			scanf("%d", board[i][j]);
		}
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}
	return 0;
}