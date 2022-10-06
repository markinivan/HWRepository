#include<stdio.h>
#include<math.h>
#include<locale.h>
#include<stdlib.h>
#include<time.h>
int main() {
	setlocale(LC_ALL, "rus");
	int a, sum = 0;
	printf("Вводите последовательность чисел:");
	while (1) {
		scanf_s("%d", &a);
		if (a > 0) {
			sum += a;

		}
		else if (a == 0) {
			break;
		}
	}
	printf("Сумма положительной подпоследовательности равна %d\n", sum);

	system("pause");
	return 0;
}