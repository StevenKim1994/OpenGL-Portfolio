#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

vector<string> readCSV(const char* str);

void writeCSV(vector<string> _data ,const char* str);
