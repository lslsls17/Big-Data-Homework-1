/*
 * Parse_Csv.hpp
 *
 *  Created on: Feb 9, 2015
 *      Author: haotian
 */

#ifndef PARSE_CSV_HPP_
#define PARSE_CSV_HPP_

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "data_class.hpp"
#include <stdlib.h>     /* atoi */


//Function for read data line by line, take file name as argument
std::vector<data_A> Read(std::string infilename) {
	std::vector<data_A> data;
	std::ifstream infile(infilename.c_str());
	std::string date_time;
	float price;
	int volume;
	char date_time_C[40];
	char price_C[10];
	char volume_C[10];
	int i;
	if (infile.is_open()) {
		while (infile.good()) {
			infile.getline(date_time_C, 256, ',');
			infile.getline(price_C, 256, ',');
			infile.getline(volume_C, 256, '\n');
			date_time = (std::string) (date_time_C);
			price = atof(price_C);
			volume = atoi(volume_C);
			//cout<<date_time<<" "<<price<<" "<<volume<<endl;
			data.push_back(data_A(date_time, price, volume));
			i++;
		}
		infile.close();
	} else {
		std::cout << "Error opening file";
	}
	return data;
}
//Function for write data line by line, take output file name as argument
void Write(data_A data, std::string outfilename) {
	std::ofstream outfile;
	outfile.open(outfilename.c_str(), std::ios::out | std::ios::app);
	outfile << data.date_time << "," << data.price << "," << data.volume
			<< "\n";
	outfile.close();
}
int Read_Size() {
	std::ifstream infile("size_temp.txt");
	int size;
	char size_c[10];

	if (infile.is_open()) {
			infile.getline(size_c, 256);
			size = atoi(size_c);
		infile.close();
		std::remove("size_temp.txt");
	} else {
		std::cout << "Error opening file";
	}
	return size;
}
void Write_Size(int size) {
	std::ofstream outfile;
	outfile.open("size_temp.txt", std::ios::out | std::ios::app);
	outfile << size;
	outfile.close();
}
#endif /* PARSE_CSV_HPP_ */
