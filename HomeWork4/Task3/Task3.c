#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
void sort(int* m, int s) {
	int count = 0;
	int tmp;
	for (int i = 0; i < s; i++){ 
		if (m[i] % 2 != 0 && m[i] != 0) {
			count += 1;
		}
	}
	for (int a = 0; a < count; a++) {
		for (int i = 0; i < s; i++) {
			if ((m[i] % 2 == 0 || m[i] == 0) && i+1<s) {
				for (int j = i + 1; j < s; j++) {
					if (m[j] % 2 == 0 || m[j] == 0) {
						if (m[i] > m[j]) {
							tmp = m[i];
							m[i] = m[j];
							m[j] = tmp;
					}
					}
				}
			}
		}
	}
}
int main() {
	setlocale(LC_ALL, "rus");
	int size;
	int* mass;
	char di[4] = { "0000" };
	printf("¬ведите размер массива:");
	scanf_s("%d", &size);
	mass = (int*)malloc(sizeof(int) * size);
	printf("¬ведите массив:");
	for (int i = 0; i < size; i++) {
		scanf_s("%d", &mass[i]);
		}
	sort(mass, size);
	printf("–езультат:");
	printf("\n");
	for (int i = 0; i < size; i++) {
		printf("%d ", mass[i]);
	}
	printf("\n");
	for (int i = 0; i < size; i++) {
		if (mass[i] % 2 == 0 || mass[i] == 0) {
			printf("%d ", mass[i]);
		}
		else {
			int ind = mass[i];
			while (ind > 10) {
				printf(" ");
				ind = ind % 10;
			} printf("  ");
		}
	}
	free(mass);
	}