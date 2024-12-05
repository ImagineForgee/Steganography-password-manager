#include <iostream>
#include <string>
#include <algorithm>

class SteganoFile {
public:
	virtual ~SteganoFile() = default;

	virtual bool read(const std::string& filepath) = 0;
	virtual bool write(const std::string& filepath) = 0;
	virtual bool encode(const std::string& message) = 0;
	virtual std::string decode() = 0;

	static std::unique_ptr<SteganoFile> create(const std::string& filePath) {
		size_t pos = filePath.find_last_of('.');
		if (pos == std::string::npos) {
			throw std::invalid_argument("File must have an extension.");
		}

		std::string extension = filePath.substr(pos + 1);
		std::transform(extension.begin(), extension.end(), extension.begin(), ::tolower);

		if (extension == "bmp") {
			return std::make_unique<BMPSteganoFile>();
		}
		else {
			throw std::invalid_argument("Unsupported file type: " + extension);
		}
	};

};