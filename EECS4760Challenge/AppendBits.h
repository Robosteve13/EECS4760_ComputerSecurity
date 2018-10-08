#pragma once
#include <iostream>
#include <cstdint>
#include <fstream>
#include <string>

class AppendBits
{
public:
	AppendBits(std::string baseFileName);
	void append(uint16_t);
private:
	void appendBit(bool, uint8_t);
	uint8_t bufferArray[15] = { 0 };
	uint8_t bufferArraySize[15] = { 0 };
	std::fstream file[15];
};

