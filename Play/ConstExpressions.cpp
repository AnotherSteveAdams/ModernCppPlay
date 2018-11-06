#include <iostream>
using namespace std;
//////////////////////// Const Expressions /////////////////////////////////
constexpr auto addOne(int n) {
	  return [n] { return n + 1; };
}
//
//auto addOneB(int n) {
//	  return [n] { return n + 1; };
//}

void ConstExpressions()
{
	auto x1 = addOne(44);
	auto x2 = addOne(99);
	cout << "x is " << x1() << " and " << x2() << endl;
}
