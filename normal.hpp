/*
 * normal.hpp
 *
 *  Created on: Feb 10, 2015
 *      Author: haotian
 */

#ifndef NORMAL_HPP_
#define NORMAL_HPP_
#include "mylog.hpp"
#include <iostream>
#include <vector>
#include<math.h>
#include <string>
#include "data_class.hpp"
//#include <thread>
using namespace std;
//static const int NUM_THREADS = 10;
//static double x_mean_thread[NUM_THREADS];
/*
 // Thread function. When a thread is launched, this is the code that gets executed.
 void ThreadFunction_mean(int threadID, int num,vector<data_A> signal) {
 //cout<<"start"<<endl;
 for (int i=0;i<num;i++)
 {
 x_mean_thread[threadID]=x_mean_thread[threadID]+signal[threadID*num+i].price/num;
 }
 cout<<"thread "<<threadID<<" launched"<<endl;

 }
 */



/*********************************************************
 * Test Normal by using 5% confidence level by Jarque Bera Test
 *
 *
 ***********************************************************/
double Test_Normal(std::string signal, int signal_size) {
	double S;
	double K;
	double JB;
	double x_mean = 0;
	int n = signal_size;
	log4cpp::Category& root = InitLogging::getRoot();
	clock_t begin = clock();
//thread thread[NUM_THREADS];
	/*
	 for (int i = 0; i < NUM_THREADS; ++i) {
	 std::cout<<"launch thread "<<i<<endl;
	 thread[i] = std::thread(ThreadFunction_mean, i,int(double(n)/NUM_THREADS),signal);
	 }
	 for (int i = 0; i < NUM_THREADS; ++i) {
	 thread[i].join();
	 x_mean=x_mean+ x_mean_thread[i]/NUM_THREADS;
	 }
	 */

	std::ifstream infile("signal.txt");
	std::string date_time;
	float price;
	char date_time_C[40];
	char price_C[10];
	char volume_C[10];
	if (infile.is_open()) {
		for (int i = 0; i < n; i++) {
			infile.getline(date_time_C, 256, ',');
			infile.getline(price_C, 256, ',');
			infile.getline(volume_C, 256, '\n');
			price = atof(price_C);
			x_mean = x_mean * i / (i + 1) + double(price) / (i + 1);
		}
	}

	cout << "x_mean=" << x_mean << endl;

	double x_2_sum = 0;
	double x_3_sum = 0;
	double x_4_sum = 0;
	if (infile.is_open()) {
		for (int i = 0; i < n; i++) {
			infile.getline(date_time_C, 256, ',');
			infile.getline(price_C, 256, ',');
			infile.getline(volume_C, 256, '\n');
			price = atof(price_C);
			x_mean = x_mean * i / (i + 1) + double(price) / (i + 1);
		}
	}

	std::ifstream infile2("signal.txt");
	if (infile2.is_open()) {
		for (int i = 0; i < n; i++) {
			infile2.getline(date_time_C, 256, ',');
			infile2.getline(price_C, 256, ',');
			infile2.getline(volume_C, 256, '\n');
			price = atof(price_C);
			x_2_sum = x_2_sum * i / (i + 1)
					+ pow(x_mean - double(price), 2.0) / (i + 1);
			x_3_sum = x_3_sum * i / (i + 1)
					+ pow(x_mean - double(price), 3.0) / (i + 1);
			x_4_sum = x_4_sum * i / (i + 1)
					+ pow(x_mean - double(price), 4.0) / (i + 1);
		}
	}

	S = x_3_sum / pow(x_2_sum, 1.5);
	K = x_4_sum / pow(x_2_sum, 2.0);
	JB = double(n) / 6.0 * (S * S + (K - 3.0) * (K - 3.0) / 4.0);

	std::ostringstream os;
	os <<  "Test Normal, ";
	os <<  "JB=" << JB;
	os << ", Chi-Square from Normal Dist=5.99 within 5 percent confidence level";

	root.info(os.str());

	if (JB < 5.99) {
		root.info(
				"The sample are normal is within 5 percent confidence level by Jarque Bera Test");
	} else {
		root.warn(
				"The sample are not normal within 5 percent confidence level by Jarque Bera Test");
	}

	clock_t end = clock();
	std::ostringstream os2;
	os2 << "Test Normal takes : " << Utils::diffclock(end, begin);
	root.info(os2.str());
	return JB;
}


/*********************************************************
 * Test Log Normal by using 5% confidence level by Jarque Bera Test
 *
 *
 ***********************************************************/
double  Test_Log_Normal(std::string signal, int signal_size) {
	double S;
	double K;
	double JB;
	double x_mean = 0;
	int n = signal_size;
	log4cpp::Category& root = InitLogging::getRoot();
	clock_t begin = clock();

	std::ifstream infile("signal.txt");
	std::string date_time;
	float price;
	char date_time_C[40];
	char price_C[10];
	char volume_C[10];


	double x_2_sum = 0;
	double x_3_sum = 0;
	double x_4_sum = 0;
	if (infile.is_open()) {
		for (int i = 0; i < n; i++) {
			infile.getline(date_time_C, 256, ',');
			infile.getline(price_C, 256, ',');
			infile.getline(volume_C, 256, '\n');
			price = log(atof(price_C));
			x_mean = x_mean * i / (i + 1) + double(price) / (i + 1);
		}
	}

	std::ifstream infile2("signal.txt");
	if (infile2.is_open()) {
		for (int i = 0; i < n; i++) {
			infile2.getline(date_time_C, 256, ',');
			infile2.getline(price_C, 256, ',');
			infile2.getline(volume_C, 256, '\n');
			price = log(atof(price_C));
			x_2_sum = x_2_sum * i / (i + 1)
					+ pow(x_mean - double(price), 2.0) / (i + 1);
			x_3_sum = x_3_sum * i / (i + 1)
					+ pow(x_mean - double(price), 3.0) / (i + 1);
			x_4_sum = x_4_sum * i / (i + 1)
					+ pow(x_mean - double(price), 4.0) / (i + 1);
		}
	}

	S = x_3_sum / pow(x_2_sum, 1.5);
	K = x_4_sum / pow(x_2_sum, 2.0);
	JB = double(n) / 6.0 * (S * S + (K - 3.0) * (K - 3.0) / 4.0);

	std::ostringstream os;
	os << "Test Log Normal";
	os <<  ", JB=" << JB;
	os << ", Chi-Square from Normal Dist=5.99 within 5 percent confidence level";

	root.info(os.str());

	if (JB < 5.99) {
		root.info(
				"The sample are log normal is within 5 percent confidence level by Jarque Bera Test");
	} else {
		root.warn(
				"The sample are not log normal within 5 percent confidence level by Jarque Bera Test");
	}

	clock_t end = clock();
	std::ostringstream os2;
	os2 << "Test Log Normal takes : " << Utils::diffclock(end, begin);
	root.info(os2.str());
	return JB;
}
#endif /* NORMAL_HPP_ */
