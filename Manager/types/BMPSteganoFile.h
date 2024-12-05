#include <iostream>
#include <vector>
#include "../SteganoFile.h"

#pragma pack(push, 1)
struct BMPFileHeader 
{
	uint16_t fileType;
	uint32_t fileSize;
	uint16_t reserved1;
	uint16_t reserved2;
	uint32_t offset;
};

struct BMPDIBHeader {
	uint32_t headerSize;
	int32_t width;
	int32_t height;
	uint16_t planes;
	uint16_t bitsPerPixel;
	uint32_t compression;
	uint32_t imageSize;
	int32_t xPixelsPerMeter;
	int32_t yPixelperMeter;
	uint32_t colorsUsed;
	uint32_t importantColors;
};

#pragma pack(pop)

class BMPSteganoFile : public SteganoFile {
	BMPFileHeader fileHeader;
	BMPDIBHeader dibHeader;
	std::vector<uint8_t> pixelData;

public:
	bool read(const std::string& filePath) {

	}
};