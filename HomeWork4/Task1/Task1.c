#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
void generateMass(int* a, int s) {
	for (int i = 0; i < s; i++) {
		a[i] = rand() % 101;
	}
}
int Min(int* a, int s) {
	int min = a[0];
	for (int i = 1; i < s; i++) {
		if (a[i] < min) {
			min = a[i];
		}
	}
	return min;
}
int Max(int* a, int s) {
	int max = a[0];
	for (int i = 1; i < s; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}
	return max;
}
int Mid(int* a, int s) {
	int sum = 0, count = 0;
	for (int i = 1; i < s; i++) {
		sum += a[i];
	}
	return sum/s;
}
void printMass(int* a, int s) {
	printf("\n");
	for (int i = 0; i < s; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}
int main() {
	setlocale(LC_ALL, "rus");
	srand(time);
	int size = 10, ind, flag = 1;
	int mass[10];
	while (flag) {
		printf("Выберите действие:\n 1)Сгенерировать массив\n 2)Найти минимум\n 3)Найти максимум\n 4)Найти среднее арифметическое\n 5)Вывести массив на экран\n 6)Выход из программы\n Ваш ввод:");
		scanf_s("%d",&ind);
		system("cls");
		switch (ind)
		{
		case 1:
			generateMass(mass, size);
			break;
		case 2:
			printf("%d\n", Min(mass, size));
			system("pause");
			system("cls");
			break;
		case 3:
			printf("%d\n", Max(mass, size));
			system("pause");
			system("cls");
			break;
		case 4:
			printf("%f\n", Mid(mass, size));
			system("pause");
			system("cls");
			break;
		case 5:
			printMass(mass, size);
			system("pause");
			system("cls");
			break;
		default:
			flag = 0;
			break;
		}
	}
}