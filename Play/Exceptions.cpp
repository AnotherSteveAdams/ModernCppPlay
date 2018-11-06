/*
 * Exceptions.cpp
 *
 *  Created on: 4 Nov 2018
 *      Author: adamsst
 */

#include <exception>
#include <iostream>
#include "Person.h"
#include <thread>

using namespace std;
void a()
{
	cout << " throwing 99" << endl;
//	throw 99;
//	throw std::range_error("You're always making mistakes");
}
void b()
{
	Person p(123,"Michael");
	a();
}
void c()
{
	b();
}
void ExceptionPlay()
{
	std::set_terminate([](){ cout << "Termination handler" << endl;});
	try {
		b();
	}
	catch (std::range_error & e) {
		cout << e.what() << endl;
	}
	catch (std::exception & e) {
		cout << e.what() << endl;
	}
	catch (int i){
		cout << i << endl;
	}
	while(true)
	{
		using namespace std::chrono_literals;
		std::this_thread::sleep_for(4s);
		cout << "sleeping" << endl;
	}
}

