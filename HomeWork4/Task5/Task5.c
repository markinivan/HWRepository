#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <string.h>
int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int size, id, board, flag = 1, len;
	char* str;
	char tmp;
	str = (char*)malloc(sizeof(char) * 100);
	printf("Введите строку:\n");
	gets(str);
	while (flag) {
		len = strlen(str);
		printf("Выберите действие над строкой:\n1) заменить строку\n2) обрезать строку\n3) развернуть строку\n4) сменить регистр\n0) выход\n\nВаш выбор:");
		scanf_s("%d", &id);
		getchar();
		switch (id) {
		case 1:
			printf("Ведите строку: ");// Не понял, какие исключения обрабатывать
			gets(str);
			printf("Текущая строка: ");
			puts(str);
			break;
		case 2:
			printf("Введите значение: ");
			scanf_s("%d", &board);
			getchar();
			if (board <  len) {
				str[board] = '\0';
			} else {
				printf("Граница выходит за пределы строки!\n");
			}
			printf("Результат: ");
			puts(str);
			break;
		case 3:
			for (int i = 0; i < len / 2; i++) {
				tmp = str[i];
				str[i] = str[len - i - 1];
				str[len - i - 1] = tmp;
			}
			printf("Результат: ");
			puts(str);
			break;
		case 4:
			printf("1)В верхний регистр\n2)В нижний регистр\n3)В противоположный регистр\nВаш выбор: ");
			scanf_s("%d", &id);
			switch (id) {
			case 1:
				for (int i = 0; i < len; i++) {
					if ((str[i] > 96 && str[i] < 123) || (str[i] > -33 && str[i] < 0)) {
						str[i] = str[i] - 32;
					}
					else if (str[i] == -72) {
						str[i] = -88;
					}
				}
				break;
			case 2:
				for (int i = 0; i < len; i++) {
					if ((str[i] > 64 && str[i] < 91) || (str[i] > -65 && str[i] < -32)) {
						str[i] = str[i] + 32;
					}
					else if (str[i] == -88) {
						str[i] = -72;
						break;
			default :
				for (int i = 0; i < len; i++) {
					if ((str[i] > 96 && str[i] < 123) || (str[i] > -33 && str[i] < 0)) {
						str[i] = str[i] - 32;
					}
					else if (str[i] == -72) {
						str[i] = -88;
					}
					else if ((str[i] > 64 && str[i] < 91) || (str[i] > -65 && str[i] < -32)) {
						str[i] = str[i] + 32;
					}
					else if (str[i] == -88) {
						str[i] = -72;
					}
					printf("Результат: ");
					puts(str);
					
				}
				break;
					}
				}
			}
			break;
		default:
			flag = 0;
			break;
		}
	}
	free(str);
	system("pause");
}