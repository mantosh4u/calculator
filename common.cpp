#include"common.h"

std::string functionlogging::in{ ">>" };
std::string functionlogging::out{ "<<" };


functionlogging::functionlogging(std::string x) 
:name(x) {
	std::cout << in << name <<"\n";
}

functionlogging::~functionlogging() {
	std::cout << out << name <<"\n";
}


//Define MACRO for easy use for end user.
//#define LOG_ENTRY_EXIT_FOR(x)       functionlogging  widgetlogger(x)
//#define LOG_ENTRY_EXIT              LOG_ENTRY_EXIT_FOR(__func__)




