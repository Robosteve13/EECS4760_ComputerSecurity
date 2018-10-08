// EECS4760Challenge.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "wave.h"
#include <iostream>
#include <fstream>
#include "Frame.h"
#include <cstdint>
#include "AppendBits.h"


void run()
{
	Wave disk1("C:\\Users\\Adam.Savel\\Desktop\\Yup\\ChallengeDisc1.wav");
	Wave disk2("C:\\Users\\Adam.Savel\\Desktop\\Yup\\ChallengeDisc2.wav");
	Wave disk3("C:\\Users\\Adam.Savel\\Desktop\\Yup\\ChallengeDisc3-edited.wav");
	//std::cout << "Chunk Size: "			<< disk1.getChunkSize()		<< std::endl;
	//std::cout << "Sub Chunk Size: "		<< disk1.getSubchunk1Size()	<< std::endl;
	//std::cout << "Audio Format: "		<< disk1.getAudioFormat()	<< std::endl;
	//std::cout << "Number of Channels: "	<< disk1.getNumChannels()	<< std::endl;
	//std::cout << "Sample Rate: "		<< disk1.getSampleRate()	<< std::endl;
	//std::cout << "Byte Rate: "			<< disk1.getByteRate()		<< std::endl;
	//std::cout << "Block Align: "		<< disk1.getBlockAlign()	<< std::endl;
	//std::cout << "Bits per Sample: "	<< disk1.getBitsPerSample()	<< std::endl;
	//std::cout << "Sub Chunk 2 Size: "	<< disk1.getSubChunk2Size()	<< std::endl;
	//std::cout << "Frame Count: "		<< disk1.getFrameCount()	<< std::endl;

	//AppendBits ch1(R"(C:\Users\Adam.Savel\Desktop\Yup\Results\Disk1\Channel1)");
	//AppendBits ch2(R"(C:\Users\Adam.Savel\Desktop\Yup\Results\Disk1\Channel2)");
	//AppendBits ch12(R"(C:\Users\Adam.Savel\Desktop\Yup\Results\Disk1\Channel12)");
	//AppendBits ch21(R"(C:\Users\Adam.Savel\Desktop\Yup\Results\Disk1\Channel21)");

	size_t count = 0;
	//for (Frame frame : disk1)
	//{
	//	//if (count++ % 2 == 0) continue;
	//	
	//	//ch12.append(frame[0], frame[1]);

	//	ch1.append(frame[0]);
	//	ch2.append(frame[1]);
	//	ch12.append(frame[0]);
	//	ch12.append(frame[1]);
	//	ch21.append(frame[1]);
	//	ch21.append(frame[0]);
	//}

	//AppendBits d2ch1(R"(C:\Users\Adam.Savel\Desktop\Yup\Results\Disk2\Channel1)");
	//AppendBits d2ch2(R"(C:\Users\Adam.Savel\Desktop\Yup\Results\Disk2\Channel2)");
	//AppendBits d2ch12(R"(C:\Users\Adam.Savel\Desktop\Yup\Results\Disk2\Channel12)");
	//AppendBits d2ch21(R"(C:\Users\Adam.Savel\Desktop\Yup\Results\Disk2\Channel21)");

	//count = 0;
	//for (Frame frame : disk2)
	//{
	//	//if (count++ % 2 == 0) continue;

	//	//ch12.append(frame[0], frame[1]);

	//	d2ch1.append(frame[0]);
	//	d2ch2.append(frame[1]);
	//	d2ch12.append(frame[0]);
	//	d2ch12.append(frame[1]);
	//	d2ch21.append(frame[1]);
	//	d2ch21.append(frame[0]);
	//}

	AppendBits d3ch1(R"(C:\Users\Adam.Savel\Desktop\Yup\Results\Disk3\Channel1)");
	AppendBits d3ch2(R"(C:\Users\Adam.Savel\Desktop\Yup\Results\Disk3\Channel2)");
	AppendBits d3ch12(R"(C:\Users\Adam.Savel\Desktop\Yup\Results\Disk3\Channel12)");
	AppendBits d3ch21(R"(C:\Users\Adam.Savel\Desktop\Yup\Results\Disk3\Channel21)");

	//count = 0;
	for (Frame frame : disk3)
	{
		//if (count++ >= 3000000) break;

		//ch12.append(frame[0], frame[1]);

		if (count % 3 == 0) d3ch1.append(frame[0]);
		if (count++ % 3 == 1) d3ch1.append(frame[1]);

		//d3ch1.append(frame[0]);
		//d3ch2.append(frame[1]);
		//d3ch12.append(frame[0]);
		//d3ch12.append(frame[1]);
		//d3ch21.append(frame[1]);
		//d3ch21.append(frame[0]);
	}
}





int main()
{
	int i = 4;
	bool i2 = i;
	int i3 = i2 << 2;

	try
	{
		run();
	}
	catch (std::exception ex)
	{
		std::cout << ex.what();
	}

	std::cout << "Completed!";
	std::cin.ignore();
    return 0;
}