#ifndef __NPCV_DATA_TEST_H__
#define __NPCV_DATA_TEST_H__

#include "core\npstring.h"
#include "utils\path_utils.h"

#define STB_IMAGE_IMPLEMENTATION
const char* fileWrite_input = "1,4\n2,0\n3,7\0";

const char *logPath = "logs/log.txt";

//Absolout path to SamplesDatas and TestOutput directory
#if defined _MSC_VER
char *sampleRoot = "D:\\Projects\\ComputerVision\\ComputerVision\\npcv\\test";
//relative inputs
char *lenaInput = "\\Datas\\SampleDatas\\lena.jpg";
//relative ouput
char *writeOutput = "\\Datas\\TestOutput\\imgWrite.jpg";
char *subareaOutput = "\\Datas\\TestOutput\\subarea.jpg";
#else
char *sampleRoot = "/home/ubuntudev/Desktop/Projects/ComputerVision/npcv/test/Datas";
//relative inputs
char *lenaInput = "/SampleDatas/lena.jpg";
//relative ouput
char *writeOutput = "/TestOutput/imgWrite.jpg";
char *subareaOutput = "/TestOutput/subarea.jpg";
#endif

class Examples {
public:
	static char *getPath_alloc(const char *filepath) {
		char *ret = (char*)mallocN(sizeof(char) * 1000);
		npcore::sprintfN(ret, "%s%s", sampleRoot, filepath);
//#if defined __linux__
		//nputils::path_to_linux(ret);
//#endif
		return ret;
	}
};


#if defined _MSC_VER
	const char * projectPath = "D:\\Projects\\ComputerVision\\ComputerVision\\npcv\\test\\";

	const char* imageReadWrite_input = "D:\\Projects\\ComputerVision\\ComputerVision\\npcv\\test\\Datas\\SampleDatas\\lena.jpg";
	const char* imageReadWrite_output = "D:\\Projects\\ComputerVision\\ComputerVision\\npcv\\test\\Datas\\TestOutput\\lenaRW.png";

	const char* imageSubarea_input = "D:\\Projects\\ComputerVision\\ComputerVision\\npcv\\test\\Datas\\SampleDatas\\lena.jpg";
	const char* imageSubarea_output = "D:\\Projects\\ComputerVision\\ComputerVision\\npcv\\test\\Datas\\TestOutput\\lenaSubarea.png";

	const char* imageGray_input = "D:\\Projects\\ComputerVision\\ComputerVision\\npcv\\test\\Datas\\SampleDatas\\lena.jpg";
	const char* imageGray_output = "D:\\Projects\\ComputerVision\\ComputerVision\\npcv\\test\\Datas\\TestOutput\\lenaGray.png";

	const char* edgeDetection_input = "D:\\Projects\\ComputerVision\\ComputerVision\\npcv\\test\\Datas\\SampleDatas\\digitsSmall.jpg";
	const char* edgeDetection_output = "D:\\Projects\\ComputerVision\\ComputerVision\\npcv\\test\\Datas\\TestOutput\\digitsSmallEdgeDetect.png";

	const char* classifyOcr_input = "D:\\Projects\\ComputerVision\\ComputerVision\\npcv\\test\\Datas\\SampleDatas\\digits.png";
	const char* classifyOcr_output = "D:\\Projects\\ComputerVision\\ComputerVision\\npcv\\test\\Datas\\TestOutput\\digits.png";


	const char* fileWrite_output = "D:\\Projects\\ComputerVision\\ComputerVision\\npcv\\test\\Datas\\TestOutput\\fileProba.csv";

#elif __linux__

	const char * projectPath = "/home/ubuntudev/Desktop/Projects/ComputerVision/npcv/test/Datas";

	const char* imageReadWrite_input = "/home/ubuntudev/Desktop/Projects/ComputerVision/npcv/test/Datas/SampleDatas/lena.jpg";
	const char* imageReadWrite_output = "/home/ubuntudev/Desktop/Projects/ComputerVision/npcv/test/Datas/OutputDatas/lenaRW.png";

	const char* imageSubarea_input = "/home/nedja/ComputerVisionGit/npcv/test/Datas/SampleDatas/lena.jpg";
	const char* imageSubarea_output = "/home/nedja/ComputerVisionGit/npcvt/test/Datas/TestOutput/lenaSubarea.png";

	const char* imageGray_input = "/home/nedja/ComputerVisionGit/npcv/test/Datas/SampleDatas/lena.jpg";
	const char* imageGray_output = "/home/nedja/ComputerVisionGit/npcv/test/Datas/TestOutput/lenaGray.png";

	const char* edgeDetection_input = "/home/nedja/ComputerVisionGit/npcv/test/Datas/SampleDatas/digitsSmall.jpg";
	const char* edgeDetection_output = "/home/nedja/ComputerVisionGit/npcv/test/Datas/TestOutput/digitsSmallEdgeDetect.png";

	const char* classifyOcr_input = "/home/nedja/ComputerVisionGit/npcv/test/Datas/SampleDatas/digits.png";
	const char* classifyOcr_output = "/home/nedja/ComputerVisionGit/npcv/test/Datas/TestOutput/digits.png";


	const char* fileWrite_output = "/home/nedja/ComputerVisionGit/ComputerVision/npcv/test/Datas/OutputDatas/fileProba.csv";


#endif




#endif
