#ifndef __FILE_HANDLER_H
#define __FILE_HANDLER_H

#include "Basic.h"
#include <fstream>

const std::string DATASET_PATH = "./dataset/";

std::vector<std::string> readFileInLines(std::string _fileName);

#endif
