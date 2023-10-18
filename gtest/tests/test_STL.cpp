#include "Head.h"
#include "gtest.h"

TEST(test_A, test1) {
	// Arrange
	std::vector<int> x;
	std::vector<int> res = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	// Act
	funkA(x);
	// Assert
	EXPECT_EQ(x, res);
}
TEST(test_B, test1) {
	// Arrange
	std::vector<int> x = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	std::vector<int> y = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	// Act
	funkB(x);
	// Assert
	EXPECT_NE(x, y);
}
TEST(test_B, test2) {
	// Arrange
	std::vector<int> x;
	// Act & Assert
	EXPECT_ANY_THROW(funkB(x));
}
TEST(test_C, test1) {
	// Arrange
	std::vector<int> x = { 4, 53, 52, 13, 0 ,-3, 45, 18 };
	std::pair<int,int> y = {53,-3};
	// Act
	std::pair<int,int> res = funkC(x);
	// Assert
	EXPECT_EQ(res, y);
}
TEST(test_C, test2) {
	// Arrange
	std::vector<int> x = { 4 };
	std::pair<int, int> y = { 4,4 };
	// Act
	std::pair<int, int> res = funkC(x);
	// Assert
	EXPECT_EQ(res, y);
}
TEST(test_D, test1) {
	// Arrange
	std::vector<int> x = { 3, 4, 12, -5, 56, 36, -32, -11};
	int y[8] = {5, -3, 42, 21, 22, 2, 13, 7};
	std::vector<int> res = {-32, -11, -5, -3, 2, 3, 4, 5, 7, 12, 13, 21, 22, 36, 42, 56};
	// Act
	funkD(x,y,8);
	// Assert
	EXPECT_EQ(res, x);
}
TEST(test_E, test1) {
	// Arrange
	std::vector<int> x = { -32, -11, -5, -3, 2, 3, 4, 5, 7, 12, 13, 21, 22, 36, 42, 56 };
	int y = 10;
	std::vector<int> res = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 13, 21, 22, 36, 42, 56 };
	// Act
	funkE(x, y);
	// Assert
	EXPECT_EQ(res, x);
}
TEST(test_F, test1) {
	// Arrange
	std::vector<int> x = { -32, -11, -5, -3, 2, 3, 4, 5, 7, 12, 13, 21, 22, 36, 42, 56 };
	int y = 10;
	std::vector<int> res = {12, 13, 21, 22, 36, 42, 56 };
	// Act
	std::vector<int> check = funkF(x, y);
	// Assert
	EXPECT_EQ(check, res);
}
TEST(test_G, test1) {
	// Arrange
	std::vector<int> x = { -32, -11, -5, -3, 2, 3, 4, 5, 7, 12, 13, 21, 22, 36, 42, 56 };
	bool flag = true;
	// Act
	std::vector<int> check = funkG(x);
	std::vector<int> res = {};
	std::vector<int> test = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	for (int i = 0; i < x.size(); i++) {
		if (x[i] == check[i]) {
			flag = false;
			break;
		}
	}
	// Assert
	EXPECT_EQ(flag, 1);
}
TEST(test_H, test1) {
	// Arrange
	std::vector<int> x = { -32, -11, -5, -3, 2, 3, 4, 5, 7, 12, 13, 21, 22, 36, 42, 56 };
	int y = 10;
	std::vector<int> res = { 12, 13, 21, 22, 36, 42, 56 };
	// Act
	funkH(x, y);
	// Assert
	EXPECT_EQ(x, res);
}
TEST(test_I, test1) {
	// Arrange
	std::vector<int> x = { -32, -11, -5, -3, 2, 3, 4, 5, 7, 12, 13, 21, 22, 36, 42, 56, 23 };
	std::vector<int> res = { -32, -11, -5, -3, 2, 3, 4, 5, 7, 12, 13, 21, 22, 36, 42, 56};
	// Act
	int a = funkI(x);
	// Assert
	EXPECT_EQ(x, res);
}
TEST(test_I, test2) {
	// Arrange
	std::vector<int> x = { -32, -11, -5, -3, 2, 3, 4, 5, 7, 12, 13, 21, 22, 36, 42, 56 };
	std::vector<int> res = { 56, 42, 36, 22, 21, 13, 12, 7, 5, 4, 3, 2, -3, -5, -11, -32 };
	// Act
	int a = funkI(x);
	// Assert
	EXPECT_EQ(x, res);
}
TEST(test_I, test3) {
	// Arrange
	std::vector<int> x = { -32, -11, -5, -3, 2, 3, 4, 5, 7, 12, 13, 21, 22, 36, 42, 56, 23 };
	std::vector<int> res = { -32, -11, -5, -3, 2, 3, 4, 5, 7, 12, 13, 21, 22, 36, 42, 56 };
	// Act
	int a = funkI(x);
	// Assert
	EXPECT_EQ(x.size(),a);
}
TEST(test_I, test4) {
	// Arrange
	std::vector<int> x = { -32, -11, -5, -3, 2, 3, 4, 5, 7, 12, 13, 21, 22, 36, 42, 56 };
	std::vector<int> res = { 56, 42, 36, 22, 21, 13, 12, 7, 5, 4, 3, 2, -3, -5, -11, -32 };
	// Act
	int a = funkI(x);
	// Assert
	EXPECT_EQ(x.size(), a);
}
TEST(test_J, test1) {
	// Arrange
	std::vector<int> x = { -32, -11, -5, -3, 2, 3, 4, 5, 7, 12, 13, 21, 22, 36, 42, 56 };
	std::vector<int> res = {};
	// Act
	funkJ(x);
	// Assert
	EXPECT_EQ(x, res);
}
TEST(test_AA, test1) {
	// Arrange
	std::list<int> x = { -32, -11, -5, -3, 2, 3, 4, 5, 7, 12, 13, 21, 22, 36, 42, 56 };
	int y[5] = { 11, 13, 5, 3, 7 };
	std::list<int> res = { -32, -11, -5, -3, 2, 3, 4, 5, 7, 12, 13, 21, 22, 36, 42, 56, 11, 13, 5, 3, 7 };
	// Act
	funkAA(x, y, 5);
	// Assert
	EXPECT_EQ(x, res);
}
TEST(test_BB, test1) {
	// Arrange
	std::list<int> x = { -32, -11, -5, -3, 2, 3, 4, 5, 7, 12, 13, 21, 22, 36, 42, 56 };
	std::vector<int> res = { -32, -11, -5, -3, 2};
	// Act
	std::vector<int> a = funkBB(x, 5);
	// Assert
	EXPECT_EQ(a, res);
}
TEST(test_CC, test1) {
	// Arrange
	std::list<int> x = { -32, -11, -5, -3, 2, 3, 4, 5, 7, 12, 13, 21, 22, 36, 42, 56 };
	std::list<int> res = { -32, -11, -5, -3, 2, 4, 5, 7, 12, 13, 21, 22, 36, 42, 56 };
	// Act
	funkCC(x, 5);
	// Assert
	EXPECT_EQ(x, res);
}
TEST(test_DD, test1) {
	// Arrange
	std::list<int> x = { -32, -11, -5, -3, 2, 3, 4, 5, 7, 12, 13, 21, 22, 36, 42, 56 };
	std::list<int> y = { -32, -11, -5, -3, 2, 3, 4, 5, 7, 12, 13, 21, 22, 36, 42, 56 };
	// Act
	funkDD(x);
	auto i = x.begin();
	auto j = y.begin();
	int count = 0;
	while (i != x.end() && j != y.end()) {
		if (*i != *j) {
			count++;
		}
		i++;
		j++;
	}
	// Assert
	EXPECT_EQ(count, 3);
}
TEST(test_EE, test1) {
	// Arrange
	std::list<int> x = { -32, -11, 13, -5, -3, 2, 3, 42, 4, 5, 7, 12, 13, 21, 22, -11, 36, 42, -5, 56 };
	std::list<int> res = { -32, -11, 13, -5, -3, 2, 3, 42, 4, 5, 7, 12, 21, 22, 36, 56 };
	// Act
	funkEE(x);
	// Assert
	EXPECT_EQ(x, res);
}
TEST(test_AAA, test1) {
	// Arrange
	std::list<int> x = { -32, -11, 13, -5, -3, 2, 3, 42, 4, 5, 7, 12, 21, 22, 36, 56 };
	std::list<int> res = { 56, 36, 22, 21, 12, 7, 5, 4, 42, 3, 2, -3, -5, 13, -11, -32};
	// Act
	funkAAA(x);
	// Assert
	EXPECT_EQ(x, res);
}
TEST(test_BBB, test1) {
	// Arrange
	std::list<int> b = { -32, -11, 13, -5, -3, 2, 3, 42, 4, 5, 7, 12, 21, 22, 36, 56 };
	std::stack<int> x;
	for (auto it = b.begin(); it != (b.end()); it++) {
		x.push(*it);
	}
	// Act & Assert
	EXPECT_NO_THROW(funkBBB(x));
}