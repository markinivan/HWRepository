#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <string.h>
void merge(char* s1, char* s2, char* s3) {
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	int size = len1 + len2;
	for (int i = 0; i < size+1; i++) {
		if (i < len1) {
			s3[i] = s1[i];
		}
		else {
			s3[i+1] = s2[i - len1];
		}
	}
	s3[len1] = ' ';
}
int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char* str1;
	char* str2;
	char* str3;
	str1 = (char*)malloc(sizeof(char) * 50);
	str2 = (char*)malloc(sizeof(char) * 50);
	printf("¬ведите строку 1:");
	gets(str1);
	printf("¬ведите строку 2:");
	gets(str2);
	printf("–езультат:");
	str3 = (char*)malloc(sizeof(char) * (strlen(str1) + strlen(str2)+1));
	merge(str1, str2, str3);
	puts(str3);
	free(str1);
	free(str2);
	free(str3);
}