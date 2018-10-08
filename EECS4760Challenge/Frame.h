#pragma once
#include <cstdint>
#include <exception>

typedef uint16_t ChannelSize;

class Frame
{
public:
	uint8_t getChannelCount();
	Frame(uint8_t chCount = 2);
	Frame(Frame& copyfrom);
	~Frame();
	ChannelSize& operator[](uint16_t index);
	Frame& operator=(const Frame& copyFrom);
private:
	uint8_t chCount;
	ChannelSize* channelArray = NULL;
};