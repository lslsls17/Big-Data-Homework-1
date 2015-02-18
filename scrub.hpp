/*
 * scrub.hpp
 *
 *  Created on: Feb 10, 2015
 *      Author: haotian
 */

#ifndef SCRUB_HPP_
#define SCRUB_HPP_
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>    // std::sort
#include "data_class.hpp"
#include <stdlib.h>     /* atoi */
#include "Parse_Csv.hpp"
#include "mylog.hpp"


/*********************************************************
 * Scrub the data into signal list and noise list  by checking certain condition
 *
 *
 ***********************************************************/
int Scrub(std::string infilename) {
	log4cpp::Category& root = InitLogging::getRoot();
	clock_t begin = clock();
	//std::vector<data_A> data;
	std::ifstream infile(infilename.c_str());
	std::string date_time;
	float price;
	int volume;
	char date_time_C[40];
	char price_C[10];
	char volume_C[10];
	int signal_size = 0;
	if (infile.is_open()) {
		while (infile.good()) {
			infile.getline(date_time_C, 256, ',');
			infile.getline(price_C, 256, ',');
			infile.getline(volume_C, 256, '\n');
			date_time = (std::string) (date_time_C);
			price = atof(price_C);
			volume = atoi(volume_C);
			if (price < 500 || price > 5000)
				Write(data_A(date_time, price, volume), "noise.txt");
			else {
				Write(data_A(date_time, price, volume), "signal.txt");
				signal_size++;
			}

		}
		infile.close();
	} else {
		std::cout << "Error opening file";
	}
	clock_t end = clock();
	std::ostringstream os1;
	os1 << "Scrub data to signal.txt and noise.txt takes : "
			<< Utils::diffclock(end, begin);
	root.info(os1.str());
	return signal_size;

}

#endif /* SCRUB_HPP_ */
