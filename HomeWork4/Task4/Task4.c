#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <math.h>
void draw_table(char** z, int** d, int s, int s1) {
	int count;
	printf("|");
	for (int i = 0; i < s; i++)
	{
		printf("%s |", z[i]);
	}
	printf("\n|");
	for (int i = 0; i < s1; i++) {
		for (int j = 0; j < s; j++) {
			if (d[j][i] > 0) {
				count = strlen(z[j]) - (floor(log10(abs(d[j][i]))) + 1) + 1;
			}
			else {
				count = strlen(z[j]);
			}
			printf("%d", d[j][i]);
			for (int t = 0; t < count; t++) {
				printf(" ");
			}
			printf("|");
		}
		if (s1 - i > 1) {
			printf("\n|");
		}
	}
	printf("\n");
	
}
int main() {
	SetConsoleCP(1251); //��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251); //��������� ������� �������� win-cp 1251 � �����
	setlocale(LC_ALL, "rus");
	int size1 = 5, size = 5;
	char kostil[3];
	char** headings;
	int** digits;
	printf("������� ����� �������� �������:");
	scanf_s("%d", &size);
	headings = (char**)malloc(sizeof(char*) * size);
	for (int i = 0; i < size; i++) {
		headings[i] = (char*)malloc(sizeof(char) * 50);
	}
	printf("������� ��������� �������:\n");
	gets(kostil);
	for (int i = 0; i < size; i++) {
		gets(headings[i]);
	}
	printf("������� ���������� ����� �������: ");
	scanf_s("%d", &size1);
	digits = (int**)malloc(sizeof(int*) * size);
	for (int i = 0; i < size; i++) {
		digits[i] = (int*)malloc(sizeof(int) * size1);
	}
	
	for (int i = 0; i < size; i++) {
		printf("������� ������ ��� ���������� ������� %s: ", headings[i]);
		for (int j = 0; j < size; j++) {
			scanf_s("%d", &digits[i][j]);
		}
	}
	printf("���� �������:\n");
	draw_table(headings,digits,size,size1);
	free(headings);
	free(digits);
	
	system("pause");
	return 0;
}