/#include <stdio.h>
#include<stdlib.h>

int main() {
    int a1, a2, b1, b2;

    printf("ù��° ����� ��� �� ũ�⸦ �Է��Ͻÿ�.\n");
    scanf_s("%d %d", &a1, &a2); //ù��° ����� ũ�⸦ �Է� ����

    printf("�ι�° ����� ��� �� ũ�⸦ �Է��Ͻÿ�.\n");
    scanf_s("%d %d", &b1, &b2); //�ι�° ����� ũ�⸦ �Է� ����

    if (a2 != b1) {
        printf("����� �������� ������ �� �����ϴ�.\n");
        return 1;
    } //a2�� b1�� �ٸ� ��� ����� �������� ������ �� ����

    printf("ù��° ����� ���Ҹ� �Է��Ͻÿ�.\n"); 
    int** A = malloc(sizeof(int*) * a1); //�����Ҵ��� ���ؼ� �Է¹��� ũ���� ����� �޸𸮿� �Ҵ�
    for (int i = 0; i < a1; i++) { //2���� �迭�̹Ƿ� �ݸ��� ���ؼ� �޸𸮿� �Ҵ�
        A[i] = malloc(sizeof(int*) * a2);
        for (int j = 0; j < a2; j++) { 
            scanf_s("%d", &A[i][j]); //�޸𸮿� �Ҵ��� ����� ���Ҹ� �Է¹���
        }
    }

    printf("�ι�° ����� ���Ҹ� �Է��Ͻÿ�.\n");
    int** B = malloc(sizeof(int*) * b1); //�����Ҵ��� ���ؼ� �Է¹��� ũ���� ����� �޸𸮿� �Ҵ�
    for (int i = 0; i < b1; i++) { //2���� �迭�̹Ƿ� �ݸ��� ���ؼ� �޸𸮿� �Ҵ�
        B[i] = malloc(sizeof(int*) * b2);
        for (int j = 0; j < b2; j++) {
            scanf_s("%d", &B[i][j]); //�޸𸮿� �Ҵ��� ����� ���Ҹ� �Է¹���
        }
    }

    int** C = (int**)malloc(a1 * sizeof(int*)); //����� �����ϱ� ���� ��� c�� �Ҵ�
    for (int i = 0; i < a1; i++) {
        C[i] = (int*)malloc(b2 * sizeof(int));
        for (int j = 0; j < b2; j++) {
            C[i][j] = 0;
        }
    }

    for (int i = 0; i < a1; i++) {
        for (int j = 0; j < b2; j++) {
            for (int k = 0; k < a2; k++) { //3���� �ݺ����� ���� ����� ������ ����
                C[i][j] += A[i][k] * B[k][j]; //���C�� ���A�� ���B�� �������� ���� ����
            }
        }
    }

    printf("��� ���� ����� ������ �����ϴ�:\n");
    for (int i = 0; i < a1; i++) {
        for (int j = 0; j < b2; j++) {
            printf("%d ", C[i][j]); //���C�� ����� ������� ���
        }
        printf("\n");
    }

    for (int i = 0; i < a1; i++) {
        free(A[i]);
    }
    free(A); //�����Ҵ� ����

    for (int i = 0; i < b1; i++) {
        free(B[i]);
    }
    free(B); //�����Ҵ� ����
   
    for (int i = 0; i < a1; i++) {
        free(C[i]);
    }
    free(C); //�����Ҵ� ����

    return 0;
}