#include <tuple>
#include <iostream>
using std::cout;
using std::endl;

std::tuple<int, std::string> tester()
{
	return  std::tuple<int, std::string>(1, "abc");
}

void TuplePlay()
{
	cout << "TuplePlay" << endl;

	auto x = tester();
	cout << std::get<1>(x) << endl;

	auto [a, b] = tester();
	cout << a << " " << b << endl;

	auto t2 = new std::tuple<int, double>(5,55.55);

}
