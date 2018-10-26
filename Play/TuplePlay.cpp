#include <tuple>
#include <iostream>
using std::cout;
using std::endl;

std::tuple<int, std::string> tester()
{
	return  std::tuple<int, std::string>(1, "abc");
}

void testerRun()
{
	auto x = tester();
	cout << "abc" << endl;

	auto [a, b] = tester();
	cout << a << " " << b << endl;
}
