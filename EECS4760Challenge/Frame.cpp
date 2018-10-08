#include "stdafx.h"
#include "Frame.h"


Frame::Frame(uint8_t chCount)
{
	channelArray = new ChannelSize[chCount];
	Frame::chCount = chCount;
}

Frame::Frame(Frame & copyFrom)
{
	chCount = copyFrom.chCount;
	channelArray = new ChannelSize[chCount];

	for (int i = 0; i < chCount; i++) channelArray[i] = copyFrom.channelArray[i];
}

Frame::~Frame()
{
	delete[] channelArray;
}

ChannelSize& Frame::operator[](uint16_t index)
{
	if (index >= chCount)
		throw std::exception("Frame[index] : index out of bounds.");
	return channelArray[index];
}

Frame& Frame::operator=(const Frame& copyFrom)
{
	chCount = copyFrom.chCount;
	channelArray = new ChannelSize[chCount];

	for (int i = 0; i < chCount; i++) channelArray[i] = copyFrom.channelArray[i];

	return *this;
}

uint8_t Frame::getChannelCount()
{
	return chCount;
}