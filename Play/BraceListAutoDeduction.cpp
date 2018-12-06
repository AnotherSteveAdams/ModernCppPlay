#include <initializer_list>
#include <iostream>

using namespace std;
///////////////////////// Brace list auto expressions ////////////////////////////////
void BraceListAutoDeduction()
{
	//auto x1{ 1, 2, 3 }; // error: not a single element
	auto x2 = { 1, 2, 3 }; // decltype(x2) is std::initializer_list<int>
	auto x3{ 3 }; // decltype(x3) is int
	auto x4{ 3.0 }; // decltype(x4) is double
	for (auto &x : x2)
		cout << x << endl;
	// not sure why this doesn't work ! - cout << " " << x3 << " " << x4 << endl;
}

