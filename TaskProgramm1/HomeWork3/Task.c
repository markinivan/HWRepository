#include<stdio.h>
#include<math.h>
#include<locale.h>
#include<stdlib.h>
#include<time.h>
int main() {
	int marker, a, b, flag = 1;
	setlocale(LC_ALL, "rus");
	printf("����� ����������!");
	Sleep(1000);
	system("cls");
	printf("��������.");
	Sleep(500);
	system("cls");
	printf("��������..");
	Sleep(500);
	system("cls");
	printf("��������...");
	Sleep(500);
	system("cls");
	printf("��������.");
	Sleep(500);
	system("cls");
	printf("��������..");
	Sleep(500);
	system("cls");
	printf("��������...");
	Sleep(500);
	system("cls");
	while (flag == 1) {
		system("cls");
		printf("����� ������:\n1. �������������.\n2. �����������\n3. ����\n0. ����� �� ����������\n����:");
		scanf_s("%d", &marker);
		system("cls");
		if (marker == 1) {
			printf("������� ��� ������� ��������������:");
			scanf_s("%d %d", &a, &b);
			system("cls");
			while (1) {
				system("cls");
				printf("����:\n1. ����� ������� ��������������.\n2. ����� �������� ��������������.\n3. ����� ��������� ��������������.\n4. ��������� � ������ ������.\n0. �����.\n����:");
				scanf_s("%d", &marker);
				if (marker == 1) {
					printf("������� ��������������: %d\n", a * b);
					system("pause");
					system("cls");
				}
				else {
					if (marker == 2) {
						printf("�������� ��������������: %d\n", a + b + a + b);
						system("pause");
						system("cls");
					}
					else {
						if (marker == 3) {
							printf("��������� ��������������: %.02f\n", sqrt(a * a + b * b));
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
			printf("������� ��� ������� �������������� ������������:");
			scanf_s("%d %d", &a, &b);
			system("cls");
			while (1) {
				system("cls");
				printf("����:\n1. ����� ������� ������������.\n2. ����� �������� ������������.\n3. ����� ��������� ������������.\n4. ��������� � ������ ������.\n0. �����.\n����:");
				scanf_s("%d", &marker);
				if (marker == 1) {
					printf("������� ������������: %.02f\n", 1.0 * a * b / 2);
					system("pause");
					system("cls");
				}
				else {
					if (marker == 2) {
						printf("�������� ������������: %.02f\n", sqrt(a * a + b * b) + a + b);
						system("pause");
						system("cls");
					}
					else {
						if (marker == 3) {
							printf("���������� ������������: %.02f\n", sqrt(a * a + b * b));
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
			printf("������� ������ �����:");
			scanf_s("%d", &a);
			system("cls");
			while (1) {
				system("cls");
				printf("����:\n1. ����� ������� �����.\n2. ����� ����� ���������� �����.\n3. ����� ������� �����.\n4. ��������� � ������ ������.\n0. �����.\n����:");
				scanf_s("%d", &marker);
				if (marker == 1) {
					printf("������� �����: %.02f\n", 3.14 * a * a);
					system("pause");
					system("cls");
				}
				else {
					if (marker == 2) {
						printf("����� ���������� �����: %.02f\n", 2 * 3.14 * a);
						system("pause");
						system("cls");
					}
					else {
						if (marker == 3) {
							printf("������� �����: %.02f\n",a*2.0);
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