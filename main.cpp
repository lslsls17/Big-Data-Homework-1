//============================================================================
// Name        : Big_Data_Assignment_A.cpp
// Author      : Haotian Wu
// Version     :
// Copyright   : Copy Riget Reserved by Haotian Wu
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Parse_Csv.hpp"
#include "scrub.hpp"
#include "data_class.hpp"
#include "normal.hpp"
using namespace std;

int main() {

	vector<data_A> noise;
	vector<data_A> signal;
	Scrub(Read("data10k.txt"), signal,  noise);
	/*
	sort(signal.begin(),signal.end());
	for ( unsigned i = 0 ; i < signal.size() ; i++ )
	{
		cout<<signal[i].price<<endl;
	}
*/
	Test_Normal(signal);
	Test_Log_Normal(signal);


	return 0;
}
