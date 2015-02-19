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
 * Calibrate the price noise based on sample data's mean and standard deviation
 ***********************************************************/
void Calibrate_noise(int& up, int& low)
{
	up=0;
	low=0;
	vector<data_A> data;
	data=Read("data10k.txt");
	//sort(data.begin(),data.end());
	double sum=0;
	double sum_square=0;
	int count=0;
	for (int i=0;i<data.size();i++)
	{
		if (data[i].price>200 && data[i].price<5000)
			{
			count++;
			sum=sum*(double(count-1))/count+data[i].price/count;
			sum_square=sum_square*(double(count-1))/count+data[i].price*data[i].price/count;
			}
	}
	//cout<<sum<<" "<<sum_square<<endl;
	double variance=(sum_square-sum*sum);
	up=std::min(5000.0,sum+3*sqrt(variance));
	low=std::max(200.0, sum-3*sqrt(variance));
	//cout<<up<<" "<<low<<endl;
}
/*********************************************************
 * Scrub the data into signal list and noise list  by checking certain condition
 ***********************************************************/
int Scrub(std::string infilename) {
	log4cpp::Category& root = InitLogging::getRoot();
	clock_t begin = clock();
	int upperbound; int lowerbound;
	Calibrate_noise(upperbound,lowerbound);
	clock_t end = clock();
	std::ostringstream os2;
	os2 << "Calibrating the standard for noise using time : "
			<< Utils::diffclock(end, begin);
	root.info(os2.str());
	begin = clock();
	//std::vector<data_A> data;
	std::ifstream infile(infilename.c_str());
	std::string date_time;
	float price;
	int volume;
	char date_time_C[40];
	char price_C[10];
	char volume_C[10];
	int signal_size = 0;
	int count_total=0;
	if (infile.is_open()) {
		while (infile.good()) {
			infile.getline(date_time_C, 256, ',');
			infile.getline(price_C, 256, ',');
			infile.getline(volume_C, 256, '\n');
			date_time = (std::string) (date_time_C);
			price = atof(price_C);
			volume = atoi(volume_C);
			count_total++;
			if (price < lowerbound|| price > upperbound || volume<=0)
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

	end = clock();
	std::ostringstream os1;
	os1 << "Scrub data to signal.txt and noise.txt takes : "
			<< Utils::diffclock(end, begin);
	root.info(os1.str());
	std::ostringstream os3;
	os3 << "signal percentage : "
			<< (double)signal_size*100.0/count_total;
	root.info(os3.str());
	return signal_size;

}

#endif /* SCRUB_HPP_ */
