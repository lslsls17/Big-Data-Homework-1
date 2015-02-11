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


void Scrub(std::vector<data_A> data, std::vector<data_A> & signal,std:: vector<data_A> & noise) {

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
