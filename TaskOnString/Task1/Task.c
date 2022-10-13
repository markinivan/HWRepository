#include <stdio.h>
#include <malloc.h>
int main() {
	char* str;
	str = (char*)malloc(sizeof(char) * 100);

	gets(str);
	str[6] = '\0';
	puts(str);


	int size = 0;
	while (str[size] != '\0') {
		size++;
	}

	free(str);
	return 0;
}