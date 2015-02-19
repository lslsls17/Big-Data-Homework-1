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
#include <thread>
#include "mylog.hpp"
#include <fstream>
//#include </usr/lib/mpich/include/mpi.h>

using namespace std;


int main(int argc, char *argv[]) {
	log4cpp::Category& root = InitLogging::getRoot();

	int signal_size;
	if (strcmp(argv[1], "SCRUB") == 0) {
		cout << "SCRUBING" <<" "<< argv[2] <<"!"<< endl;
		signal_size = Scrub(argv[2]);
		 Write_Size(signal_size);
	} else if (strcmp(argv[1], "NORMAL") == 0) {
		cout << "TEST NORMALING" << endl;
		double JB_normal, JB_log_normal;
		signal_size=Read_Size();
		JB_normal = Test_Normal("signal.txt", signal_size);
		JB_log_normal = Test_Log_Normal("signal.txt",  signal_size);
		std::ostringstream os;
		if (JB_normal < JB_log_normal) {
			os << "Sample is more like normal than log normal ";
			root.info(os.str());
		} else {
			os << "Sample is more like log normal than normal ";
			root.info(os.str());
		}
		remove("signal.txt");
		remove("noise.txt");
	} else {
		root.error("Please to input: ./main SCRUB  [data_name.txt]   and than input:   ./main NORMAL   as first argument");
	}

}

/*
int main() {
	log4cpp::Category& root = InitLogging::getRoot();
	int signal_size;


	cout << "SCRUBING" << endl;
	signal_size = Scrub("data100k.txt");
	cout << "TEST NORMALING" << endl;
	double JB_normal, JB_log_normal;
	JB_normal = Test_Normal("signal.txt", signal_size);
	JB_log_normal = Test_Log_Normal("signal.txt", signal_size);
	std::ostringstream os;
	if (JB_normal < JB_log_normal) {
		os << "Sample is more like normal than log normal :";
		root.info(os.str());
	} else {
		os << "Sample is more like log normal than normal :";
		root.info(os.str());
	}
		remove("signal.txt");
		remove("noise.txt");
}
*/
/*
 int main() {
 int signal_size;
 int rank=0;
 int size=0;
 MPI_Init (NULL, NULL);
 MPI_Comm_rank (MPI_COMM_WORLD, &rank);
 MPI_Comm_size (MPI_COMM_WORLD, &size);
 //int first_i = (rank ) / 26;
 //int second_i = (rank ) % 26;
 //char first_c = first_i + 'a';
 //char second_c = second_i + 'a';
 //std::ostringstream os;
 //os << "bulk" << first_c << second_c;

 // Get the name of the processor
 char processor_name[MPI_MAX_PROCESSOR_NAME];
 int name_len;
 MPI_Get_processor_name(processor_name, &name_len);

 // Print off a hello world message
 printf("Hello world from processor %s, rank %d"
 " out of %d processors\n",
 processor_name, rank, size);

 // Finalize the MPI environment.
 MPI_Finalize();


 //string sourceFile = os.str();

 signal_size=Scrub("data100k.txt");
 //cout<<"Signal.txt"<<endl;
 Test_Normal("signal.txt",signal_size);


 //root.error("[Wrong] need to input Task (SCRUB/NORMAL) as first param");

 }
 */
