#include<gtkmm.h>
#include <gtkmm/main.h>
#include<gtkmm/window.h>
#include<gtkmm/button.h>
#include<gtkmm/togglebutton.h>
#include<gtkmm/checkbutton.h>
#include<gtkmm/radiobutton.h>
#include<gtkmm/volumebutton.h>


#include<iostream>
#include<string>
#include<array>
#include<vector>
#include<list>
#include<map>
#include<set>
#include<thread>
#include<future>
#include<algorithm>
#include<memory>
#include<chrono>
#include<regex>

#include<cstring>
#include<cstdlib>
#include<forward_list>

#include<unordered_map>
#include<unordered_set>

#include<unistd.h>
#include<fstream>

#include<typeinfo>
#include<initializer_list>
#include<exception>
#include<stdexcept>
#include<system_error>

using namespace std::chrono;

template<typename T>
void display(const T& val)
{
	std::cout<<val<<"\n";
}



template<typename T>
void displaywithtab(const T& val)
{
	std::cout<<val<<"\t";
}



template<typename T>
void basicsdisplay(const T& val)
{
	std::cout<<val;
}





 // Generic class for tracing the function call
 class functionlogging 
{
 	private:
        std::string name;
        static std::string in;
        static std::string out;
 	public:
 	functionlogging(std::string);
 	~functionlogging();
};


//Define MACRO for easy use for end user.
#define LOG_ENTRY_EXIT_FOR(x)       functionlogging  SomeLongNameThatIsNotLikelyToBeUsedInTheFunctionlogger(x)
#define LOG_ENTRY_EXIT              LOG_ENTRY_EXIT_FOR(__func__)
