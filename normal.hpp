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
#include <algorithm>    // std::sort
#include "data_class.hpp"
#include <stdlib.h>     /* atoi */
using namespace std;

void Test_Normal(std::vector<data_A>  signal) {
double S;
double K;
double JB;
double x_mean=0;
int n=signal.size();
for(int i=0; i<n;i++)
{
	x_mean=x_mean*i/(i+1)+double(signal[i].price)/(i+1);
}
cout<<"x_mean="<<x_mean<<endl;
double x_2_sum=0;
double x_3_sum=0;
double x_4_sum=0;
for(int i=0; i<n;i++)
{
	x_2_sum=x_2_sum*i/(i+1)+pow(x_mean-double(signal[i].price),2.0)/(i+1);
	x_3_sum=x_3_sum*i/(i+1)+pow(x_mean-double(signal[i].price),3.0)/(i+1);
	x_4_sum=x_4_sum*i/(i+1)+pow(x_mean-double(signal[i].price),4.0)/(i+1);
}
S=x_3_sum/pow(x_2_sum,1.5);
K=x_4_sum/pow(x_2_sum,2.0);
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
JB=double(n)/6.0*(S*S+(K-3.0)*(K-3.0)/4.0);
cout<<"JB="<<JB<<endl;
}

#endif /* NORMAL_HPP_ */
