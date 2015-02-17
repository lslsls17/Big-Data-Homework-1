//============================================================================
// Name        : Big_Data_Assignment_A.cpp
// Author      : Haotian Wu
// Version     :
// Copyright   : Copy Riget Reserved by Haotian Wu
// Description : Hello World in C++, Ansi-style
//============================================================================
//#include "mylog.hpp"
#include <iostream>
#include "Parse_Csv.hpp"
#include "scrub.hpp"
#include "data_class.hpp"
#include "normal.hpp"
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <sstream>
#include </usr/lib/mpich/include/mpi.h>
#include <thread>

using namespace std;


int main(int argc, char *argv[]) {
	//log4cpp::Category& root = InitLogging::getRoot();
	int signal_size;
	if (argc == 2) {
		if (strcmp(argv[1], "SCRUB") == 0) {
			int rank=0;
			int size=0;
				 MPI_Init (&argc, &argv); /* starts MPI */
				 MPI_Comm_rank (MPI_COMM_WORLD, &rank); /* get current process id */
				 MPI_Comm_size (MPI_COMM_WORLD, &size); /* get number of processes */
			int first_i = (rank ) / 26;
			int second_i = (rank ) % 26;
			char first_c = first_i + 'a';
			char second_c = second_i + 'a';
			std::ostringstream os;
			os << "bulk" << first_c << second_c;
			cout<<os<<endl;
			//string sourceFile = os.str();

			//signal_size=Scrub(sourceFile);
			cout<<"Signal.txt"<<endl;
		}
		if (strcmp(argv[1], "NORMAL") == 0) {
			Test_Normal("signal.txt",signal_size);
		}
	}else{
		//root.error("[Wrong] need to input Task (SCRUB/NORMAL) as first param");
	}
}

/*
int main() {
	log4cpp::Category& root = InitLogging::getRoot();
	int signal_size;
			signal_size=Scrub("data10k.txt");
			Test_Normal("signal.txt",signal_size);


		//root.error("[Wrong] need to input Task (SCRUB/NORMAL) as first param");

}
*/
