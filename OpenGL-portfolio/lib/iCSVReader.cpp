#pragma once

#include "iCSVReader.h"


vector<string> readCSV(const char* str)
{

	vector<string> buff_vector;
	string str_buf;
	fstream fs;

	fs.open(str, ios::in);

	while(!fs.eof())
	{
		getline(fs, str_buf, ',');
		printf("%s\n", str_buf);
		buff_vector.push_back(str_buf);
	}
	fs.close();

	return buff_vector;
}

void writeCSV(vector<string> _data, const char* str)
{
	fstream fs;
	fs.open(str, ios::out);

	for(int i=0; i<_data.size(); i++)
		fs << _data[i] << endl;

	fs.close();
}

