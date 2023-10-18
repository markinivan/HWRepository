#pragma once
#include "vector"
#include "iterator"
#include "random"
#include "iostream"
#include <iomanip>
#include <utility>
#include <list>
#include <stack>
void funkA(std::vector<int>& a);
void funkB(std::vector<int>& a);
std::pair<int, int>& funkC(std::vector<int>& a);
void funkD(std::vector<int>& a, int* b, int size);
void funkE(std::vector<int>& a, int num);
std::vector<int> funkF(std::vector<int>& a, int num);
std::vector<int> funkG(std::vector<int>& a);
void funkH(std::vector<int>& a, int num);
int funkI(std::vector<int>& a);
void funkJ(std::vector<int>& a);
void funkAA(std::list<int>& a, int* b, int size);
std::vector<int> funkBB(std::list<int>& a, int num);
void funkCC(std::list<int>& a, int id);
void funkDD(std::list<int>& a);
void funkEE(std::list<int>& a);
void funkAAA(std::list<int>& a);
void funkBBB(std::stack<int>& a);