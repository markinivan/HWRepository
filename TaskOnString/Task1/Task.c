#include <stdio.h>
#include <malloc.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "rus");
	char* str;
	int flag = 1, id;
	str = (char*)malloc(sizeof(char) * 100);

	printf("������� ������ (�� 100 ��������): ");
	gets(str);
    int size = 0;
	while (str[size] != '\0') {
		size++;
	}
	printf("%d", size);
	while (flag) {
		printf("�������� �������� ��� �������:\n1) �������� ������\n2) �������� ������\n3) ���������� ������ \n4) ������� �������\n0) �����");
		scanf_s("%d", &id);

	}

	free(str);
	return 0;
}