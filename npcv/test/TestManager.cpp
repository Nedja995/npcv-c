#ifndef __NPCV_TEST_MANAGER_H__
#define __NPCV_TEST_MANAGER_H__

#include <iostream>

#include "../src/core/Image.h"
#include "../src/utils/ImageStream.h"
#include "../src/imageproc/imageproc_gray.h"
#include "../src/imageproc/edge_detection.h"
#include "../src/classification/image_classification.h"
#include "../src/utils/file_ops.h"
#include "../src/classification/classification_image_utils.h"
#include "../src/core/npstdlib/list.h"

#include "DataTest.h"

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
	npcore::Image * img = nputils::ImageStream::ReadImage_STB(imageReadWrite_input);

	nputils::ImageStream::WriteImage_STB(img, imageReadWrite_output);

	return true;
}

bool ImageSubarea_Test()
{
	npcore::Image * img = nputils::ImageStream::ReadImage_STB(imageSubarea_input);

	npcore::Image * small = npcore::image_get_area(img, 110, 110, img->width /2, img->height /2);

	nputils::ImageStream::WriteImage_STB(small, imageSubarea_output);

	return true;
}








bool ImageProc_Gray_Test()
{
	npcore::Image * img = nputils::ImageStream::ReadImage_STB(imageGray_input);

	npip::gray(img);

	nputils::ImageStream::WriteImage_STB(img, imageGray_output);

	return true;
}

bool ImageProc_EdgeDetection_Test()
{
	npcore::Image * img = nputils::ImageStream::ReadImage_STB(edgeDetection_input);

	//npcore::Image * img2 = (npcore::Image *)duplicateN(img, sizeof(img));
	//npcore::Image * img3 = (npcore::Image *)duplicateN(img, sizeof(img));
	//npcore::Image * img4 = (npcore::Image *)duplicateN(img, sizeof(img));
	//npcore::Image * img5 = (npcore::Image *)duplicateN(img, sizeof(img));
	//npcore::Image * img6 = (npcore::Image *)duplicateN(img, sizeof(img));
	//npcore::Image * img7 = (npcore::Image *)duplicateN(img, sizeof(img));
	//npcore::Image * img8 = (npcore::Image *)duplicateN(img, sizeof(img));
	//npcore::Image * img9 = (npcore::Image *)duplicateN(img, sizeof(img));
	//npcore::Image * img10 = (npcore::Image *)duplicateN(img, sizeof(img));
	//npcore::Image * img11 = (npcore::Image *)duplicateN(img, sizeof(img));
	//npcore::Image * img12 = (npcore::Image *)duplicateN(img, sizeof(img));
	//npcore::Image * img13 = (npcore::Image *)duplicateN(img, sizeof(img));
	//npcore::Image * img14 = (npcore::Image *)duplicateN(img, sizeof(img));
	//npcore::Image * img15 = (npcore::Image *)duplicateN(img, sizeof(img));


	npip::contour_draw_custom(img, 1, 20);
	//npcore::imgproc::contour_draw_custom(img2);
	//npcore::imgproc::contour_draw_custom(img3);
	//npcore::imgproc::contour_draw_custom(img4);
	//npcore::imgproc::contour_draw_custom(img5);
	//npcore::imgproc::contour_draw_custom(img6);
	//npcore::imgproc::contour_draw_custom(img7);
	//npcore::imgproc::contour_draw_custom(img8);
	//npcore::imgproc::contour_draw_custom(img9);
	//npcore::imgproc::contour_draw_custom(img10);
	//npcore::imgproc::contour_draw_custom(img11);
	//npcore::imgproc::contour_draw_custom(img12);
	//npcore::imgproc::contour_draw_custom(img13);
	//npcore::imgproc::contour_draw_custom(img14);
	//npcore::imgproc::contour_draw_custom(img15);

	nputils::ImageStream::WriteImage_STB(img, edgeDetection_output);

	return true;
}

bool ClassifyOcr_Test()
{
	npcore::Image *img = nputils::ImageStream::ReadImage_STB(classifyOcr_input);
	npcore::Image *subimage = 0;
	npcore::Image *subImageEdges = NULL;
	npcf::ImageClassificationData *icdTemp = 0;
	npcore::List *classes = npcore::list_create();

	int subimageSize = 20;

	int si = 0;
	for (int x = 0; x < 2000 - 20; x += 20)
	{
		for (int y = 700; y < 800; y += 20)
		{
			subimage = npcore::image_get_area(img, x, y, subimageSize, subimageSize);

			icdTemp = npcf::image_classify(subimage, 12);
			if (icdTemp == NULL)
				continue;
			npcore::list_put(classes, icdTemp);
			si++;
		}
	}

	//npcore::ImageClassificationData * icd = npcore::image_classify(subimage, 9);
//	npcf::csv_write_image_classifier(i)
//	nputils::csv_write_image_classifiers(classes, fileWrite_output);

	/*for (int i = 0; i < icd->regionCount; i++)
	{
		std::cout << "reg: " << i << " : " << npcore::image_classify_region_get(icd, i) << std::endl;
	}*/

//	npcore::Image * small = npcore::image_get_area(img, 0, 400, 20, 20);

	//npcore::ImageStream::WriteImage_STB(subimage, classifyOcr_output);

	return true;
}

bool FileWrite_Test()
{
	return nputils::file_write(fileWrite_output, fileWrite_input);
}


int main(int argc, char** argv)
{
	std::cout << "===== NPCV TestManger started=====" << std::endl;

	NPCVTests testChoosed = ImageReadWrite;

	std::string input;

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


		//system("pause");
		return 0;

}



#endif
