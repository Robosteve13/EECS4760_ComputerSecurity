#include "stdafx.h"
#include "AppendBits.h"


AppendBits::AppendBits(std::string baseFileName)
{
	file[0] = std::fstream(baseFileName + "X.txt",		std::ios::binary | std::ios::out | std::ios::trunc);
	file[1] = std::fstream(baseFileName + "Y.txt",		std::ios::binary | std::ios::out | std::ios::trunc);
	file[2] = std::fstream(baseFileName + "Z.txt",		std::ios::binary | std::ios::out | std::ios::trunc);
	file[3] = std::fstream(baseFileName + "XY.txt",		std::ios::binary | std::ios::out | std::ios::trunc);
	file[4] = std::fstream(baseFileName + "XZ.txt",		std::ios::binary | std::ios::out | std::ios::trunc);
	file[5] = std::fstream(baseFileName + "YX.txt",		std::ios::binary | std::ios::out | std::ios::trunc);
	file[6] = std::fstream(baseFileName + "YZ.txt",		std::ios::binary | std::ios::out | std::ios::trunc);
	file[7] = std::fstream(baseFileName + "ZX.txt",		std::ios::binary | std::ios::out | std::ios::trunc);
	file[8] = std::fstream(baseFileName + "ZY.txt",		std::ios::binary | std::ios::out | std::ios::trunc);
	file[9] = std::fstream(baseFileName + "XYZ.txt",	std::ios::binary | std::ios::out | std::ios::trunc);
	file[10] = std::fstream(baseFileName + "XZY.txt",	std::ios::binary | std::ios::out | std::ios::trunc);
	file[11] = std::fstream(baseFileName + "YXZ.txt",	std::ios::binary | std::ios::out | std::ios::trunc);
	file[12] = std::fstream(baseFileName + "YZX.txt",	std::ios::binary | std::ios::out | std::ios::trunc);
	file[13] = std::fstream(baseFileName + "ZXY.txt",	std::ios::binary | std::ios::out | std::ios::trunc);
	file[14] = std::fstream(baseFileName + "ZYX.txt",	std::ios::binary | std::ios::out | std::ios::trunc);
}

