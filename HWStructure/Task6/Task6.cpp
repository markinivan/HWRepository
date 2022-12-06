#include<locale>
#include<stdio.h>
#include<string>
#include<iostream>

struct Dimension {
	int height;
	int depth;
	int width;
};
void input(struct Dimension* sizes) {
	std::cout << "Input height: ";
	std::cin >> (sizes->height);
	std::cout << "Input depth: ";
	std::cin >> (sizes->depth);
	std::cout << "Input width: ";
	std::cin >> (sizes->width);
};
int calculateSquare(struct Dimension sizes) {
	int square, square_bok, square_updown, square_front;
	square_bok = 2 * sizes.height * sizes.depth;
	square_updown = 2 * sizes.width * sizes.depth;
	square_front = sizes.height * sizes.width;
	square = square_bok + square_updown + square_front;
	return square;
};
int calculateVolume(struct Dimension sizes) {
	int V = sizes.height * sizes.depth * sizes.width;
	return V;
};
float calculateDye(struct Dimension sizes, float consumption) {
	int square = calculateSquare(sizes);
	float dye_needed = square * consumption;
	return dye_needed;
};
float calculatePaintingCost(struct Dimension sizes, float consumption, float workCost, float paintCost) {
	int square = calculateSquare(sizes);
	float mass = calculateDye(sizes,consumption);
	float cost1 = mass * paintCost;
	float cost2 = square * workCost;
	float costALL = cost1 + cost2;
	return costALL;
};
float calculateCupboardCost(struct Dimension sizes, float cupboardCost) {
	int square = calculateSquare(sizes);
	float cost = square * cupboardCost;
	return cost;
};
float calculateMass(struct Dimension sizes, float m2mass) {
	int square = calculateSquare(sizes);
	float mass = square * m2mass;
	return mass;
};
float calculateLiftingCost(struct Dimension sizes, float liftCost, float m2mass, int floors_count) {
	float mass = calculateMass(sizes, m2mass);
	float cost = mass * liftCost * floors_count;
	return cost;
};
float calculateCost(struct Dimension cupboard, float cupboardCost, float paintConsumption, float paintCost, float paintWorkCost, float weight, int floorsCount, float riseCost, float deliveryCost) {
	float PaintCost = calculatePaintingCost(cupboard, paintConsumption, paintWorkCost, paintCost);
	float CupboardCost = calculateCupboardCost(cupboard, cupboardCost);
	float LiftingCost = calculateLiftingCost(cupboard, riseCost, weight, floorsCount);
	float FinalCost = PaintCost + CupboardCost + LiftingCost + deliveryCost;
	return FinalCost;
};

int main() {
	setlocale(LC_ALL, "rus");
	// расход краски, стоимость работы по покраске, стоимость краски
	float paintConsumption = 0.8, paintWorkCost = 35.00, paintCost = 50.00;
	// стоимость материала шкафа за м2
	float cupboardCost = 650;
	// вес кг/м2
	float weight = 0.9;
	// число этажей
	int floorsCount = 5;
	float deliveryCost = 500.00;
	float riseCost = 2.50;
	struct Dimension cupboard;
	std::cout << "CUPBOARD PARAMETERS\n";
	input(&cupboard);
	float cost;
	cost = calculateCost(cupboard, cupboardCost, paintConsumption, paintCost, paintWorkCost, weight, floorsCount, riseCost, deliveryCost);
	float PaintCost = calculatePaintingCost(cupboard, paintConsumption, paintWorkCost, paintCost);
	float CupboardCost = calculateCupboardCost(cupboard, cupboardCost);
	float DeliveryCost = calculateLiftingCost(cupboard, riseCost, weight, floorsCount)+deliveryCost;
	std::cout << "Cost by position: \n";
	std::cout << "   - cupboard cost: " << CupboardCost << "\n";
	std::cout << "   - painting cost: " << PaintCost << "\n";
	std::cout << "   - delivery cost (with rise):" << DeliveryCost << "\n";
	std::cout << "Total cost: " << cost;
	return 0;
};