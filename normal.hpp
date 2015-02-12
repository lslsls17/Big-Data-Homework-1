/*
 * normal.hpp
 *
 *  Created on: Feb 10, 2015
 *      Author: haotian
 */

#ifndef NORMAL_HPP_
#define NORMAL_HPP_

#include <iostream>
#include <vector>
#include<math.h>
#include <string>
#include "data_class.hpp"
#include <thread>
using namespace std;
static const int NUM_THREADS = 10;
static double x_mean_thread[NUM_THREADS];

// Thread function. When a thread is launched, this is the code that gets executed.
void ThreadFunction_mean(int threadID, int num,vector<data_A> signal) {
	//cout<<"start"<<endl;
	for (int i=0;i<num;i++)
	{
		x_mean_thread[threadID]=x_mean_thread[threadID]+signal[threadID*num+i].price/num;
	}
	cout<<"thread "<<threadID<<" launched"<<endl;

}


void Test_Normal(std::vector<data_A>  signal) {
double S;
double K;
double JB;
double x_mean=0;
int n=signal.size();
thread thread[NUM_THREADS];
for (int i = 0; i < NUM_THREADS; ++i) {
	std::cout<<"launch thread "<<i<<endl;
thread[i] = std::thread(ThreadFunction_mean, i,int(double(n)/NUM_THREADS),signal);
}
for (int i = 0; i < NUM_THREADS; ++i) {
	thread[i].join();
	x_mean=x_mean+ x_mean_thread[i]/NUM_THREADS;
}

/*
for(int i=0; i<n;i++)
{
	x_mean=x_mean*i/(i+1)+double(signal[i].price)/(i+1);
}
*/
cout<<"x_mean="<<x_mean<<endl;
double x_2_sum=0;
double x_3_sum=0;
double x_4_sum=0;
for(int i=0; i<n;i++)
{
	/*
	x_2_sum=x_2_sum+pow(x_mean-double(signal[i].price),2.0)/n;
	x_3_sum=x_3_sum+pow(x_mean-double(signal[i].price),3.0)/n;
	x_4_sum=x_4_sum+pow(x_mean-double(signal[i].price),4.0)/n;
	*/

	x_2_sum=x_2_sum*i/(i+1)+pow(x_mean-double(signal[i].price),2.0)/(i+1);
	x_3_sum=x_3_sum*i/(i+1)+pow(x_mean-double(signal[i].price),3.0)/(i+1);
	x_4_sum=x_4_sum*i/(i+1)+pow(x_mean-double(signal[i].price),4.0)/(i+1);

}
S=x_3_sum/pow(x_2_sum,1.5);
K=x_4_sum/pow(x_2_sum,2.0);
cout<<"S="<<S<<" "<<"K="<<K<<endl;
JB=double(n)/6.0*(S*S+(K-3.0)*(K-3.0)/4.0);
cout<<"JB="<<JB<<endl;
}

void Test_Log_Normal(std::vector<data_A>  signal) {
double S;
double K;
double JB;
double x_mean=0;
int n=signal.size();
for(int i=0; i<n;i++)
{
	x_mean=x_mean*i/(i+1)+double(log(signal[i].price))/(i+1);
}
cout<<"x_mean="<<x_mean<<endl;
double x_2_sum=0;
double x_3_sum=0;
double x_4_sum=0;
for(int i=0; i<n;i++)
{
	x_2_sum=x_2_sum*i/(i+1)+pow(x_mean-double(log(signal[i].price)),2.0)/(i+1);
	x_3_sum=x_3_sum*i/(i+1)+pow(x_mean-double(log(signal[i].price)),3.0)/(i+1);
	x_4_sum=x_4_sum*i/(i+1)+pow(x_mean-double(log(signal[i].price)),4.0)/(i+1);
}
S=x_3_sum/pow(x_2_sum,1.5);
K=x_4_sum/pow(x_2_sum,2.0);
cout<<"S="<<S<<" "<<"K="<<K<<endl;
JB=double(n)/6.0*(S*S+(K-3.0)*(K-3.0)/4.0);
cout<<"JB="<<JB<<endl;
}

#endif /* NORMAL_HPP_ */
