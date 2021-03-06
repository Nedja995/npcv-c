#ifndef __NPCV_TEST_MANAGER_H__
#define __NPCV_TEST_MANAGER_H__

//#include <varargs.h>
//#if defined _MSC_VER && _NP_DEBUG && _NP_NP_DEBUG_VLD
//#include "vld.h"
//#endif

//#include "core/Image.h"
#include "utils/ImageStream.h"
#include "imageproc/imageproc_gray.h"
#include "imageproc/edge_detection.h"
//#include "classification/image_classification.h"
#include "utils/file_ops.h"
#include "classification/classification_image_utils.h"
//#include "core/list.h"
#include "core/npio.h"
//#include "core/npstring.h"
#include "core/memory.h"
#include "core/debug.h"
#include "DataTest.h"



using namespace npcore;

#ifdef WITH_GTEST
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

TEST(FactorialTest, Positive) {
	EXPECT_EQ(4, saberi(2, 2));
	EXPECT_EQ(0, oduzmi(2, 2));
	EXPECT_EQ(6, pomnozi(2, 3));
	EXPECT_EQ(4, podeli(8, 2));
}

GTEST_API_ int main(int argc, char **argv) {
	printf("Running main() from gtest_main.cc\n");
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

#else
enum NPCVTests
{
	ALL,
	FILE_W,
	IMAGE_RW,
	GRAY,
	SUBIMAGE,
	EDGES,
	CLASSIFYOCR
};


bool FileWrite_Example()
{
	char *output = Examples::getPath_alloc(fileWriteOutput);

	if (nputils::file_write(output, fileWriteInput) == false) {
		NConsolePrint("\nFile Writing failed !");
		return false;
	}
}

bool ImageReadWrite_Example()
{
	char *input = Examples::getPath_alloc(lenaInput);
	char *output = Examples::getPath_alloc(writeOutput);
	Image * img = nputils::ImageStream::ReadImage_STB(input);
	if (img == NULL) {
		NConsolePrint("\nEdge Image Read Write failed! input image not found!");
		return false;
	}

	nputils::ImageStream::WriteImage_STB(img, output);

	return true;
}

bool ImageGray_Example()
{
	char *input = Examples::getPath_alloc(lenaInput);
	char *output = Examples::getPath_alloc(grayOutput);

	Image * img = nputils::ImageStream::ReadImage_STB(input);
	if (img == NULL) {
		NConsolePrint("\nGray failed! input image not found!");
		return false;
	}

	npip::gray(img);
	nputils::ImageStream::WriteImage_STB(img, output);


	return true;
}

bool Subarea_Example()
{
	char *input = Examples::getPath_alloc(lenaInput);
	char *output = Examples::getPath_alloc(subareaOutput);

	Image * img = nputils::ImageStream::ReadImage_STB(input);
	if (img == NULL) {
		NConsolePrint("\n Subarea failed! input image not found!");
		return false;
	}

	Image * small = image_get_area(img, img->width / 4, img->height / 4,
		img->width / 2, img->height / 2);

	nputils::ImageStream::WriteImage_STB(small, output);

	return true;
}

bool EdgeDetection_Examples()
{
	char *input = Examples::getPath_alloc(lenaInput);
	char *output = Examples::getPath_alloc(edgeDetectionOutput);

	Image * img = nputils::ImageStream::ReadImage_STB(input);

	if (img == NULL) {
		NConsolePrint("\nDetection failed! input image not found!");
		return false;
	}

	npip::contour_draw_custom(img, 1, 20);
	nputils::ImageStream::WriteImage_STB(img, output);

	return true;
}

bool ClassifyOcrSamples_Example()
{
	char *input = Examples::getPath_alloc(ocrSamples);
	char *output = Examples::getPath_alloc(ocrSamplesOutput);


	Image *img = nputils::ImageStream::ReadImage_STB(input);
	if (img == NULL) {
		NConsolePrint("\nClassify OCR Samples failed! input image not found!");
		return false;
	}
	Image *subimage = 0;
	Image *subImageEdges = NULL;
	npcf::ImageClassificationData *icdTemp = 0;
	List *classes = list_create();

	int si = 0;
	for (int x = 0; x < 2000 - 20; x += 20)
	{
		for (int y = 700; y < 800; y += 20)
		{
			subimage = image_get_area(img, x, y, ocrSubimageSize, ocrSubimageSize);

			icdTemp = npcf::image_classify(subimage, 12);
			if (icdTemp == NULL)
				continue;
			list_put(classes, icdTemp);
			si++;
		}
	}

	char *csvContent = npcf::datas_get_format_csv(classes);

	nputils::file_write(output, csvContent);

	return true;
}

void printMainMessage() {
	NConsolePrint("\n\n===== NPCV ExamplesManger =====\n\n");
	NConsolePrint("available inputs are (type parametars or leave it with default params):\n\n");
	NConsolePrint(" all\n\n");
	NConsolePrint(" filewrite output_path\n\n");
	NConsolePrint(" imagereadwrite input_image output_image\n\n");
	NConsolePrint(" gray input_image output_path\n\n");
	NConsolePrint(" subimage input_image output_image x y width height\n\n");
	NConsolePrint(" edges input_path output_path resolution sensitivity\n\n");
	NConsolePrint(" csfocr input_image output_file sample_size regions\n\n");
}

//
//TODO: solution for unknown input arguments number
//
// for now without custom arguments
//
int main2(int argc, char** argv)
{
	NPCVTests testChoosed = ALL;
	char *input = (char*)mallocN(sizeof(char) * 256);
	//*(input + 256) = '\0';
	//
	debug_initialize();

	while (strncmp(input, "quit", 5) != 0)
	{
		//
		// MAIN LOOP
		printMainMessage();

		//get input
		scanf("%s", input);

		//TODO: move this to function
		//choose example
		if (strstr(input, "all") != NULL)
			testChoosed = ALL;
		else if (strstr(input, "filewrite") != NULL)
			testChoosed = FILE_W;
		else if (strstr(input, "imagereadwrite") != NULL)
			testChoosed = IMAGE_RW;
		else if (strstr(input, "gray") != NULL)
			testChoosed = GRAY;
		else if (strstr(input, "subimage") != NULL)
			testChoosed = SUBIMAGE;
		else if (strstr(input, "edges") != NULL)
			testChoosed = EDGES;
		else if (strstr(input, "csfocr") != NULL)
			testChoosed = CLASSIFYOCR;
		else {
			NConsolePrint("\nWrong command..");
			continue;
		}

		//process
		if (testChoosed == ALL) {
			NConsolePrint("\nstart FileWrite\n");
			FileWrite_Example();
			NConsolePrint("stop FileWrite\n\n");

			NConsolePrint("start ImageReadWrite\n");
			ImageReadWrite_Example();
			NConsolePrint("stop ImageReadWrite\n\n");

			NConsolePrint("start Gray\n");
			ImageGray_Example();
			NConsolePrint("stop Gray\n\n");

			NConsolePrint("start Subarea\n");
			Subarea_Example();
			NConsolePrint("stop Subarea\n\n");

			NConsolePrint("start Edges\n");
			EdgeDetection_Examples();
			NConsolePrint("stop FileWrite\n\n");

			NConsolePrint("start Classify OCR samples\n");
			ClassifyOcrSamples_Example();
			NConsolePrint("stop Classify OCR samples\n");
		}
		else if (testChoosed == FILE_W) {
			FileWrite_Example();
		}
		else if (testChoosed == IMAGE_RW) {
			ImageReadWrite_Example();
		}
		else if (testChoosed == GRAY) {
			ImageGray_Example();
		}
		else if (testChoosed == SUBIMAGE) {
			Subarea_Example();
		}
		else if (testChoosed == EDGES) {
			FileWrite_Example();
		}
		else if (testChoosed == CLASSIFYOCR) {
			ClassifyOcrSamples_Example();
		}

	}

	debug_exit();

	//system("pause");

	return 0;

}

#endif


#endif