void AppendBits::append(uint16_t inputByte)
{
	//// MSB X
	//appendBit(inputByte & (1 << 15), 0);

	//// MSB Y
	//appendBit(inputByte & (1 << 14), 1);

	//// MSB Z
	//appendBit(inputByte & (1 << 13), 2);

	//// MSB XY
	//appendBit(inputByte & (1 << 15), 3);
	//appendBit(inputByte & (1 << 14), 3);

	//// MSB XZ
	//appendBit(inputByte & (1 << 15), 4);
	//appendBit(inputByte & (1 << 13), 4);

	//// MSB YX
	//appendBit(inputByte & (1 << 14), 5);
	//appendBit(inputByte & (1 << 15), 5);

	//// MSB YZ
	//appendBit(inputByte & (1 << 14), 6);
	//appendBit(inputByte & (1 << 13), 6);

	//// MSB ZX
	//appendBit(inputByte & (1 << 13), 7);
	//appendBit(inputByte & (1 << 15), 7);

	//// MSB ZY
	//appendBit(inputByte & (1 << 13), 8);
	//appendBit(inputByte & (1 << 14), 8);

	//// MSB XYZ
	//appendBit(inputByte & (1 << 15), 9);
	//appendBit(inputByte & (1 << 14), 9);
	//appendBit(inputByte & (1 << 13), 9);

	//// MSB XZY
	//appendBit(inputByte & (1 << 15), 10);
	//appendBit(inputByte & (1 << 13), 10);
	//appendBit(inputByte & (1 << 14), 10);

	//// MSB YXZ
	//appendBit(inputByte & (1 << 14), 11);
	//appendBit(inputByte & (1 << 15), 11);
	//appendBit(inputByte & (1 << 13), 11);

	//// MSB YZX
	//appendBit(inputByte & (1 << 14), 12);
	//appendBit(inputByte & (1 << 13), 12);
	//appendBit(inputByte & (1 << 15), 12);

	//// MSB ZXY
	//appendBit(inputByte & (1 << 13), 13);
	//appendBit(inputByte & (1 << 15), 13);
	//appendBit(inputByte & (1 << 14), 13);

	//// MSB ZYX
	//appendBit(inputByte & (1 << 13), 14);
	//appendBit(inputByte & (1 << 14), 14);
	//appendBit(inputByte & (1 << 15), 14);

	//appendBit(inputByte & (1 << 0), 0);
	//appendBit(inputByte2 & (1 << 0), 0);

	//appendBit(inputByte2 & (1 << 0), 1);
	//appendBit(inputByte & (1 << 0), 1);
	
	//appendBit(inputByte & (1 << 1), 0);
	//appendBit(inputByte & (1 << 0), 0);
	//appendBit(inputByte2 & (1 << 2), 0);
	//appendBit(inputByte2 & (1 << 1), 0);
	//appendBit(inputByte2 & (1 << 0), 0);

	//appendBit(inputByte & (1 << 1), 0);
	//appendBit(inputByte2 & (1 << 2), 0);

	//appendBit(inputByte & (1 << 1), 1);
	//appendBit(inputByte & (1 << 0), 1);
	//appendBit(inputByte2 & (1 << 2), 1);
	//appendBit(inputByte2 & (1 << 1), 1);
	//appendBit(inputByte2 & (1 << 0), 1);

	//appendBit(inputByte & (1 << 1), 0);
	//appendBit(inputByte2 & (1 << 1), 0);
	//appendBit(inputByte & (1 << 0), 0);
	//appendBit(inputByte2 & (1 << 0), 0);

	//appendBit(inputByte & (1 << 0), 1);
	//appendBit(inputByte2 & (1 << 0), 1);
	//appendBit(inputByte & (1 << 1), 1);
	//appendBit(inputByte2 & (1 << 1), 1);

	// X
	appendBit(inputByte & (1 << 2), 0);

	// Y
	appendBit(inputByte & (1 << 1), 1);

	// Z
	appendBit(inputByte & (1 << 0), 2);

	// XY
	appendBit(inputByte & (1 << 2), 3);
	appendBit(inputByte & (1 << 1), 3);

	// XZ
	appendBit(inputByte & (1 << 2), 4);
	appendBit(inputByte & (1 << 0), 4);

	// YX
	appendBit(inputByte & (1 << 1), 5);
	appendBit(inputByte & (1 << 2), 5);

	// YZ
	appendBit(inputByte & (1 << 1), 6);
	appendBit(inputByte & (1 << 0), 6);

	// ZX
	appendBit(inputByte & (1 << 0), 7);
	appendBit(inputByte & (1 << 2), 7);

	// ZY
	appendBit(inputByte & (1 << 0), 8);
	appendBit(inputByte & (1 << 1), 8);

	// XYZ
	appendBit(inputByte & (1 << 2), 9);
	appendBit(inputByte & (1 << 1), 9);
	appendBit(inputByte & (1 << 0), 9);

	// XZY
	appendBit(inputByte & (1 << 2), 10);
	appendBit(inputByte & (1 << 0), 10);
	appendBit(inputByte & (1 << 1), 10);

	// YXZ
	appendBit(inputByte & (1 << 1), 11);
	appendBit(inputByte & (1 << 2), 11);
	appendBit(inputByte & (1 << 0), 11);

	// YZX
	appendBit(inputByte & (1 << 1), 12);
	appendBit(inputByte & (1 << 0), 12);
	appendBit(inputByte & (1 << 2), 12);

	// ZXY
	appendBit(inputByte & (1 << 0), 13);
	appendBit(inputByte & (1 << 2), 13);
	appendBit(inputByte & (1 << 1), 13);

	// ZYX
	appendBit(inputByte & (1 << 0), 14);
	appendBit(inputByte & (1 << 1), 14);
	appendBit(inputByte & (1 << 2), 14);
}

void AppendBits::appendBit(bool bit, uint8_t bufferNum)
{
	bufferArray[bufferNum] |= (bit << (7 - bufferArraySize[bufferNum]++));
	if (bufferArraySize[bufferNum] == 8)
	{
		file[bufferNum].put(bufferArray[bufferNum]);
		bufferArraySize[bufferNum] = 0;
		bufferArray[bufferNum] = 0;
	}
}
