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


std::vector<data_A> Read(std::string infilename) {
	std::vector<data_A> data;
	std:: ifstream infile(infilename.c_str());
	std::string date_time;
    float price;
    int volume;
    char date_time_C[40] ;
    char price_C[10] ;
    char volume_C[10] ;
    int i;
    if (infile.is_open())
                    {
                            while (infile.good())
                            {
                                    infile.getline(date_time_C, 256, ',');
                                    infile.getline(price_C, 256, ',');
                                    infile.getline(volume_C, 256, '\n');
                                    date_time=(std::string)(date_time_C);
                                    price=atof(price_C);
                                    volume=atoi(volume_C);
                                    //cout<<date_time<<" "<<price<<" "<<volume<<endl;
                                    data.push_back(data_A(date_time, price,volume)) ;
                                    i++ ;
                            }
                            infile.close();
                    }
                    else
                    {
                    	std:: cout << "Error opening file";
                    }
    return data;
}

void Write(std::vector<data_A> signal)
{

}



#endif /* PARSE_CSV_HPP_ */
