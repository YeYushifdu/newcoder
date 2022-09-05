#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	int N, minutes;		//总时间 维持笑的时间
	int i, j, k,m, start = 0, flag;
	scanf("%d,%d", &N, &minutes);
	int customers[3109];
	int smile[3109] = { 0 };			//这里要全置0，不然最后一位smile[start+minutes+k]不知道是多少
	int sum = 0, max = 0;				//当前顾客数 最大顾客数
	for (i = 0;; i++) {
		scanf("%d", &customers[i]);		//该分钟顾客数
		if (getchar() == '\n') {
			break;
		}
	}
	for (i = 0; i < N; i++) {
		scanf("%d", &smile[i]);			//该分钟是否笑
		if (getchar() == '\n') {
			break;
		}
	}
	//如果从第0分钟开始计算，碰到第一个smile[]==0则调整情绪,i=0,持续minutes分钟
	do{
		sum = 0;
		j = 0;
		do {
			sum += customers[start + j];
			j++;
		} while (smile[start + j] == 1);		//一直笑一直满意
		//不笑了开始用维持
		k = 0;
		do {
			sum += customers[start + j + k];
			k++;
		} while (k < minutes);
		flag = 1;
		for (m = 0; start + j + k + m < N; m++) {		//能否继续笑
			if (flag == 1 && smile[start + j + k + m] == 1) {
				sum += customers[start + j + k + m];
			}
			if (smile[start + j + k + m] == 0) {
				flag = 0;
				if (sum > max) {
					max = sum;
				}
				break;
			}
		}
		start++;
	} while (start < N);
	printf("%d", max);
	return 0;
}