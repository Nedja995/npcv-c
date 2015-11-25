#ifndef __NPCV_DATA_TEST_H__
#define __NPCV_DATA_TEST_H__


const char* fileWrite_input = "1,4\n2,0\n3,7\0";

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

#elif defined __linux__

	const char * projectPath = "/home/ubuntu/ComputerVision/npcv";

	const char* imageReadWrite_input = "/home/ubuntu/ComputerVision/npcv/test/Datas/SampleDatas/lena.jpg";
	const char* imageReadWrite_output = "/home/ubuntu/ComputerVision/npcvtest/Datas/TestOutput/lenaRW.png";

	const char* imageSubarea_input = "/home/ubuntu/ComputerVision/npcvtest/Datas/SampleDatas/lena.jpg";
	const char* imageSubarea_output = "/home/ubuntu/ComputerVision/npcvtest/Datas/TestOutput/lenaSubarea.png";

	const char* imageGray_input = "/home/ubuntu/ComputerVision/npcvtest/Datas/SampleDatas/lena.jpg";
	const char* imageGray_output = "/home/ubuntu/ComputerVision/npcvtest/Datas/TestOutput/lenaGray.png";

	const char* edgeDetection_input = "/home/ubuntu/ComputerVision/npcvtest/Datas/SampleDatas/digitsSmall.jpg";
	const char* edgeDetection_output = "/home/ubuntu/ComputerVision/npcvtest/Datas/TestOutput/digitsSmallEdgeDetect.png";

	const char* classifyOcr_input = "/home/ubuntu/ComputerVision/npcvtest/Datas/SampleDatas/digits.png";
	const char* classifyOcr_output = "/home/ubuntu/ComputerVision/npcvtest/Datas/TestOutput/digits.png";


	const char* fileWrite_output = "D:/Projects/ComputerVision/ComputerVision/npcv/test/Datas/TestOutput/fileProba.csv";


#endif



#endif
