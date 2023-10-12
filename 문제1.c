#include <stdio.h>
#include <math.h>

struct plane { //점 구조체
	int x;
	int y;
};

struct circle { //원 구조체
	struct plane c;
	int r;
};

void func1(struct plane a, struct circle b) { //원과 점의 위치관계를 판별하는 함수
	int a1 = b.c.x - a.x;
	int b1 = b.c.y - a.y;
	int r = b.r;

	double d = sqrt((a1 * a1) + (b1 * b1)); //점a와 원b의 중심 사이의 거리

	if (d > r) //점a와 원b의 중심 사이의 거리가 원의 반지름보다 클 경우 점은 원 밖에 있음
		printf("점은 원 밖에 있습니다.\n");
	else if (d < r) //점a와 원b의 중심 사이의 거리가 원의 반지름보다 작을 경우 점은 원 안에 있음
		printf("점은 원 안에 있습니다.\n");
	else //그 외 경우는 점이 원 위에 있는 경우
		printf("점은 원 위에 있습니다.\n");


}

void func2(struct circle a, struct circle b) { //원a과 원b의 위치관계를 판별하는 함수
	int a1 = a.c.x - b.c.x;
	int b1 = a.c.y - b.c.y;
	int r1 = abs(a.r - b.r);
	int r2 = a.r + b.r;

	double d = sqrt((a1 * a1) + (b1 * b1)); //원a와 원b 중심사이의 거리

	if (a1 == 0 && b1 == 0 && r1 == 0) //원의 줌심이 같고 반지름이 같은 경우 두 원은 일치
		printf("두 원은 일치 합니다.\n");
	else if (r1 == d || r2 == d) //중심사이 거리가 두 원의 반지름의 차 또는 합과 동일할 경우 두 원은 내접 도는 외접함
		printf("두 원은 한 점에서 만납니다.\n");
	else if (r1 < d && d < r2) //중심사이 거리가 반지름의 차와 반지름의 합 사이인 경우 두 원은 두 점에서 만남
		printf("두 원은 두 점에서 만납니다.\n");
	else if (d < r1) { //반지름의 차보다 중심사이 거리가 작을 경우 한 원이 한 원 내부에 있음
		if (a.r > b.r) //원a의 반지름이 큰 경우
			printf("원B는 원A 내부에 있습니다.\n");
		else //원b의 반지름이 큰 경우
			printf("원A는 원B 내부에 있습니다.\n");
	}
	else //위 상황 외 경우는 두 원이 서로 밖에 있고 반나지 않는 경우
		printf("원A, 원B는 내부에 있지도 않고 만나지도 않습니다.\n");

	return 0;
}

int main() {
	struct plane p1;
	struct circle c1;
	struct circle c2;

	p1.x = 1; //점p1의 x좌표
	p1.y = 2; //점p2의 y좌표

	c1.c.x = 1; //원c1 중심의 x좌표
	c1.c.y = 1; //원c1 줌심의 y좌표
	c1.r = 4; //원c1의 반지름

	c2.c.x = 1; //원c2 중심의 x좌표
	c2.c.y = 2; //원c2 중심의 y좌표
	c2.r = 3; //원c2의 반지름

	func1(p1, c1); //점p1과 원c1 사이의 위치관계를 판별하는 함수 실행
	func2(c1, c2); //원c1과 원c2 사이의 위치관계를 판별하는 함수 실행

	return 0;
}
