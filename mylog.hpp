/*
 * mylog.hpp
 *
 *  Created on: Feb 16, 2015
 *      Author: haotian
 */

#ifndef MYLOG_HPP_
#define MYLOG_HPP_
#include <log4cpp/Category.hh>
#include <log4cpp/PropertyConfigurator.hh>
class InitLogging{

public:

	static log4cpp::Category&  getRoot(){
		std::string initFileName = "log4cpp.properties";
				log4cpp::PropertyConfigurator::configure(initFileName);
				return log4cpp::Category::getRoot();
	}


};





#endif /* MYLOG_HPP_ */
