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
	printf("������� ������:\n");
	gets(str);
	while (flag) {
		len = strlen(str);
		printf("�������� �������� ��� �������:\n1) �������� ������\n2) �������� ������\n3) ���������� ������\n4) ������� �������\n0) �����\n\n��� �����:");
		scanf_s("%d", &id);
		getchar();
		switch (id) {
		case 1:
			printf("������ ������: ");// �� �����, ����� ���������� ������������
			gets(str);
			printf("������� ������: ");
			puts(str);
			break;
		case 2:
			printf("������� ��������: ");
			scanf_s("%d", &board);
			getchar();
			if (board <  len) {
				str[board] = '\0';
			} else {
				printf("������� ������� �� ������� ������!\n");
			}
			printf("���������: ");
			puts(str);
			break;
		case 3:
			for (int i = 0; i < len / 2; i++) {
				tmp = str[i];
				str[i] = str[len - i - 1];
				str[len - i - 1] = tmp;
			}
			printf("���������: ");
			puts(str);
			break;
		case 4:
			printf("1)� ������� �������\n2)� ������ �������\n3)� ��������������� �������\n��� �����: ");
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
					printf("���������: ");
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