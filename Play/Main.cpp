//============================================================================
// Name        : RangesV3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include "ThreadPlay.h"
#include <chrono>
#include <ctime>

using namespace std;
typedef  std::tuple<string, int> TSI;

using namespace std;
extern void testCount();
extern void bestAverageScore();
extern void dump3(vector<TSI>&);
void testAsynch();
extern void TemplatePlay();
extern void runBothAverageTests();
int PlayCppLinq ();

//////////////////////////////////////////////////////////
template<typename... Args>
auto sum(Args... args) {
	// Unary folding.
	return (... + args);
}

void FoldingExpressions()
{

	sum(1.0, 2.0f, 3); // == 6.0
}
/////////////////////////////////////////////////////////
void BraceListAutoDeduction()
{
	//auto x1{ 1, 2, 3 }; // error: not a single element
	auto x2 = { 1, 2, 3 }; // decltype(x2) is std::initializer_list<int>
	auto x3{ 3 }; // decltype(x3) is int
	auto x4{ 3.0 }; // decltype(x4) is double
}
/////////////////////////////////////////////////////////
constexpr auto addOne(int n) {
	  return [n] { return n + 1; };
}

void ConstExpressions()
{
	auto x1 = addOne(44);
	auto x2 = addOne(99);
	cout << "x is " << x1() << " and " << x2() << endl;
}
////////////////////////////////////////////////////////////
int main() {
 //runBothAverageTests();
	//runit();
	auto tot = PlayCppLinq();
	cout << tot << endl;
	//TemplatePlay();
	//FoldingExpressions();
	//BraceListAutoDeduction();
	//ConstExpressions();

}
