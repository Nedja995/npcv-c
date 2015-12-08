#include "gtest/gtest.h"

#include "base/utils/file_ops.h"

bool readFile(const char *filepath) {
	return true;
}

bool writeFile(const char *filepath) {
	return true;
}

bool readImage(const char *filepath) {
	return true;
}

bool writeImage(const char *filepath) {
	return true;
}

TEST(BaseUtilsTest, Utils) {
	const char *fileIn = "";
	const char *fileOut = "";
	const char *imageIn = "";
	const char *imageOut = "";
	EXPECT_EQ(true, readFile(fileIn));
	EXPECT_EQ(true, writeFile(fileOut));
	EXPECT_EQ(true, readImage(imageIn));
	EXPECT_EQ(true, writeImage(imageOut));
}