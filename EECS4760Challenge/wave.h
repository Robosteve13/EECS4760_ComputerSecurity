#pragma once
#include <cstdint>
#include <fstream>
#include <string>
#include "Frame.h"
#include <thread>

class Wave
{

public:
	friend class WaveIterator;
	Wave(std::string);
	~Wave();

	uint32_t getChunkSize();
	uint32_t getSubchunk1Size();
	uint16_t getAudioFormat();
	uint16_t getNumChannels();
	uint32_t getSampleRate();
	uint32_t getByteRate();
	uint16_t getBlockAlign();
	uint16_t getBitsPerSample();
	uint32_t getSubChunk2Size();

	class WaveIterator
	{
	public:
		WaveIterator(size_t frameIndex, Wave& owner);
		WaveIterator& operator++();
		bool operator!=(const WaveIterator& rhs);
		Frame operator*();
	private:
		Wave& owner;
		size_t currentFrameIndex = 0;
	};

	WaveIterator begin() { return WaveIterator(0, *this); }

	WaveIterator end() { return WaveIterator(getFrameCount() + 1, *this); }
	Frame operator[](uint8_t index);

	size_t getFrameSize();
	size_t getFrameCount();

private:
	uint32_t chunkSize;
	uint32_t subChunk1Size;
	uint16_t audioFormat;
	uint16_t numChannels;
	uint32_t sampleRate;
	uint32_t byteRate;
	uint16_t blockAlign;
	uint16_t bitsPerSample;
	uint32_t subChunk2Size;

	bool verifySubchunk2ID();
	bool verifyChunkID();
	bool verifyFormat();
	bool verifySubchunk1ID();
	std::fstream wavFile;
	
};

