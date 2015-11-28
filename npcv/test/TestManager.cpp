#ifndef __NPCV_TEST_MANAGER_H__
#define __NPCV_TEST_MANAGER_H__

#include <iostream>

#if defined _MSC_VER && DEBUG
#include "vld.h"
#endif

#include "../src/core/Image.h"
#include "../src/utils/ImageStream.h"
#include "../src/imageproc/imageproc_gray.h"
#include "../src/imageproc/edge_detection.h"
#include "../src/classification/image_classification.h"
#include "../src/utils/file_ops.h"
#include "../src/classification/classification_image_utils.h"
#include "../src/core/npstdlib/list.h"
#include "../src/core/npstdlib/npio.h"
#include "../src/core/npstdlib/npstring.h"
#include "../src/core/npstdlib/memory.h"
#include "../src/core/npstdlib/debug.h"
#include "DataTest.h"

using namespace npcore;

enum NPCVTests
{
	ImageReadWrite,
	GrayImage,
	EdgeDetection,
	ImageSubarea,
	ClassifyOcr,
	FileWrite
};


bool ImageReadWrite_Test()
{
	/*Log("Test Started: ImageReadWrite\n", TRACE);
	Log("input path: "); Log(imageReadWrite_input); Log("\n");
	Log("output path: "); Log(imageReadWrite_output); Log("\n");*/

	Image * img = nputils::ImageStream::ReadImage_STB(imageReadWrite_input);
    if(img == NULL){
        Log("Test Failed !", ERROR);
        return false;
    }

	IMAGE_FOREACH(img)
		if(x == 0 || x == 300)
			NTrace(pixel_string_alloc(pixel));
		END_ITER_Y
			if (x == 0 || x == 300)
			NTrace("\n");
	END_FOREACH2



	nputils::ImageStream::WriteImage_STB(img, imageReadWrite_output);

	return true;
}

bool ImageSubarea_Test()
{
	Image * img = nputils::ImageStream::ReadImage_STB(imageSubarea_input);

	Image * small = image_get_area(img, 110, 110, img->width /2, img->height /2);

	nputils::ImageStream::WriteImage_STB(small, imageSubarea_output);

	return true;
}








bool ImageProc_Gray_Test()
{
	Image * img = nputils::ImageStream::ReadImage_STB(imageGray_input);

	npip::gray(img);

	nputils::ImageStream::WriteImage_STB(img, imageGray_output);

	return true;
}

bool ImageProc_EdgeDetection_Test()
{
	Image * img = nputils::ImageStream::ReadImage_STB(edgeDetection_input);

	//Image * img2 = (Image *)duplicateN(img, sizeof(img));
	//Image * img3 = (Image *)duplicateN(img, sizeof(img));
	//Image * img4 = (Image *)duplicateN(img, sizeof(img));
	//Image * img5 = (Image *)duplicateN(img, sizeof(img));
	//Image * img6 = (Image *)duplicateN(img, sizeof(img));
	//Image * img7 = (Image *)duplicateN(img, sizeof(img));
	//Image * img8 = (Image *)duplicateN(img, sizeof(img));
	//Image * img9 = (Image *)duplicateN(img, sizeof(img));
	//Image * img10 = (Image *)duplicateN(img, sizeof(img));
	//Image * img11 = (Image *)duplicateN(img, sizeof(img));
	//Image * img12 = (Image *)duplicateN(img, sizeof(img));
	//Image * img13 = (Image *)duplicateN(img, sizeof(img));
	//Image * img14 = (Image *)duplicateN(img, sizeof(img));
	//Image * img15 = (Image *)duplicateN(img, sizeof(img));


	npip::contour_draw_custom(img, 1, 20);
	//imgproc::contour_draw_custom(img2);
	//imgproc::contour_draw_custom(img3);
	//imgproc::contour_draw_custom(img4);
	//imgproc::contour_draw_custom(img5);
	//imgproc::contour_draw_custom(img6);
	//imgproc::contour_draw_custom(img7);
	//imgproc::contour_draw_custom(img8);
	//imgproc::contour_draw_custom(img9);
	//imgproc::contour_draw_custom(img10);
	//imgproc::contour_draw_custom(img11);
	//imgproc::contour_draw_custom(img12);
	//imgproc::contour_draw_custom(img13);
	//imgproc::contour_draw_custom(img14);
	//imgproc::contour_draw_custom(img15);

	nputils::ImageStream::WriteImage_STB(img, edgeDetection_output);

	return true;
}

bool ClassifyOcr_Test()
{
	Image *img = nputils::ImageStream::ReadImage_STB(classifyOcr_input);
	Image *subimage = 0;
	Image *subImageEdges = NULL;
	npcf::ImageClassificationData *icdTemp = 0;
	List *classes = list_create();

	int subimageSize = 20;

	int si = 0;
	for (int x = 0; x < 2000 - 20; x += 20)
	{
		for (int y = 700; y < 800; y += 20)
		{
			subimage = image_get_area(img, x, y, subimageSize, subimageSize);

			icdTemp = npcf::image_classify(subimage, 12);
			if (icdTemp == NULL)
				continue;
			list_put(classes, icdTemp);
			si++;
		}
	}

	//ImageClassificationData * icd = image_classify(subimage, 9);
//	npcf::csv_write_image_classifier(i)
//	nputils::csv_write_image_classifiers(classes, fileWrite_output);

	/*for (int i = 0; i < icd->regionCount; i++)
	{
		std::cout << "reg: " << i << " : " << image_classify_region_get(icd, i) << std::endl;
	}*/

//	Image * small = image_get_area(img, 0, 400, 20, 20);

	//ImageStream::WriteImage_STB(subimage, classifyOcr_output);

	return true;
}

bool FileWrite_Test()
{
	return nputils::file_write(fileWrite_output, fileWrite_input);
}


int main(int argc, char** argv)
{
	std::cout << "===== NPCV TestManger started=====" << std::endl << std::endl<< std::endl<< std::endl;

	NPCVTests testChoosed = ImageReadWrite;

	std::string input;

	debug_initialize();
//	dbg_default_TraceFile = (char*)logPath;

	char *leak = (char*)mallocN(2000);
	leak = NULL;
	if (argc == 2)
	{
		input = argv[1];
		if (input == "ImageRW")
		{
			testChoosed = ImageReadWrite;
		}
		if (input == "Gray")
		{
			testChoosed = GrayImage;
		}
		if (input == "Edge")
		{
			testChoosed = EdgeDetection;
		}
	}
		if (testChoosed == ImageReadWrite)
		{
			ImageReadWrite_Test();
		}
		else if (testChoosed == GrayImage)
		{
			ImageProc_Gray_Test();
		}
		else if (testChoosed == ImageSubarea)
		{
			ImageSubarea_Test();
		}
		else if (testChoosed == ClassifyOcr)
		{
			ClassifyOcr_Test();
		}
		else if (testChoosed == FileWrite)
		{
			FileWrite_Test();
		}
		else if (testChoosed == EdgeDetection)
		{
			int a = 3;
			ImageProc_EdgeDetection_Test();
			a = 4;
		}
		else
		{
			std::cout << "Test don't exists" << std::endl;
		}
		std::cout << std::endl << std::endl;
		debug_exit();
		//system("pause");
		return 0;

}



#endif
