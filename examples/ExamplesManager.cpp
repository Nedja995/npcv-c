#ifndef __NPCV_EXAMPLES_MANAGER__
#define __NPCV_EXAMPLES_MANAGER__

#include "ExamplesDatas.h"

#include "base/core/npstdlib.h"
#include "base/imageproc/npimageproc.h"
#include "base/imageproc/imageproc_gray.h"
#include "base/classification/classification_image_utils.h"
#include "base/classification/image_classification.h"

enum NPCVTests
{
	ALL,
	LIST,
	TIME,
	FILE_W,
	IMAGE_RW,
	GRAY,
	GRAY2,
	SUBIMAGE,
	EDGES,
	CLASSIFYOCR
};

int List_Example()
{
	NConsolePrint("\nstart List\n");
	List *list = list_create();
	//list_put(list, "static str");
	//list_put(list, "static string");
	//list_put(list, "statString");
	list_put(list, strmakeN("DynString"));
	list_put(list, strmakeN("DynamicS"));
	list_put(list, strmakeN("String dyn"));

	//print them
	NConsolePrint("\n");
	LIST_FOREACH(list)
	{
		NConsolePrint("%s\n", (char *)link->data);
	}

	list_free_custom(list, freeN); /* with passed callback for free element */
	//list_free(list); /* clear only list. for list with static elements */

	NConsolePrint("finish List\n\n");
	return 0;
}

int Time_Example()
{
	NConsolePrint("\nstart Time\n");	
	
	NTime *nt = time_get_allocN();
	
	if (nt == NULL) {
		NConsolePrint("Time struct getting error !");
		return -1;
	}
			
	NConsolePrint("\nTime successfuly used: %02d_%02d_%02d_%02d-%02d-%02d\n", nt->year, nt->month, nt->day, nt->hour, nt->minute, nt->second);
	
	freeN(nt);
	
	NConsolePrint("finish Time\n\n");
	return 0;
}

int FileWrite_Example()
{
	char *output = Examples::getPath_alloc(fileWriteOutput);

	if (file_write(output, fileWriteInput) == -1) {
		NConsolePrint("\nFile Writing failed !");
		freeN(output);
		return -1;
	}
	freeN(output);
	return 0;
}

int ImageReadWrite_Example()
{
	char *input = Examples::getPath_alloc(lenaInput);
	char *output = Examples::getPath_alloc(writeOutput);
	Image * img = ReadImage_STB(input);
	
	freeN(input);
	
	if (img == NULL) {
		NConsolePrint("\nEdge Image Read Write failed! input image not found!");
		return -1;
	}

	WriteImage_STB(img, output);
	
	free_image(img);
	freeN(output);
	return 0;
}

int ImageGray_Example()
{
	char *input = Examples::getPath_alloc(lenaInput);
	char *output = Examples::getPath_alloc(grayOutput);

	Image * img = ReadImage_STB(input);
	
	freeN(input);
	
	if (img == NULL) {
		NConsolePrint("\nGray failed! input image not found!");
		return -1;
	}

	np_gray_simple(img);
	WriteImage_STB(img, output);

	free_image(img);
	freeN(output);

	return 0;
}

int ImageGray2_Example()
{
	char *input = Examples::getPath_alloc(gray2input);
	char *output = Examples::getPath_alloc(gray2Output);

	Image * img = ReadImage_STB(input);

	freeN(input);

	if (img == NULL) {
		NConsolePrint("\nGray failed! input image not found!");
		return -1;
	}

	np_gray_matrix(img);
	WriteImage_STB(img, output);

	free_image(img);
	freeN(output);

	return 0;
}

int Subarea_Example()
{
	char *input = Examples::getPath_alloc(lenaInput);
	char *output = Examples::getPath_alloc(subareaOutput);

	Image * img = ReadImage_STB(input);
	if (img == NULL) {
		NConsolePrint("\n Subarea failed! input image not found!");
		return -1;
	}

	Image * small = image_get_area(img, img->width / 4, img->height / 4,
		img->width / 2, img->height / 2);

	WriteImage_STB(small, output);
	
	freeN(input);
	freeN(output);
	free_image(img);
	free_image(small);

	return 0;
}

int EdgeDetection_Examples()
{
	char *input = Examples::getPath_alloc(lenaInput);
	char *output = Examples::getPath_alloc(edgeDetectionOutput);

	Image * img = ReadImage_STB(input);

	if (img == NULL) {
		NConsolePrint("\nDetection failed! input image not found!");
		return -1;
	}

	contour_draw_custom(img, 1, 20);
	WriteImage_STB(img, output);

	freeN(input);
	freeN(output);
	free_image(img);

	return 0;
}

