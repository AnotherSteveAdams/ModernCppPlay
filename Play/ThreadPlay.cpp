/*
 * ThreadPlay.cpp
 *
 *  Created on: 11 Mar 2018
 *      Author: adamsst
 */

#include "ThreadPlay.h"
#include <iostream>
#include <future>
#include <vector>
#include <algorithm>
#include <future>
#include <numeric>
#include <chrono>

using namespace std;


void testAsynch()
{
	ThreadPlay p;
	p.AsynchPlay();
}

ThreadPlay::ThreadPlay() {
	// TODO Auto-generated constructor stub

}

ThreadPlay::~ThreadPlay() {
	// TODO Auto-generated destructor stub
}


int parallel_sum2(int a, int b)
{
	return a + b;
 //return 12;
}

template <typename RandomIt>
int parallel_sum(RandomIt beg, RandomIt end)
{
	using namespace std::chrono_literals;
	cout << "parallel_sum" << endl;
	std::this_thread::sleep_for(2s);
	return std::accumulate(beg, end, 0);
}

void ThreadPlay::AsynchPlay()
{
	std::vector<int> l(10000,2);
	//auto total = std::async(std::launch::async, parallel_sum2, 5, 6);

	auto handle = std::async(std::launch::async,
			parallel_sum<std::vector<int>::iterator>, l.begin(), l.end());

	cout << "waiting..." << endl;

	auto result = handle.get();

	cout << "total = " << result << endl;

}
