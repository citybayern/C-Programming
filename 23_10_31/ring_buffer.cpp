#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int ringbuffer[5] = { 0, };

    while (1) {
        printf("배열 값 입력:\n");

        for (int i = 0; i < 5; ++i) {
            printf("ringbuffer[%d]: ", i);
            scanf("%d", &ringbuffer[i]);
        }

        // 입력 받은 배열 값 출력하기
        printf("입력한 배열 값: ");
        for (int i = 0; i < 5; ++i) {
            printf("%d ", ringbuffer[i]);
        }
        printf("\n");
    }

    return 0;
}
