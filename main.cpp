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

	string filename;
	int signal_size=Scrub("data10k.txt");
	Test_Normal("signal.txt",signal_size);
	//Test_Log_Normal("signal.txt",signal_size);


	return 0;
}
