/*
 * scrub.hpp
 *
 *  Created on: Feb 10, 2015
 *      Author: haotian
 */

#ifndef SCRUB_HPP_
#define SCRUB_HPP_
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>    // std::sort
#include "data_class.hpp"
#include <stdlib.h>     /* atoi */
using namespace std;

void Scrub(vector<data_A> data, vector<data_A> & signal, vector<data_A> & noise) {

	//sort(data.begin(),data.end());
	for ( unsigned i = 0 ; i < data.size() ; i++ )
	{
	       if (data[i].price< 500 ||data[i].price > 5000 )
	    	   noise.push_back(data[i]);
	       else
	    	   signal.push_back(data[i]);
	}
	//return make_tuple(signal,noise);

}




#endif /* SCRUB_HPP_ */
