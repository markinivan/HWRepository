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
struct FoodIntake {
	struct Dish dish1;
	struct Dish dish2;
};
struct FamilyMember {
	struct FIO name;
	struct Date B_day;
	std::string family_status;
};
struct PFCC CreatePFCC(int p, int f, int car, float cal) {
	struct PFCC NEW;
	NEW.proteins = p;
	NEW.fats = f;
	NEW.carbohydrates = car;
	NEW.calories = cal;
	return NEW;
};
void CreateBody(struct Body* new_body) {
	int m, v, s;
	std::string f;
	std::string mat;
	std::cout << "Input mass: ";
	std::cin >> m;
	std::cout << "Input volume: ";
	std::cin >> v;
	std::cout << "Input surface area: ";
	std::cin >> s;
	std::cout << "Input surface form: ";
	std::cin >> f;
	std::cout << "Input surface material: ";
	std::cin >> mat;
    new_body->mass = m;
	new_body->volume = v;
	new_body->surface_area = s;
	new_body->form = f;
	new_body->material = mat;
};
struct Note CreateNote(struct Note note) {
	struct Note NEW;
	NEW.pages = note.pages;
	NEW.line_step = note.line_step;
	NEW.line_format = note.line_format;
	NEW.page_format = note.page_format;
	return NEW;
};
struct Jeans CreateJeans(int s, int p, std::string color){
	struct Jeans NEW;
	NEW.size = s;
	NEW.prise = p;
	NEW.color = color;
	return NEW;
};



int main() {
	setlocale(LC_ALL, "rus");
	struct Dimension box = { 10, 30, 30 };
	struct Note MyNote = { 48, 0.5, "A5", "клетка" };
	struct Time LunchTime = { 00,30,15 };
	struct Dish Lunch = { {9,7,17,164.8} , 500, "сбалансированое", "плов с курицей" };
	struct FoodIntake menu[3];
	menu[0] = { { {4,2,19}, 300, "злаковое", "каша гречневая"},{{0,0,0,0.3}, 300, "напитки", "чай"} };
	menu[1] = { Lunch,{{0,0,0,0.3}, 300, "напитки", "чай" } };
	menu[2] = { {{54,37,1,544},500,"мясное","котлеты куриные"}, {{0,0,12,46.5}, 300, "напитки", "компот"} };
	struct FamilyMember family[3];
	family[0] = { {"Нотин","Александр","Григорьевич"},{12,8,1981},"отец"};
	family[1] = { {"Нотина","Виктория","Алексеевна"},{19,7,1984},"мать"};
	family[2] = { {"Нотин","Пётр","Александрович"},{4,11,2009},"сын"};
	system("pause");
	return 0;
} 