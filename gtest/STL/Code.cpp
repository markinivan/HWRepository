#include "Head.h"
void funkA(std::vector<int>& a) {
	std::vector<int> b = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	a.assign(b.begin(), b.end());
}
void funkB(std::vector<int>& a) {
	if (a.size()==0){ 
		throw "Empty input!"; }
	//std::vector<int> a;
	srand(time(0));
	for (auto it = a.begin(); it < a.end(); it++) {
		*it = rand() % 201 - 100;
		std::cout << *it << " ";
	}
}
std::pair<int, int>& funkC(std::vector<int>& a) {
	std::pair<int, int> maxmin = { a[0], a[0] };
	for (auto it = a.begin(); it < a.end(); it++) {
		if (*it >= maxmin.first) {
			maxmin.first = *it;
		}
		else {
			if (*it < maxmin.second) {
				maxmin.second = *it;
			}
		}
	}  
	return maxmin;
}
void funkD(std::vector<int>& a, int* b, int size) {
	std::vector<int> c;
	bool flag = true;
	for (int i = 0; i < size; i++) {
		a.push_back((b[i]));
	}
	c = a;
	while (flag == 1) {
		flag = false;
		for (auto i = c.begin(); i < c.end(); i++) {
			for (auto it = i; it < c.end(); it++) {
				if (it + 1 < c.end() && *it > *(it + 1)) {
					flag = true;
					int tmp = *it;
					*it = *(it + 1);
					*(it + 1) = tmp;
				}
			}
		}
	}
	a.assign(c.begin(), c.end());

}
void funkE(std::vector<int>& a, int num) {
	for (auto it = a.begin(); it < a.end(); it++) {
		if (*it<num) {
			*it = 0;
		}
	}
}
std::vector<int> funkF(std::vector<int>& a, int num) {
	std::vector<int> d;
	for (auto it = a.begin(); it < a.end(); it++) {
		if (*it > num) {
			d.push_back(*it);
			std::cout << *it << " ";
		}
	}
	for (auto i = d.begin(); i < d.end(); i++) {
		std::cout << *i << " ";
	}
	return d;
}
std::vector<int> funkG(std::vector<int>& a) {
	srand(time(0));
	int j = 13;
	int size = a.size();
	std::vector<int> b = a;
	bool flag;
	do {
		flag = false;
		for (int i = 0; i < size; i++) {
			do {
				j = rand() % size;
			} while (j == i);
			int tmp = b[i];
			b[i] = b[j];
			b[j] = tmp;
		}
		for (int i = 0; i < b.size(); i++) {
			if (b[i] == a[i]) {
				flag = true;
				break;
			}
		}
	} while (flag);
	return b;
}
void funkH(std::vector<int>& a, int num) {
	std::vector<int> b;
	for (auto it = a.begin(); it < a.end(); it++) {
		if (*it >= num) {
			b.push_back(*it);
		}
	}
	a.assign(b.begin(),b.end());
}
int funkI(std::vector<int>& a) {
	if (a.size() % 2 == 1) {
		a.pop_back();
	}
	else {
		auto beg = a.begin();
		auto end = a.end()-1;
		for (int i = 0; i < (a.size()/2); i++){
			int tmp = *beg;
			*beg = *end;
			*end = tmp;
			beg++;
			end--;
		}
	}
	return a.size();
}
void funkJ(std::vector<int>& a) {
	std::vector<int> b = {};
	a.assign(b.begin(), b.end());
}
void funkAA(std::list<int>& a, int* b, int size){
	int s = a.size();
	for (int i = 0; i < size; i++) {
		a.resize(++s, b[i]);
	}
}
std::vector<int> funkBB(std::list<int>& a, int num) {
	int i=0;
	std::list<int>::iterator end = --a.end();
	std::vector<int> out;
	for (std::list<int>::iterator it = a.begin(); i < num && it != (end); it++) {
		out.push_back(*it);
		i++;
	}
	return out;
}
void funkCC(std::list<int>& a, int id) {
	int count = -1;
	for (std::list<int>::iterator it = a.begin(); it != a.end(); it++) {
		count++;
		if (count == id) {
			a.erase(it);
			break;
		}
	}
}
void funkDD(std::list<int>& a) {
	srand(time(0));
	int res;
	std::vector<int> id = { -1,-1,-1 };
	for (int i = 0; i < 3; i++) {
		do
		{res = rand() % (a.size());
		}
		while
		(res == id[0] || res == id[1] || res == id[2]);
		id[i] = res;
	}
	int count = 0;
	for (std::list<int>::iterator j = a.begin(); j != a.end(); j++)
	{
		for (auto it = id.begin(); it < id.end(); it++) {
			if (count == *it) {
				*j = rand() % 201 - 100;
			}
		}
		count++;
	}
}
void funkEE(std::list<int>& a) {
	std::list<int> b;
	b.push_back(*(a.begin()));
	bool flag;
	for (std::list<int>::iterator i = a.begin(); i != a.end(); i++) {
		flag = true;
		for (std::list<int>::iterator j = b.begin(); j != b.end(); j++)	{
			if (*i == *j) {
				flag = false;
			}
		}
		if (flag) {
			b.push_back(*i);
		}
	}
	for (std::list<int>::iterator j = b.begin(); j != b.end(); j++) {
		std::cout << *j << " ";
	}
	a.assign(b.begin(), b.end());
}
void funkAAA(std::list<int>& a) {
	for (auto it = a.begin(); it != (a.end()); it++) {
		std::cout << *it << " ";
	}
	std::stack<int> stack;
	std::list<int> b = a;
	for (auto it = b.begin(); it != (b.end()); it++) {
		stack.push(*it);
	}
	b = {};
	while (!stack.empty()) {
		b.push_back(stack.top());
		stack.pop();
	}
	a.assign(b.begin(), b.end());
}
void funkBBB(std::stack<int>& a) {
	//How check output?
	std::cout << "| |" << "\n";
	while (!a.empty()) {
		std::cout << "|" << a.top() << "|" << "\n";
		a.pop();
	}
	std::cout << "___";
}