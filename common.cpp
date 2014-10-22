#include"common.h"

functionlogging::functionlogging(std::string x) :name(x) 
{
	std::cout << in << name <<"\n";
}

functionlogging::~functionlogging()
{
	std::cout << out << name <<"\n";
}

std::string functionlogging::in{ ">>" };
std::string functionlogging::out{ "<<" };


