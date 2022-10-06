#include<stdio.h>
#include<math.h>
#include<locale.h>
#include<stdlib.h>
#include<time.h>
int main() {
	int marker, a, b, flag = 1;
	setlocale(LC_ALL, "rus");
	printf("Добро пожаловать!");
	Sleep(1000);
	system("cls");
	printf("Загрузка.");
	Sleep(500);
	system("cls");
	printf("Загрузка..");
	Sleep(500);
	system("cls");
	printf("Загрузка...");
	Sleep(500);
	system("cls");
	printf("Загрузка.");
	Sleep(500);
	system("cls");
	printf("Загрузка..");
	Sleep(500);
	system("cls");
	printf("Загрузка...");
	Sleep(500);
	system("cls");
	while (flag == 1) {
		system("cls");
		printf("Выбор фигуры:\n1. Прямоугольник.\n2. Треугольник\n3. Круг\n0. Выйти из приложения\nВвод:");
		scanf_s("%d", &marker);
		system("cls");
		if (marker == 1) {
			printf("Введите две стороны прямоугольника:");
			scanf_s("%d %d", &a, &b);
			system("cls");
			while (1) {
				system("cls");
				printf("Меню:\n1. Найти площадь прямоугольника.\n2. Найти периметр прямоугольника.\n3. Найти диагональ прямоугольника.\n4. Вернуться к выбору фигуры.\n0. Выйти.\nВвод:");
				scanf_s("%d", &marker);
				if (marker == 1) {
					printf("Площадь прямоугольника: %d\n", a * b);
					system("pause");
					system("cls");
				}
				else {
					if (marker == 2) {
						printf("Периметр прямоугольника: %d\n", a + b + a + b);
						system("pause");
						system("cls");
					}
					else {
						if (marker == 3) {
							printf("Диагональ прямоугольника: %.02f\n", sqrt(a * a + b * b));
							system("pause");
							system("cls");

						}
						else {
							if (marker == 4) {
								break;

							}
							else {
								if (marker == 0) {
									flag = 0;
									break;

								}
							}
						}
					}
				}

			}
		
		}
		if (marker == 2) {
			printf("Введите две стороны прямоугольного треугольника:");
			scanf_s("%d %d", &a, &b);
			system("cls");
			while (1) {
				system("cls");
				printf("Меню:\n1. Найти площадь треугольника.\n2. Найти периметр треугольника.\n3. Найти диагональ треугольника.\n4. Вернуться к выбору фигуры.\n0. Выйти.\nВвод:");
				scanf_s("%d", &marker);
				if (marker == 1) {
					printf("Площадь треугольника: %.02f\n", 1.0 * a * b / 2);
					system("pause");
					system("cls");
				}
				else {
					if (marker == 2) {
						printf("Периметр треугольника: %.02f\n", sqrt(a * a + b * b) + a + b);
						system("pause");
						system("cls");
					}
					else {
						if (marker == 3) {
							printf("Гипотенуза треугольника: %.02f\n", sqrt(a * a + b * b));
							system("pause");
							system("cls");

						}
						else {
							if (marker == 4) {
								break;

							}
							else {
								if (marker == 0) {
									flag = 0;
									break;

								}
							}
						}
					}
				}

			}
		}
		if (marker == 3) {
			printf("Введите радиус круга:");
			scanf_s("%d", &a);
			system("cls");
			while (1) {
				system("cls");
				printf("Меню:\n1. Найти площадь круга.\n2. Найти длину окружности круга.\n3. Найти диаметр круга.\n4. Вернуться к выбору фигуры.\n0. Выйти.\nВвод:");
				scanf_s("%d", &marker);
				if (marker == 1) {
					printf("Площадь круга: %.02f\n", 3.14 * a * a);
					system("pause");
					system("cls");
				}
				else {
					if (marker == 2) {
						printf("Длина окружности круга: %.02f\n", 2 * 3.14 * a);
						system("pause");
						system("cls");
					}
					else {
						if (marker == 3) {
							printf("Диаметр круга: %.02f\n",a*2.0);
							system("pause");
							system("cls");

						}
						else {
							if (marker == 4) {
								break;

							}
							else {
								if (marker == 0) {
									flag = 0;
									break;

								}
							}
						}
					}
				}

			}
		} else if (marker == 0)
		{
			flag = 0;
		}
	}
			system("pause");
	return 0;
}