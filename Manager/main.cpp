#include <iostream>
#include <fstream>
#include "SteganoFile.h"

void encode(const std::string& inputPath, const std::string& outputName, const std::string& outputPath, const std::string& message) {
	std::ifstream inputfile(inputPath, std::ios::binary);

}


int main(int argc, char* argv[])
{
	if (argc < 4) {
		std::cerr << "Usage:" << std::endl;
		std::cerr << "  Encode: " << argv[0] << " -e <input_path> <outout_path> <message>" << std::endl;
		std::cerr << "  Decode: " << argv[0] << " -d <input_file>" << std::endl;
		return 1;
	}

	std::string mode = argv[1];
	std::string inputFile = argv[2];
	try {
		auto fileHandler = SteganoFile::create(inputFile);

		if (mode == "-e") {
			if (argc < 5 || argc < 6) {
				std::cerr << "Error: Missing output file or message." << std::endl;
				return 1;
			}

			std::string outputFile = argv[3];
			std::string message = argv[4];


		}
	}
	catch (const std::exception& e) {
		std::cerr << "Error:" << e.what() << std::endl;
		return 1;
	}
	return 0;
}
