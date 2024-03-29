#include <iostream>
#include <string>

using namespace std;
class NegativeNumberException :std::exception
{
public:
	const char* what() const throw()
	{
		return "\nNumar negativ:\n";
	}
};