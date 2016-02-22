#include "base\core\npstdlib.h"
#include "nputils.h"

int npcu_test_file();
int npcu_test_image();
int npcu_test_path();

int main(int argc, char** argv)
{
	NConsolePrint("\n====================\nNPC Utils Main Test\n=================\n");
	npcu_test_file();
	NConsolePrint("\n====================\nNPC Utils Main Test Finished\n=================\n");
	return 0;
}

int npcu_test_file()
{
	file_write("file.txt", "fsdfsdfsdf");
	return 0;
}
int npcu_test_image()
{
	return 0;
}
int npcu_test_path()
{
	return 0;
}