/*
 * data_class.hpp
 *
 *  Created on: Feb 10, 2015
 *      Author: haotian
 */

#ifndef DATA_CLASS_HPP_
#define DATA_CLASS_HPP_

#include <iostream>
#include <string>
#include <stdlib.h>     /* atoi */

class data_A
{
public:
	std::string date_time;
	float price;
	int  volume;
	data_A(std::string date_time_,float price_, int volume_)
	{
		date_time=date_time_;
		price=price_;
		volume=volume_;
	}
    bool operator < (const data_A & my_data) const
    {
        for (int i=0; i < date_time.size();i++)
        {
        	//std::cout<<((date_time[i])<(my_data.date_time[i]))<<std::endl;
        	if ((date_time[i])<(my_data.date_time[i]))
        		return true;
        	if ((date_time[i])>(my_data.date_time[i]))
        	        		return false;
        }
        return false;
    	//return (price < my_data.price);
    }

};



#endif /* DATA_CLASS_HPP_ */
