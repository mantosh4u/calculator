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

