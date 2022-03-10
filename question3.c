#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct student {
	char name[15];  // �л��� �̸��� �޴� ���
	int num, total; // ���� �л��� �й�, ������ �޴� ���
}STUDENT;

void print(STUDENT *info, int MAX) {
	char head[3][5] = { "�̸�", "�й�", "����" }; 
	int i;
	for (i = 0; i < 40; i++)
		printf("-");

	printf("\n%-16s %-12s %-12s \n", head[0], head[1], head[2]);

	for (i = 0; i < 40; i++)
		printf("-");
	printf("\n");

	for (i = 0; i < MAX; i++) { // MAX = �Է¹��� �л� �� ��ŭ ��� �ݺ�
		printf("%-16s %-12d %-12d\n", (info+i)->name, (info+i)->num, (info+ i)->total);
	} // ��� ���� �������� '->' ���.

}

void sort_name(STUDENT *info, int MAX) { // ����ü�迭�� �л� ���� ����
	int i, j, temp; // temp�� int�� ���� snum�� total�� ���� �ٲ� �� ���
	char tempname[15]; // temp�� �ٸ��� char�� ���� �޾ƾ��ϴ� ���� ����

	for (i = 0; i < MAX - 1; i++) {
		for (j = i + 1; j < MAX; j++) { // ù��° ���ڿ����� 2~5��° ���ڿ����� �ѹ��� ��� ��
			if (strcmp(info[i].name, info[j].name) > 0) { //strcmp�� �̿��� ù ���ں��� ũ�� ��
				strcpy(tempname, info[i].name); // �� ���ڿ��� �� ũ�ٸ� �� ���ڿ��� ���� �ٲ�
				strcpy(info[i].name, info[j].name);
				strcpy(info[j].name, tempname); // ���������� �����ϸ� ���� ������ 0�� �迭�� ���� ū ���� 4�� �迭�� ��

				temp = info[i].num; // name�� ���� ���� ���� �ٲ�
				info[i].num = info[j].num;
				info[j].num = temp;

				temp = (info+i)->total;// ��� ���� ������ '->' ���
				(info+i)->total = (info+j)->total;
				(info+j)->total = temp;
			}
		}
	}
	print(info, MAX); // print�Լ��� ���ĵ� info �迭�� �л� �� ����
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
	int choice; // �޴��� �������� �� ���� ������ ����
	int MAX; // �Է� ���� �л� ��
	int cnt; // �ѱ����� �������� �Ǻ��� �� �� int�� ����
	int i, j;
	for (;;) { // 2 �̸�, 5�� �ʰ��ϴ� ���ڰ� �ƴ϶�� break�� Ż��
		printf("�� ���� �л� ���� �Է��Ͻðڽ��ϱ�? ");
		scanf("%d", &MAX);
		if (MAX < 2) {
			printf("Error! ������ ���� �ּ� 2�� �̻��� ������ �ʿ��մϴ�!\n\n");
		}
		else if (MAX > 5) {
			printf("Error! �ִ� 5���� �л� ������ �Է��Ͻ� �� �ֽ��ϴ�!\n\n");
		}
		else
			break;
	}
	for (i = 0; i < MAX; i++) { // MAX�� �Է� ���� �л� �� ��ŭ ���� �Է� �ݺ�
		cnt = 0; // �׸��� �Ѿ ������ ���� 0���� �ʱ�ȭ
		printf("�л� %d ����\n", i + 1);
		printf("�̸� : ");
		scanf("%s",info[i].name);
		for (j = 0; j < 15; j++) { // �ѱ� �Ǻ� for��
			if (info[i].name[j] & 0x80)
				cnt++; // �ѱ��� ���� ������ cnt ���� �÷���
			else
				printf("");
		}
		if (cnt > 0) {
			printf("Error! �л��� �̸��� ����� �Է����ּ���!\n\n");
			i--; // i�� ���� 1 �ٿ������ν� �л� 1�̿��ٸ� �ٽ� �л�1�� �ݺ�.
			continue;
		}
		if (strlen(info[i].name) >= 15) { // 15�� �̻��� ���ڷ� �Է� �޾��� ��쵵 ��������
			printf("Error! 15�� �̸��� ���� �̸����� �ٽ� �Է����ּ���!\n\n");
			i--; 
			continue;
		}

		printf("�й� : ");
		scanf("%d", &info[i].num);
		printf("���� : ");
		scanf("%d", &info[i].total);
		puts("");
	}

	while (1) { // 0�� �Է� ���� �� ���� ���� �ݺ�
		printf("\n1. �̸� ��(ABC��)  2. �й���(��������)  3. ����(��������)  0. ����");
		printf("\n   ���ϴ� ������ �����Ͻÿ�. : ");
		scanf("%d", &choice);

		switch (choice) { // �Է� ���� choice�� ������ ������ case�� �̵�
		case 0:
			printf("\n   ���α׷��� �����ϰڽ��ϴ�.\n\n");
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
		default: // ���õ� ���� �׸� �ܷ� ���� �ް� �Ǹ� default ���
			printf("��Ȯ�� ���� �Է����ּ���.\n");
		}
	}
	return 0;
}