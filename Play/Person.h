/*
 * Person.h
 *
 *  Created on: 15 Oct 2018
 *      Author: adamsst
 */
#ifndef PERSON_H_
#define PERSON_H_
#include <string>

class Person {
public:
	Person(int i, std::string name)
		{
		 _i = i;
		 _name = name;
		}

	~Person();

private:	int _i;
public:  	int getI() const	{ return _i;}

private:	std::string _name;
public:		std::string getName() const	         {return _name;}
public:		void setName(const std::string name) {_name = name;}

};

#endif /* PERSON_H_ */
