#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	int N, minutes;		//��ʱ�� ά��Ц��ʱ��
	int i, j, k,m, start = 0, flag;
	scanf("%d,%d", &N, &minutes);
	int customers[3109];
	int smile[3109] = { 0 };			//����Ҫȫ��0����Ȼ���һλsmile[start+minutes+k]��֪���Ƕ���
	int sum = 0, max = 0;				//��ǰ�˿��� ���˿���
	for (i = 0;; i++) {
		scanf("%d", &customers[i]);		//�÷��ӹ˿���
		if (getchar() == '\n') {
			break;
		}
	}
	for (i = 0; i < N; i++) {
		scanf("%d", &smile[i]);			//�÷����Ƿ�Ц
		if (getchar() == '\n') {
			break;
		}
	}
	//����ӵ�0���ӿ�ʼ���㣬������һ��smile[]==0���������,i=0,����minutes����
	do{
		sum = 0;
		j = 0;
		do {
			sum += customers[start + j];
			j++;
		} while (smile[start + j] == 1);		//һֱЦһֱ����
		//��Ц�˿�ʼ��ά��
		k = 0;
		do {
			sum += customers[start + j + k];
			k++;
		} while (k < minutes);
		flag = 1;
		for (m = 0; start + j + k + m < N; m++) {		//�ܷ����Ц
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