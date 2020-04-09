#include "FileHandler.h"

std::vector<std::string> readFileInLines(std::string _fileName) {
	std::vector <std::string> contents;
	std::string filePath = DATASET_PATH + _fileName;
	try {
		std::ifstream dataFile(filePath);
		std::string line;
		if (dataFile.is_open()) {
			while (std::getline(dataFile, line)) {
				contents.push_back(line);
			}
			dataFile.close();
		}
		else { 
			std::cerr << "File open error\n";
		}
	}
	catch (int e) {
		std::cerr << "General file io error\n";
	}
	return contents;
}