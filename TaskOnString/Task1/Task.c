#include <stdio.h>
#include <malloc.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "rus");
	char* str;
	int flag = 1, id;
	str = (char*)malloc(sizeof(char) * 100);

	printf("Введите строку (до 100 символов): ");
	gets(str);
    int size = 0;
	while (str[size] != '\0') {
		size++;
	}
	printf("%d", size);
	while (flag) {
		printf("Выберите действие над строкой:\n1) Заменить строку\n2) Обрезать строку\n3) Развернуть строку \n4) Сменить регистр\n0) Выход");
		scanf_s("%d", &id);

	}

	free(str);
	return 0;
}