/*
 * Pointers.cpp
 *
 *  Created on: 3 Nov 2018
 *      Author: adamsst
 */

#include "Person.h"
#include <iostream>
#include <memory>
using namespace std;

void PointerPlay()
{
	{
		//Person p2(88, "Jacob Adams");
		auto ptr = std::make_unique<Person>(99, "Steve Adams");
		cout << ptr->getName() << endl;
		//ptr.reset(); // will call delete on the underlying object.
		auto p = ptr.get();
		p->setName("another name");
		cout << "end of block" << p->getName()  << endl;
	}
	cout << "Finishing" << endl;
}



