/#include <stdio.h>
#include<stdlib.h>

int main() {
    int a1, a2, b1, b2;

    printf("첫번째 행렬의 행과 열 크기를 입력하시오.\n");
    scanf_s("%d %d", &a1, &a2); //첫번째 행렬의 크기를 입력 받음

    printf("두번째 행렬의 행과 열 크기를 입력하시오.\n");
    scanf_s("%d %d", &b1, &b2); //두번째 행렬의 크기를 입력 받음

    if (a2 != b1) {
        printf("행렬의 곱연산을 진행할 수 없습니다.\n");
        return 1;
    } //a2과 b1이 다를 경우 행렬의 곱연산을 진행할 수 없음

    printf("첫번째 행렬의 원소를 입력하시오.\n"); 
    int** A = malloc(sizeof(int*) * a1); //동적할당을 통해서 입력받은 크기의 행렬을 메모리에 할당
    for (int i = 0; i < a1; i++) { //2차원 배열이므로 반목문을 통해서 메모리에 할당
        A[i] = malloc(sizeof(int*) * a2);
        for (int j = 0; j < a2; j++) { 
            scanf_s("%d", &A[i][j]); //메모리에 할당한 행렬의 원소를 입력받음
        }
    }

    printf("두번째 행렬의 원소를 입력하시오.\n");
    int** B = malloc(sizeof(int*) * b1); //동적할당을 통해서 입력받은 크기의 행렬을 메모리에 할당
    for (int i = 0; i < b1; i++) { //2차원 배열이므로 반목문을 통해서 메모리에 할당
        B[i] = malloc(sizeof(int*) * b2);
        for (int j = 0; j < b2; j++) {
            scanf_s("%d", &B[i][j]); //메모리에 할당한 행렬의 원소를 입력받음
        }
    }

    int** C = (int**)malloc(a1 * sizeof(int*)); //결과를 저장하기 위한 행렬 c를 할당
    for (int i = 0; i < a1; i++) {
        C[i] = (int*)malloc(b2 * sizeof(int));
        for (int j = 0; j < b2; j++) {
            C[i][j] = 0;
        }
    }

    for (int i = 0; i < a1; i++) {
        for (int j = 0; j < b2; j++) {
            for (int k = 0; k < a2; k++) { //3번의 반복문을 통해 행렬의 곱연산 실행
                C[i][j] += A[i][k] * B[k][j]; //행렬C에 행렬A와 행렬B를 곱연산한 값을 저장
            }
        }
    }

    printf("행렬 곱셈 결과는 다음과 같습니다:\n");
    for (int i = 0; i < a1; i++) {
        for (int j = 0; j < b2; j++) {
            printf("%d ", C[i][j]); //행렬C에 저장된 결과값을 출력
        }
        printf("\n");
    }

    for (int i = 0; i < a1; i++) {
        free(A[i]);
    }
    free(A); //동적할당 해제

    for (int i = 0; i < b1; i++) {
        free(B[i]);
    }
    free(B); //동적할당 해제
   
    for (int i = 0; i < a1; i++) {
        free(C[i]);
    }
    free(C); //동적할당 해제

    return 0;
}