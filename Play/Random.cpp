#include <random>
#include <iostream>
//extern constexpr auto addOne(int n);
//extern  auto addOneB(int n);

constexpr auto addOneB(int n) {
	  return n + 1;
}
using namespace std;

void RandomPlay() {
	{
		std::random_device rd;
		std::mt19937 mt(rd());
		std::uniform_real_distribution<double> dist(1.0, 10.0);

		//auto x = addOneB(333);
		for (int i=0; i<16; ++i)
		{
			auto r = dist(mt);
			cout << r << endl;
			cout << " addOneB:" << addOneB((int)dist(mt)) << endl;
//			cout << "  " << addOneB((int)1.23)
//			     << endl;
		}
	}
}
