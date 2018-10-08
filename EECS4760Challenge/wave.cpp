#include "stdafx.h"
#include "wave.h"
#include <iostream>


Wave::Wave(std::string filename) 
{
	wavFile.open(filename, std::ios::binary | std::ios::in);

	bool isGood = true;
	isGood &= verifyChunkID() & verifyFormat() & verifySubchunk1ID() & verifySubchunk2ID();
	if (!isGood) throw std::exception("Wave : could not verify file contents.");

	uint32_t data = 0;
	wavFile.seekg(4);
	for (int i = 0; i < 4; i++) data |= wavFile.get() << (i * 8);
	chunkSize = data;

	data = 0;
	wavFile.seekg(16);
	for (int i = 0; i < 4; i++) data |= wavFile.get() << (i * 8);
	subChunk1Size = data;

	data = 0;
	wavFile.seekg(20);
	for (int i = 0; i < 2; i++) data |= wavFile.get() << (i * 8);
	audioFormat = data;

	data = 0;
	wavFile.seekg(22);
	for (int i = 0; i < 2; i++) data |= wavFile.get() << (i * 8);
	numChannels = data;

	data = 0;
	wavFile.seekg(24);
	for (int i = 0; i < 4; i++) data |= wavFile.get() << (i * 8);
	sampleRate = data;

	data = 0;
	wavFile.seekg(28);
	for (int i = 0; i < 4; i++) data |= wavFile.get() << (i * 8);
	byteRate = data;

	data = 0;
	wavFile.seekg(32);
	for (int i = 0; i < 2; i++) data |= wavFile.get() << (i * 8);
	blockAlign = data;

	data = 0;
	wavFile.seekg(34);
	for (int i = 0; i < 2; i++) data |= wavFile.get() << (i * 8);
	bitsPerSample = data;

	data = 0;
	wavFile.seekg(40);
	for (int i = 0; i < 4; i++) data |= wavFile.get() << (i * 8);
	subChunk2Size = data;
}


Wave::~Wave()
{
}

bool Wave::verifyChunkID()
{
	std::string chunkID = "";
	wavFile.seekg(0, wavFile.beg);

	for (int i = 0; i < 4; i++)
	{
		chunkID += wavFile.get();
	}

	if (chunkID.compare("RIFF") == 0) return true;
	return false;
}

uint32_t Wave::getChunkSize()
{
	return chunkSize;
}

bool Wave::verifyFormat()
{
	std::string format = "";
	wavFile.seekg(8);

	for (int i = 0; i < 4; i++)
	{
		format += wavFile.get();
	}

	if (format.compare("WAVE") == 0) return true;
	return false;
}

bool Wave::verifySubchunk1ID()
{
	std::string subchunkID = "";
	wavFile.seekg(12);

	for (int i = 0; i < 4; i++)
	{
		subchunkID += wavFile.get();
	}

	if (subchunkID.compare("fmt ") == 0) return true;
	return false;
}

uint32_t Wave::getSubchunk1Size()
{
	return subChunk1Size;
}

uint16_t Wave::getAudioFormat()
{
	return audioFormat;
}

uint16_t Wave::getNumChannels()
{
	return numChannels;
}

uint32_t Wave::getSampleRate()
{
	return sampleRate;
}

uint32_t Wave::getByteRate()
{
	return byteRate;
}

uint16_t Wave::getBlockAlign()
{
	return blockAlign;
}

uint16_t Wave::getBitsPerSample()
{
	return bitsPerSample;
}

bool Wave::verifySubchunk2ID()
{
	std::string subchunkID = "";
	wavFile.seekg(36);

	for (int i = 0; i < 4; i++)
	{
		subchunkID += wavFile.get();
	}

	if (subchunkID.compare("data") == 0) return true;
	return false;
}

uint32_t Wave::getSubChunk2Size()
{
	return subChunk2Size;
}

Frame Wave::operator[](uint8_t index)
{
	size_t fileIndex = (getChunkSize() - getSubChunk2Size() + 8) + (index * getFrameSize());
	wavFile.seekg(fileIndex);
	Frame test(getNumChannels());
	ChannelSize data;

	for (int i = 0; i < getNumChannels(); i++)
	{
		data = 0;
		for (int j = 0; j < (getBitsPerSample() / 8); j++)
		{
			int result = wavFile.get();

			bool eof = wavFile.eof();
			bool fail = wavFile.fail();
			bool bad = wavFile.bad();
			if (fail)
			{
				std::cerr << "AHHHH!!!!!" << std::endl;
			}
			data |= result << (j * 8);
		}
		test[i] = data;
	}
	return test;
}

size_t Wave::getFrameSize()
{
	return (getBitsPerSample() / 8) * getNumChannels();
}

size_t Wave::getFrameCount()
{
	return getSubChunk2Size() / getFrameSize();
}



Wave::WaveIterator::WaveIterator(size_t frameIndex, Wave& owner) : owner(owner)
{
	currentFrameIndex = frameIndex;
}

Wave::WaveIterator & Wave::WaveIterator::operator++()
{
	currentFrameIndex++;
	return *this;
}

bool Wave::WaveIterator::operator!=(const WaveIterator & rhs)
{
	return this->currentFrameIndex != rhs.currentFrameIndex;
}

Frame Wave::WaveIterator::operator*()
{
	
	size_t fileIndex = (owner.getChunkSize() - owner.getSubChunk2Size() + 8) + (currentFrameIndex * owner.getFrameSize());
	owner.wavFile.seekg(fileIndex);
	Frame test(owner.getNumChannels());
	ChannelSize data;

	for (int i = 0; i < owner.getNumChannels(); i++)
	{
		data = 0;
		for (int j = 0; j < (owner.getBitsPerSample() / 8); j++)
		{
			int result = owner.wavFile.get();

			bool eof = owner.wavFile.eof();
			bool fail = owner.wavFile.fail();
			bool bad = owner.wavFile.bad();
			if (fail)
			{
				std::cerr << "AHHHH!!!!!" << std::endl;
			}
			data |= result << (j * 8);
		}
		test[i] = data;
	}
	return test;
}
