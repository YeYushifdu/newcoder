#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
void Check(int* p);
int main() {
    int N, i = 0, j, sz;
    scanf("%d", &N);        //ÓÃÀý¸öÊý
    while (i < N) {
        char arr[1000];
        gets(arr);
        int* p = arr;
        Check(*p);
        i++;
    }
    return 0;
}

void Check(int* p) {
    int i, j;
    for (i = 0; i < 998; i++) {
        if ((*(p + i) == *(p + i + 1)) && (*(p + i + 1) == *(p + i + 2))) {
            for (j = i + 2; j < 999; j++) {
                *(p + j) = *(p + j + 1);
            }
        }
    }
    for (i = 0; i < 997; i++) {
        if ((*(p + i) == *(p + i + 1)) && (*(p + i + 2) == *(p + i + 3))) {
            for (j = 1 + 3; j < 999; j++) {
                *(p + j) = *(p + j + 1);
            }
        }
    }
    printf("%s\n", *p);
}