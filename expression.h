#include<string>

class expression
{
public:
	expression(const std::string& x): _input(x) {}
	int evalute();
private:
	std::string _input;
};
