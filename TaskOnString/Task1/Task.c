#include <stdio.h>
#include <malloc.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "rus");
	char* str;
	int flag = 1, id, b, e;
	str = (char*)malloc(sizeof(char) * 100);

	printf("������� ������ (�� 100 ��������): ");
	gets(str);
    int size = 0;
	while (str[size] != '\0') {
		size++;
	}
	printf("%d\n", size);
	while (flag) {
		printf("�������� �������� ��� �������:\n1) �������� ������\n2) �������� ������\n3) ���������� ������ \n4) ������� �������\n0) �����");
		scanf_s("%d", &id);
		switch (id)
		{
		case 1:
			printf("������� ������ (�� 100 ��������): ");
			gets(str);
			break;
		case 2:
			printf("� ������ �� ����� ������ ��������:");
			scanf_s("%d %d", &b, &e);
			for (int i = b; i <= e; i++) {

			}

		default:
			break;
		}
	}

	free(str);
	return 0;
}