#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct student {
	char name[15];  // 학생의 이름을 받는 멤버
	int num, total; // 각각 학생의 학번, 총점을 받는 멤버
}STUDENT;

void print(STUDENT *info, int MAX) {
	char head[3][5] = { "이름", "학번", "총점" }; 
	int i;
	for (i = 0; i < 40; i++)
		printf("-");

	printf("\n%-16s %-12s %-12s \n", head[0], head[1], head[2]);

	for (i = 0; i < 40; i++)
		printf("-");
	printf("\n");

	for (i = 0; i < MAX; i++) { // MAX = 입력받은 학생 수 만큼 출력 반복
		printf("%-16s %-12d %-12d\n", (info+i)->name, (info+i)->num, (info+ i)->total);
	} // 멤버 접근 연산자인 '->' 사용.

}

void sort_name(STUDENT *info, int MAX) { // 구조체배열과 학생 수를 받음
	int i, j, temp; // temp는 int형 값인 snum과 total의 값을 바꿀 때 사용
	char tempname[15]; // temp와 다르게 char형 값을 받아야하니 따로 선언

	for (i = 0; i < MAX - 1; i++) {
		for (j = i + 1; j < MAX; j++) { // 첫번째 문자열부터 2~5번째 문자열까지 한번씩 모두 비교
			if (strcmp(info[i].name, info[j].name) > 0) { //strcmp를 이용해 첫 글자부터 크기 비교
				strcpy(tempname, info[i].name); // 앞 문자열이 더 크다면 뒷 문자열과 값을 바꿈
				strcpy(info[i].name, info[j].name);
				strcpy(info[j].name, tempname); // 마지막까지 진행하면 가장 작은게 0번 배열에 가장 큰 값이 4번 배열에 들어감

				temp = info[i].num; // name에 따라 같이 값을 바꿈
				info[i].num = info[j].num;
				info[j].num = temp;

				temp = (info+i)->total;// 멤버 접근 연산자 '->' 사용
				(info+i)->total = (info+j)->total;
				(info+j)->total = temp;
			}
		}
	}
	print(info, MAX); // print함수로 정렬된 info 배열과 학생 수 전달
}

void sort_num(STUDENT *info, int MAX) {
	int i, j, temp;
	char tempname[15];

	for (i = 0; i < MAX - 1; i++) {
		for (j = i + 1; j < MAX; j++) {
			if (info[i].num > info[j].num) {
				strcpy(tempname, info[i].name);
				strcpy(info[i].name, info[j].name);
				strcpy(info[j].name, tempname);

				temp = info[i].num;
				info[i].num = info[j].num;
				info[j].num = temp;

				temp = (info + i)->total;
				(info + i)->total = (info + j)->total;
				(info + j)->total = temp;
			}
		}
	}
	print(info, MAX);
}

void sort_total(STUDENT *info, int MAX) {
	int i, j, temp;
	char tempname[15];

	for (i = 0; i < MAX -1 ; i++) {
		for (j = i + 1; j < MAX; j++) {
			if (info[i].total < info[j].total) {
				strcpy(tempname, info[i].name);
				strcpy(info[i].name, info[j].name);
				strcpy(info[j].name, tempname);

				temp = info[i].num;
				info[i].num = info[j].num;
				info[j].num = temp;

				temp = (info + i)->total;
				(info + i)->total = (info + j)->total;
				(info + j)->total = temp;
			}
		}
	}
	print(info, MAX);
}

int main(void) {

	STUDENT info[5] = { 0 };
	int choice; // 메뉴를 선택했을 때 값을 저장할 변수
	int MAX; // 입력 받을 학생 수
	int cnt; // 한글인지 영문인지 판별할 때 쓸 int형 변수
	int i, j;
	for (;;) { // 2 미만, 5를 초과하는 숫자가 아니라면 break로 탈출
		printf("몇 명의 학생 수를 입력하시겠습니까? ");
		scanf("%d", &MAX);
		if (MAX < 2) {
			printf("Error! 소팅을 위해 최소 2명 이상의 정보가 필요합니다!\n\n");
		}
		else if (MAX > 5) {
			printf("Error! 최대 5명의 학생 정보를 입력하실 수 있습니다!\n\n");
		}
		else
			break;
	}
	for (i = 0; i < MAX; i++) { // MAX에 입력 받은 학생 수 만큼 정보 입력 반복
		cnt = 0; // 항목이 넘어갈 때마다 새로 0으로 초기화
		printf("학생 %d 정보\n", i + 1);
		printf("이름 : ");
		scanf("%s",info[i].name);
		for (j = 0; j < 15; j++) { // 한글 판별 for문
			if (info[i].name[j] & 0x80)
				cnt++; // 한글이 나올 때마다 cnt 값을 올려줌
			else
				printf("");
		}
		if (cnt > 0) {
			printf("Error! 학생의 이름은 영어로 입력해주세요!\n\n");
			i--; // i의 값을 1 줄여줌으로써 학생 1이였다면 다시 학생1로 반복.
			continue;
		}
		if (strlen(info[i].name) >= 15) { // 15개 이상의 글자로 입력 받았을 경우도 마찬가지
			printf("Error! 15개 미만의 영문 이름으로 다시 입력해주세요!\n\n");
			i--; 
			continue;
		}

		printf("학번 : ");
		scanf("%d", &info[i].num);
		printf("총점 : ");
		scanf("%d", &info[i].total);
		puts("");
	}

	while (1) { // 0을 입력 받을 때 까지 무한 반복
		printf("\n1. 이름 순(ABC순)  2. 학번순(오름차순)  3. 총점(내림차순)  0. 종료");
		printf("\n   원하는 정렬을 선택하시오. : ");
		scanf("%d", &choice);

		switch (choice) { // 입력 받은 choice의 값으로 각각의 case로 이동
		case 0:
			printf("\n   프로그램을 종료하겠습니다.\n\n");
			return 0;
		case 1:
			sort_name(info, MAX);
			break;
		case 2:
			sort_num(info, MAX);
			break;
		case 3:
			sort_total(info, MAX);
			break;
		default: // 제시된 선택 항목 외로 값을 받게 되면 default 출력
			printf("정확한 값을 입력해주세요.\n");
		}
	}
	return 0;
}