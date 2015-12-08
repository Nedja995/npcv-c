#include "gtest/gtest.h"

int saberi(int a, int  b) {
	return a + b;
}

int oduzmi(int a, int b) {
	return a - b;
}

int pomnozi(int a, int b) {
	return a + b;
}

int podeli(int a, int b) {
	return a / b;
}

TEST(BaseTest, Core) {
	EXPECT_EQ(4, saberi(2, 2));
	EXPECT_EQ(0, oduzmi(2, 2));
	EXPECT_EQ(6, pomnozi(2, 3));
	EXPECT_EQ(4, podeli(8, 2));
}
