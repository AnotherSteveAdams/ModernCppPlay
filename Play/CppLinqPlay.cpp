#include "precompiled.h"
//#include "/home/adamsst/cpplinq/CppLinq/cpplinq.hpp"

#include <vector>
#include <iostream>
#include <string>
#include <list>
#include <tuple>

#include <numeric>
#include <functional>

using std::cout;
using std::vector;
using std::string;
using std::endl;
using std::get;
using std::unordered_map;

typedef  std::tuple<string, int> TSI;

int PlayCppLinq ()
{
    using namespace cpplinq;
    int ints[] = {3,1,4,1,5,9,2,6,5,4};

    string s("abc");
#if __cplusplus > 201402L
    // Computes the sum of all even numbers in the sequence above
    auto total =
            from_array (ints)
        |  where ([](int i) {return i%2 ==0;})     // Keep only even numbers
        |  sum ()                                  // Sum remaining numbers
        ;



    auto scores = vector<TSI> {
    		{"Steve", 100},
    		{"John", 12},
    		{"Steve", 33},
    		{"John", 55},
    		{"Steve", 77},
    		{"John", 84},
    		};

    auto lam = []{cout << "in lambda" << endl;    };

    lam();

    auto something =
    		    from_iterators(scores.begin(), scores.end())
			|           where([](TSI s)  { return std::get<1>(s) < 80;})
			|          select([](TSI s)  { return std::get<0>(s);})
			|         orderby([](auto s) { return s;})
			|       to_vector();


    auto somethingElse =
    		    from_iterators(scores.begin(), scores.end())
			|           where([](TSI s)  { return std::get<1>(s) < 80;})
			|          select([](TSI s)  { return std::get<0>(s);})
			|         orderby([](auto s) { return s;})
			|       to_vector();


    auto somethingElse2 =
    		    from_iterators(scores.begin(), scores.end())
			|           where([](TSI s)  { return std::get<1>(s) < 80;})
			|          select([](TSI s)  { return std::get<0>(s);})
			|         orderby([](auto s) { return s;})
			|       to_vector();


    auto somethingElse3 =
    		    from_iterators(scores.begin(), scores.end())
			|           where([](TSI s)  { return std::get<1>(s) < 80;})
			|          select([](TSI s)  { return std::get<0>(s);})
			|         orderby([](auto s) { return s;})
			|       to_vector();


    //auto something =
    		from_iterators(scores.begin(), scores.end())
    | where ([](TSI s) { return std::get<1>(s) < 80;})
    | select([](TSI s) { return std::get<0>(s);})
	//| for_each([](string s) { cout << "  got an " << s << endl;})
	//| to_vector()
	;
    for (auto x: something)
    	cout << "t>" << x << endl;
    return total;
#endif
}
