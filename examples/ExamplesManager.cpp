#ifndef __NPCV_EXAMPLES_MANAGER__
#define __NPCV_EXAMPLES_MANAGER__

//#include <varargs.h>
//#if defined _MSC_VER && _NP_DEBUG && _NP_NP_DEBUG_VLD
//#include "vld.h"
//#endif

//#include "base/core/Image.h"
#include "base/utils/ImageStream.h"
#include "base/imageproc/imageproc_gray.h"
#include "base/imageproc/edge_detection.h"
//#include "classification/image_classification.h"
#include "base/utils/file_ops.h"
#include "base/classification/classification_image_utils.h"
//#include "base/core/list.h"
#include "base/core/npio.h"
//#include "base/core/npstring.h"
#include "base/core/memory.h"
#include "base/core/debug.h"
#include "ExamplesDatas.h"

#include "base/core/npstdlib.h"

using namespace npcore;

enum NPCVTests
{
	ALL,
	TIME,
	FILE_W,
	IMAGE_RW,
	GRAY,
	SUBIMAGE,
	EDGES,
	CLASSIFYOCR
};

bool Time_Example()
{
	NConsolePrint("\nstart Time\n");	
	
	NTime *nt = time_get_allocN();
	
	if (nt == NULL) {
		NConsolePrint("Time struct getting error !");
		return false;
	}
	
	NConsolePrint("\nTime successfuly used: %02d_%02d_%02d_%02d-%02d-%02d\n", nt->year, nt->month, nt->day, nt->hour, nt->minute, nt->second);
	
	freeN(nt);
	
	NConsolePrint("finish Time\n\n");
	return true;
}

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
	NConsolePrint(" all run all with example datas\n\n");
	NConsolePrint("time\n\n");
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
#	include <time.h>
int main2(int argc, char** argv)
{

	
/*	NTime *ret = (NTime*)mallocN(sizeof(NTime));
		
		time_t curtime;
		struct tm *loctime;

		//Get the current time. 
		curtime = time(NULL);

		// Convert it to local time representation. 
		loctime = localtime(&curtime);

	NConsolePrint("now: %d-%d-%d %d:%d:%d\n", loctime->tm_year + 1900, loctime->tm_mon + 1, loctime->tm_mday, loctime->tm_hour, loctime->tm_min, loctime->tm_min);



		ret->day = loctime->tm_mday;
		ret->hour = loctime->tm_hour;
		ret->milisecond = 0;
		ret->minute = loctime->tm_min;
		ret->month = loctime->tm_mon;
		ret->second = loctime->tm_sec;
		ret->year = 1900 + loctime->tm_year;
		
		//freeN(loctime);

	freeN(ret);*/
	
	
	
	return 0;
}

int main(int argc, char** argv)
{
	
	NPCORE_initialize();

	NPCVTests testChoosed = ALL;
	char *input = strmakeN("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
	//*(input + 256) = '\0';
	//


	while (strncmp(input, "quit", 50) != 0)
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
		else if (strstr(input, "time") != NULL)
			testChoosed = TIME;
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

			Time_Example();
		


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
		else if (testChoosed == TIME) {
			Time_Example();
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

	freeN(input);

	//system("pause");
	NPCORE_exit();

	return 1;

}


#endif
