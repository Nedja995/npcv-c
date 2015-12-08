#include "gtest/gtest.h"

#include "base/core/list.h"
#include "base/core/mathn.h"
//#include "base/core/npstring.h"

//using namespace npcore;

bool listTests() {
	return true;
}



bool readImageT(const char *filepath) {
	return true;
}

bool writeImageT(const char *filepath) {
	return true;
}
TEST(BaseCoreTest, List) {
	EXPECT_EQ(true, readImageT("Fd"));
}
TEST(BaseCoreTest, Core) {
	//list
	EXPECT_EQ(true, readImageT("Fd"));
	//math
	//EXPECT_EQ(3, npcore::sqrtf(9));
	//npstring
//	EXPECT_EQ(5, strnlenN("Proba"));
	//char *strTemp = "Probaa";
	//sprintfN(strTemp, "Proba%i", 1);
//	EXPECT_EQ("Proba1", strTemp);
}