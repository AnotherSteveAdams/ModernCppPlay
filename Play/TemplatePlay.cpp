#include <vector>
#include <functional>
#include <map>
#include <iostream>

#include "Person.h"

using std::cout;
using namespace std;
template<typename T, typename X>
std::map<X, std::vector<T>>* ToDictionary(std::vector<T> v, std::function<X(T)> f)
{
	auto v2 = new std::map<X, std::vector<T>>();
	for(auto y:v)
		(*v2)[f(y)].push_back(y);

	return v2;
}

// overload person so it can be dumped out easily for cout.
ostream& operator<<(ostream& cx, const Person& p)
{
	cx << p.getI() << " " << p.getName();
   return cx;
}

// Overload map so it can be dumped out easily to cout.
template<typename T1,typename T2>
ostream& operator<<(ostream& cx, const std::map<T1,T2>& map)
{
	for( auto  [key, val] : map )
	{
		std::cout << "Key:" << key << endl;
		for (auto entry : val) std::cout << "  " <<  entry << endl;
	}
	// cx << p.getI() << " " << p.getName();
   return cx;
}

void TemplatePlay()
{
	cout <<  " starting " << endl;
	auto l = new std::vector<Person> {
		{1, "steve"},
		{1, "peter"},
		{1, "michael"},
		{2, "john"},
		{4, "john"},
	};
	auto d = ToDictionary<Person, std::string>(*l, [] (auto person)->auto { return person.getName(); });
	cout << "iterating..." << *d << endl;

	auto amap = std::map<std::string, string>();

	// cout << " all of l " << *l << endl;
	for( auto  [key, val] : *d )
	{
		std::cout << "Key:" << key << endl;

//		for (auto person : val)
//			std::cout << "   " << person.getI() << endl;

		/// cout << " and by the overload" << endl;
		for (auto person : val) std::cout << "  " <<  person << endl;
	}
//	for (auto h : d)
//	{
//		std::cout << "x " << std::get<0>(h) << endl;
//		for (auto name : std::get<1>(h))
//			std::cout << "   " << name.getName() << endl;
//	}
}