void free_l(void *icd)
{
	free_image_classification_data((ImageClassificationData*)icd);
}

int ClassifyOcrSamples_Example()
{
	char *input = Examples::getPath_alloc(ocrSamples);
	char *output = Examples::getPath_alloc(ocrSamplesOutput);


	Image *img = ReadImage_STB(input);
	if (img == NULL) {
		NConsolePrint("\nClassify OCR Samples failed! input image not found!");
		return -1;
	}
	Image *subimage = 0;
	Image *subImageEdges = NULL;
	ImageClassificationData *icdTemp = 0;
	List *classes = list_create();

	int si = 0;
	for (int x = 0; x < 2000 - 20; x += 20)
	{
		for (int y = 700; y < 800; y += 20)
		{
			subimage = image_get_area(img, x, y, ocrSubimageSize, ocrSubimageSize);

			icdTemp = image_classify(subimage, 12);
			
			free_image(subimage);
			
			if (icdTemp == NULL)
				continue;
			list_put(classes, icdTemp);
			
			//free_image_classification_data(icdTemp);
			si++;
		}
	}

	char *csvContent = datas_get_format_csv(classes);

	file_write(output, csvContent);

	freeN(csvContent);
	//list_free_default(classes, free_l);
	
	list_free_custom(classes, free_l);
	
	freeN(input);
	freeN(output);
	free_image(img);

	return 0;
}

void printMainMessage() {
	NConsolePrint("\n\n===== NPCV ExamplesManger =====\n\n");
	NConsolePrint("available inputs are (type parametars or leave it with default params):\n\n");
	NConsolePrint(" all run all with example datas\n\n");
	NConsolePrint(" list\n\n");
	NConsolePrint(" time\n\n");
	NConsolePrint(" filewrite output_path\n\n");
	NConsolePrint(" imagereadwrite input_image output_image\n\n");
	NConsolePrint(" gray input_image output_path\n\n");
	NConsolePrint(" gray2 input_image output_path\n\n");
	NConsolePrint(" subimage input_image output_image x y width height\n\n");
	NConsolePrint(" edges input_path output_path resolution sensitivity\n\n");
	NConsolePrint(" csfocr input_image output_file sample_size regions\n\n");
}

int main(int argc, char** argv)
{	
	NPCORE_initialize();

	NPCVTests testChoosed = ALL;
	char *input = strmakeN("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");

	while (stringCompare(input, "quit") != 0)
	{
		//
		// MAIN LOOP
		printMainMessage();

		//get input
		NConsoleInput("%s", input);

		//TODO: move this to function
		//choose example
		if (stringContains(input, "all") != NULL)
			testChoosed = ALL;
		else if (stringContains(input, "list") != NULL)
			testChoosed = LIST;
		else if (stringContains(input, "time") != NULL)
			testChoosed = TIME;
		else if (stringContains(input, "filewrite") != NULL)
			testChoosed = FILE_W;
		else if (stringContains(input, "imagereadwrite") != NULL)
			testChoosed = IMAGE_RW;
		else if (stringContains(input, "gray2") != NULL)
			testChoosed = GRAY2;
		else if (stringContains(input, "gray") != NULL)
			testChoosed = GRAY;
		else if (stringContains(input, "subimage") != NULL)
			testChoosed = SUBIMAGE;
		else if (stringContains(input, "edges") != NULL)
			testChoosed = EDGES;
		else if (stringContains(input, "csfocr") != NULL)
			testChoosed = CLASSIFYOCR;
		else {
			NConsolePrint("\nWrong command..");
			continue;
		}

		//process
		if (testChoosed == ALL) {
			List_Example();
			List_Example();
			Time_Example();
			Time_Example();
			FileWrite_Example();
			FileWrite_Example();
			ImageReadWrite_Example();
			ImageReadWrite_Example();
			ImageGray_Example();
			ImageGray_Example();
			ImageGray2_Example();
			ImageGray2_Example();
			Subarea_Example();
			Subarea_Example();
			EdgeDetection_Examples();
			EdgeDetection_Examples();
			ClassifyOcrSamples_Example();
			ClassifyOcrSamples_Example();
		}
		else if (testChoosed == LIST) {
			List_Example();
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
		else if (testChoosed == GRAY2) {
			ImageGray2_Example();

		}
		else if (testChoosed == SUBIMAGE) {
			Subarea_Example();

		}
		else if (testChoosed == EDGES) {
			EdgeDetection_Examples();

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
