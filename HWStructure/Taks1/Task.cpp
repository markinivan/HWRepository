#include<locale>
#include<stdio.h>
#include<string>
#include<iostream>

struct Dimension {
	int height;
	int depth;
	int width;
};
struct Book {
	std::string author;
	std::string name;
	std::string publisher;
	int year;
	int count;
	int articul;
};
struct PFCC {
	int proteins;
	int fats;
	int carbohydrates;
	float calories;
};
struct Note {
	int pages;
	float line_step;
	std::string page_format;
	std::string line_format;
};
struct FIO {
	std::string last_name;
	std::string first_name;
	std::string patronymic;
};
struct Date {
	int day;
	int month;
	int year;
};
struct Time {
	int sec;
	int min;
	int hours;
};
struct Jeans {
	int size;
	int prise;
	std::string color;
};
struct Televisor {
	int diagonal;
	int price;
	int resolution;
	std::string model;
};
struct Body {
	int mass;
	int volume;
	int surface_area;
	std::string form;
	std::string material;
};
struct Worker {
	struct FIO name;
	struct Date B_day;
	float salary;
	int ID;
	std::string post;
};
struct Dish {
	struct PFCC pfcc;
	int serving_weight;
	std::string menu;
	std::string name;
};
struct Student {
	struct FIO name;
	struct Date B_day;
	float scholarship;
	int ID;
	int course;
	std::string direction;
};
struct Patient {
	struct FIO name;
	struct Date B_day;
	int ID;
	std::string diagnosis;
};



int main() {
	setlocale(LC_ALL, "rus");
	struct Dimension box = {10, 30, 30};
	struct Note MyNote = {48, 0.5, "A5", "клетка"};
	struct Time LunchTime = {00,30,15};
	struct PFCC d = {9,7,17};
	struct Dish Lunch = {d , 500, "сбалансированое", "плов с курицей"};
	system("pause");
	return 0;
} 