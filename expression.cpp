#include"expression.h"

int expression::evalute() {
	int first{};
	int second{};
	auto posplus = _input.find("+");
	if(posplus != std::string::npos) {
		first  = std::stoi(_input.substr(0,posplus));
		second = std::stoi(_input.substr(posplus+1));
	}
	return (first + second);
}

