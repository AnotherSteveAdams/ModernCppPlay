//============================================================================
// Name        : RangesV3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
//#include <tuple>
#include <string>
#include "ThreadPlay.h"
//#include <chrono>
//#include <ctime>

using namespace std;
typedef  std::tuple<string, int> TSI;

using namespace std;
extern void testCount();
extern void bestAverageScore();
extern void dump3(vector<TSI>&);
void testAsynch();
extern void TemplatePlay();
extern void runBothAverageTests();
extern void OverridePlay();
extern void FoldingExpressionsPlay();
extern void BraceListAutoDeduction();
extern void ConstExpressions();
extern void DeclTypeAutoReturnExpressions();
extern void PointerPlay();
int PlayCppLinq ();


/////////////////////////////////////////////////////////////////////////////

int main() {
	auto v = vector<string> {"abc", "def"};
 //runBothAverageTests();
	//runit();
//	auto tot = PlayCppLinq();
//	cout << tot << endl;
	//TemplatePlay();
	//FoldingExpressionsPlay();
	//BraceListAutoDeduction();
	//ConstExpressions();
    //GeneralAutoPlay();
	//OverridePlay();
	//PointerPlay();
	//PlayCppLinq();
}
