//#include "precompiled.h"
#include <vector>
#include <iostream>
#include <string>
#include <list>
#include <tuple>

#include <range/v3/view/filter.hpp>   //specific includes
#include <range/v3/view/group_by.hpp>   //specific includes
#include <range/v3/action/sort.hpp>
namespace a= ranges::v3::action;
namespace v= ranges::v3::view;

//int oldAverage(vector<TSI> &scores);
//int newAverage(vector<TSI> &scores);
//int newAveragePlay(vector<TSI> &scores);
auto scores = std::vector<std::tuple<std::string, int>> {
		{"Steve", 100},
		{"John", 12},
		{"Steve", 33},
		{"John", 55},
		{"Steve", 77},
		{"John", 84},
		};

void CompileTimeTest()
{
	auto averageScores1 =
			a::sort(scores)
			 | v::filter     ([](auto a)         { return std::get<1>(a) > 50;})
			 | v::group_by   ([](auto a, auto b) { return std::get<0>(a)== std::get<0>(b);}) // Group by name
	;

	for (auto xx2 : averageScores1)
	{
		for (auto xx3 : xx2)
		{
		   std::cout << "here" << std::get<0>(xx3) << "=" << std::get<1>(xx3)  << std::endl;
		}
	}

//	auto averageScores1a =
//			a::sort(scores)
//			 | v::filter     ([](auto a)         { return std::get<1>(a) > 50;})
//			 | v::group_by   ([](auto a, auto b) { return std::get<0>(a)== std::get<0>(b);}) // Group by name
//	;
//	auto averageScores1b =
//			a::sort(scores)
//			 | v::filter     ([](auto a)         { return std::get<1>(a) > 50;})
//			 | v::group_by   ([](auto a, auto b) { return std::get<0>(a)== std::get<0>(b);}) // Group by name
//	;
//	auto averageScores1c =
//			a::sort(scores)
//			 | v::filter     ([](auto a)         { return std::get<1>(a) > 50;})
//			 | v::group_by   ([](auto a, auto b) { return std::get<0>(a)== std::get<0>(b);}) // Group by name
//	;

//	auto averageScores2 =
//			a::sort(scores)
//			 | v::filter     ([](auto a)         { return get<1>(a) > 50;})
//			 | v::group_by   ([](auto a, auto b) { return get<0>(a)== get<0>(b);}) // Group by name
//	;
//	auto averageScores3 =
//			a::sort(scores)
//			 | v::filter     ([](auto a)         { return get<1>(a) > 50;})
//			 | v::group_by   ([](auto a, auto b) { return get<0>(a)== get<0>(b);}) // Group by name
//	;
//	auto averageScores2a =
//			a::sort(scores)
//			 | v::filter     ([](auto a)         { return get<1>(a) > 50;})
//			 | v::group_by   ([](auto a, auto b) { return get<0>(a)== get<0>(b);}) // Group by name
//	;
//	auto averageScores3a =
//			a::sort(scores)
//			 | v::filter     ([](auto a)         { return get<1>(a) > 50;})
//			 | v::group_by   ([](auto a, auto b) { return get<0>(a)== get<0>(b);}) // Group by name
//	;
//	auto averageScores2b =
//			a::sort(scores)
//			 | v::filter     ([](auto a)         { return get<1>(a) > 50;})
//			 | v::group_by   ([](auto a, auto b) { return get<0>(a)== get<0>(b);}) // Group by name
//	;
//	auto averageScores3b =
//			a::sort(scores)
//			 | v::filter     ([](auto a)         { return get<1>(a) > 50;})
//			 | v::group_by   ([](auto a, auto b) { return get<0>(a)== get<0>(b);}) // Group by name
//	;

}
//void runOneTest(int (*testerFunc)(vector<TSI> &f), int iterations)
//{
//
//	////////////////////////////////////////////////////////////////
//	auto start = std::chrono::system_clock::now();
//	for (int i =0; i<iterations; i++)
//		testerFunc(scores);
//	cout << "old done" << endl;
//	auto end = std::chrono::system_clock::now();
//
//	std::chrono::duration<double> elapsed_seconds = end-start;
//	std::time_t end_time = std::chrono::system_clock::to_time_t(end);
//
//	std::cout << "finished computation at " << std::ctime(&end_time)
//			  << "elapsed time: " << elapsed_seconds.count() << "s\n";
//}
//
//
//void runBothAverageTestsPerformance()
//{
//	const int iterations = 10000;
//
//	runOneTest(oldAverage, iterations);
//	runOneTest(newAverage, iterations);
//}
//
//
//void runBothAverageTests()
//{
//	auto o = oldAverage(scores);
//	auto n = newAverage(scores);
//	auto x = newAveragePlay(scores);
//	cout << o << n << x ;
//}
//
//
//int oldAverage(vector<TSI> &scores)
//{
//	unordered_map<string, vector<int>> studentsToScores;
//	for (auto scoreRow : scores)
//	{
//		string student = std::get<0>(scoreRow);
//		int score = std::get<1>(scoreRow);
//
//		// find student in list
//		unordered_map<string, vector<int>>::iterator iter =
//				studentsToScores.find(student);
//		if (iter == studentsToScores.end())
//		{
//			vector<int> currentScores;
//			currentScores.push_back(score);
//			studentsToScores.insert(make_pair(student, currentScores));
//		}
//		else
//		{
//			iter->second.push_back(score);
//		}
//	}
//	// get average and max
//	double max = -99999;
//	for(auto mapElem : studentsToScores)
//	{
//		int sum = 0;
//		for (int i : mapElem.second)
//		{
//			sum += i;
//		}
//		double average = sum / (double)mapElem.second.size();
//		if (average > max) max = average;
//	}
//	return static_cast<int>(floor(max));
//}
//
//int newAverage(vector<TSI> &scores)
//{
//
//	auto averageScores =
//			a::sort(scores)
//		     | v::group_by   ([](auto a, auto b) { return get<0>(a)== get<0>(b);}) // Group by name
//		     | v::transform  ([](auto ax1)     {
//				return make_tuple (      // Transform into names and average scores
//					get<0>(v3::index(ax1, 0)),    // Name
//
//					accumulate(ax1, 0, [](auto pa, auto pb) { return pa + get<1>(pb); })
//		     	 	 	 / distance(ax1) // Average
//				); });
//
//	auto bestScores = ranges::v3::max(averageScores, [](auto p1, auto p2)
//			{ return std::get<1>(p1) < std::get<1>(p2); });
//
//	return 1;// std::get<1>(bestScores);
//}
//
//
//int newAveragePlay(vector<TSI> &scores)
//{
//	auto scores2 = vector<TSI> {
//			{"Steve", 100},
//			{"John", 12},
//			{"Steve", 33},
//			{"John", 55},
//			{"Steve", 77},
//			{"John", 84},
//			};
//
//	auto s2 = scores2 | v::filter     ([](auto a)         { return get<1>(a) > 10;});
//
//	cout << "************* newAveragePlay dump 1 ***************" << endl;
//	for (auto xx2 : s2)
//		cout << std::get<0>(xx2) << "=" << std::get<1>(xx2) << endl;
//
//	cout << "************* newAveragePlay dump 2 ***************" << endl;
//	for (auto xx2 : scores2)
//		cout << std::get<0>(xx2) << "=" << std::get<1>(xx2) << endl;
//
//	auto averageScores =
//		a::sort(scores)
//		 | v::filter     ([](auto a)         { return get<1>(a) > 50;})
//		 | v::group_by   ([](auto a, auto b) { return get<0>(a)== get<0>(b);}) // Group by name
//		 | v::transform  ([](auto ax1)     {
//			return make_tuple (      // Transform into names and average scores
//					// get<0>(v3::index(ax1, 0)),    // Name
//				//v3::index(ax1, 0),    // Name
//					ax1,
//				v3::accumulate(ax1, 0, [](auto pa, auto pb) { return pa + get<1>(pb); })
//					 / ranges::v3::distance(ax1) // Average
//			); });
//
//
//	cout << "************* newAveragePlay dump 2a ***************" << endl;
//	for (auto xx2 : averageScores)
//	{
//		auto a1 = std::get<0>(xx2);
//		//auto name = v3::index(a1, 0);
//
//		for (auto xx3 : a1)
//		   cout << std::get<0>(xx3) << "=" << std::get<1>(xx3) << endl;
//	}
//	auto bestScores = max(averageScores, [](auto p1, auto p2)
//			{ return std::get<1>(p1) < std::get<1>(p2); });
//

//	auto averageScores3x =
//			a::sort(scores)
//			 | v::filter     ([](auto a)         { return get<1>(a) > 50;})
//			 | v::group_by   ([](auto a, auto b) { return get<0>(a)== get<0>(b);}) // Group by name
//	;
//	auto averageScores3x1 =
//			a::sort(scores)
//			 | v::filter     ([](auto a)         { return get<1>(a) > 50;})
//			 | v::group_by   ([](auto a, auto b) { return get<0>(a)== get<0>(b);}) // Group by name
//	;
//	auto averageScores3x2 =
//			a::sort(scores)
//			 | v::filter     ([](auto a)         { return get<1>(a) > 50;})
//			 | v::group_by   ([](auto a, auto b) { return get<0>(a)== get<0>(b);}) // Group by name
//	;
//	auto averageScores3x3 =
//			a::sort(scores)
//			 | v::filter     ([](auto a)         { return get<1>(a) > 50;})
//			 | v::group_by   ([](auto a, auto b) { return get<0>(a)== get<0>(b);}) // Group by name
//	;
//	auto averageScores3x4 =
//			a::sort(scores)
//			 | v::filter     ([](auto a)         { return get<1>(a) > 50;})
//			 | v::group_by   ([](auto a, auto b) { return get<0>(a)== get<0>(b);}) // Group by name
//	;
//	auto averageScores3b =
//			a::sort(scores)
//			 | v::filter     ([](auto a)         { return get<1>(a) > 50;})
//			 | v::group_by   ([](auto a, auto b) { return get<0>(a)== get<0>(b);}) // Group by name
//	;
//	auto averageScores3xb =
//			a::sort(scores)
//			 | v::filter     ([](auto a)         { return get<1>(a) > 50;})
//			 | v::group_by   ([](auto a, auto b) { return get<0>(a)== get<0>(b);}) // Group by name
//	;
//	auto averageScores3x1b =
//			a::sort(scores)
//			 | v::filter     ([](auto a)         { return get<1>(a) > 50;})
//			 | v::group_by   ([](auto a, auto b) { return get<0>(a)== get<0>(b);}) // Group by name
//	;
//	auto averageScores3x2b =
//			a::sort(scores)
//			 | v::filter     ([](auto a)         { return get<1>(a) > 50;})
//			 | v::group_by   ([](auto a, auto b) { return get<0>(a)== get<0>(b);}) // Group by name
//	;
//	auto averageScores3x3b =
//			a::sort(scores)
//			 | v::filter     ([](auto a)         { return get<1>(a) > 50;})
//			 | v::group_by   ([](auto a, auto b) { return get<0>(a)== get<0>(b);}) // Group by name
//	;
//	auto averageScores3x4b =
//			a::sort(scores)
//			 | v::filter     ([](auto a)         { return get<1>(a) > 50;})
//			 | v::group_by   ([](auto a, auto b) { return get<0>(a)== get<0>(b);}) // Group by name
//	;
////			 | v::transform  ([](auto ax1)     {
////				return
////					v3::accumulate(ax1, 0, [](auto pa, auto pb) { return pa + get<1>(pb); })
////						 / ranges::v3::distance(ax1) // Average
////				; });
//
//
//		cout << "************* newAveragePlay dump 3 ***************" << endl;
//		for (auto xx2 : averageScores3)
//		{
//			for (auto xx3 : xx2)
//			{
//			   cout << "here" << std::get<0>(xx3) << "=" << std::get<1>(xx3)  << endl;
//			}
//		}
//		return 1;
		////////////////////////////////////////////////////////////////////////////////////////////////////////
//		auto averageScores4 =
//				a::sort(scores)
//				 | v::filter     ([](auto a)         { return get<1>(a) > 50;})
//				 | v::group_by   ([](auto a, auto b) { return get<0>(a)== get<0>(b);}) // Group by name
//
//					 | v::transform  ([](auto ax1)     {
//						return
//							v3::accumulate(ax1, 0, [](auto pa, auto pb) { return pa + get<1>(pb); })
//								 / ranges::v3::distance(ax1) // Average
//						; });
//
//
//		cout << "************* newAveragePlay dump 4  ***************" << endl;
//		for (auto xx2 : averageScores4)
//		{
//			// for (auto xx3 : xx2)
//			{
//			   cout << "here" << xx2  << endl;
//			}
//		}
//
//		//cout << "maxxx is " << std::get<0>(bestScores) << " and his average score is " << std::get<1>(bestScores) <<  endl;

//	cout << "************* by2 dump ***************" << endl;
//	for (auto xx2 : averageScores)
//		cout << std::get<0>(xx2) << "=" << std::get<1>(xx2) << endl;
	// auto x = bestScores[0];
	//return std::get<1>(bestScores);
////////////////}
//
//
//void dumpPlay()
//{
//	cout << "***************************************************" << endl;
//	cout << "creating by2" << endl;
//
//	// using namespace ranges::v3::action;
//	auto by2 = sort(scores)
//		| group_by([] (TSI a, TSI b) { return std::get<0>(a)== std::get<0>(b);})
//		| ranges::v3::view::transform([](auto ax1) {
////			for(auto ax2 : ax1) {
////				cout << " by2 d" << std::get<0>(ax2) << endl;
////
////					cout << "first  " << std::get<0>( ax2) << endl;
////				//auto first =  a | ranges::v3::view::take(1);
////				//string txt = std::get<0>( first);
////
////			}
//
//		auto s2 = ax1 | ranges::v3::view::take(1);
//		ranges::for_each(s2, [] (auto s2a) { cout << "for_each: " <<  std::get<0>(s2a) << ":" <<  std::get<1>(s2a) << endl; });
//
//		auto s2e = ranges::v3::index(ax1, 0);
//		cout << "s2e" << std::get<0>(s2e);
//
//		auto name = std::get<0>(ranges::v3::index(ax1, 0));
//		cout << "name:" << name << endl;
//
//		const auto counter = ranges::v3::distance(ax1);
//		cout << "count:" << counter << endl;
//
//		//auto s3 = std::get<0>(s2);
//			return new std::tuple<string, int> (
//				name,//std::get<0>(ax1 | ranges::v3::view::take(1)), //"f",//std::get<0>( first),
//				ranges::v3::accumulate(ax1, 0, [](auto pa, auto pb) { return pa + std::get<1>(pb); })
//					 / ranges::v3::distance(ax1)
//			);
//	})
//	;
//
//	cout << "************* by2 dump ***************" << endl;
//	for (auto xx2 : by2)
//		cout << std::get<0>(*xx2) << "=" << std::get<1>(*xx2) << endl;
//	cout << "************* by2 dump done ***************" << endl;
//}
//
//void bestAverageScorePlay()
//{
//
//	auto by = ranges::v3::action::sort(scores) | group_by([]
//             (TSI a, TSI b)
//			{
//				return std::get<0>(a)== std::get<0>(b);
//			});
//
////	auto t = new  std::tuple<string, int> { "a",3};
////
//
//	//auto averages = ranges::v3::view::ints(1) | ranges::v3::view::transform([](auto x) { return x;});
//
////	auto averages = by | ranges::v3::view::transform([](auto x) {
////		return ranges::v3::accumulate(x, 0, [](auto pr) { return std::get<1>(pr); });
////	});
////	cout << "================================== averages =======================================" << endl;
////	for (auto a : averages)
////		cout << "  99 average: " << a << endl;
//	auto compare = [](auto a1, auto b1) { return std::get<1>(a1) < std::get<1>(b1); };
//
//	cout << "==================================== max =======================================" << endl;
//	auto m =  max(scores, compare );
//	cout << "max score" << std::get<0>(m) << " " << std::get<1>(m) << endl;
//	auto m2 =  max(by, [compare](auto a, auto b)
//			{
//				return max(a, compare )
//				      < max(b, compare);
//			});
//	//cout << "max by **" << std::get<0>(m2) << " " << std::get<1>(m2) << endl;
//
//	auto test = scores[2];
//	cout << "==================================" << endl;
//	cout << "get from scores: "  << std::get<0>(test) << "=" << std::get<1>(test) << endl;
//	cout << "==================================" << endl;
//
//	//auto test2 = by[2];
//	//cout << std::get<0>(test2);
//	cout << "get from by" << endl;
////
//	for (auto x : by)
//	{
//		// decltype(x) xt;
//		cout << "  --" << endl;
//		auto total = ranges::v3::accumulate(x, 0, [](auto pa, auto pb) { return pa +  std::get<1>(pb); });
////		auto xp6 = std::accumulate(x.begin(), x.end(),
////		                                    0, // start with first element
////		                                    [](std::string a, int b) {
////		                                        return a + '-' + std::to_string(b);
////		                                    });
//
//		cout << "  total=" << total << endl;
//		for (auto y : x)
//		{
//
//			cout << "  " << std::get<0>(y) << " " << std::get<1>(y) << endl;
//		}
//	}
//	cout << "==================================" << endl;
////	RANGES_FOR(auto x, by)//, [] (auto x)
////			{
////				//cout << x << endl;
////			}
//
////	for (auto xa : by)
////		//for (auto xb : xa)
////			cout << "h" << std::get<1>(xa) << endl;
//
//	cout << "***************** vector l max sum *******************" << endl;
//	auto l = vector<int> {2,1,2,2,3};
//	auto m1 = max(l);
//	auto suml = std::accumulate(l.begin(), l.end(), 0, [](int sum_a, int sum_b) {return sum_a + sum_b;});
//	cout << " max is " << m1 << " suml = " << suml << endl;
//	for (auto al : l)
//		cout << al << endl;
//	cout << "sorting" << endl;
//
//	ranges::v3::action::sort(l);
//	for (auto al : l)
//		cout << al << endl;
//
//	auto x = ranges::v3::action::sort(l)
//			| group_by([] (int a, int b) { return a == b;});
//
//	cout << "==================================" << endl;
//	for (auto xa : x)
//		cout << xa << endl;
//}
//
//void testCount() {
//
//  std::vector<int> v { 6, 2, 3, 4, 5, 6 };
//  //note the count return is a numeric type
//  //like int or long -- auto below make sure
//  //it matches the implementation
//  auto c = ranges::count( v, 6 );
//  cout << "vector:   " << c << "\n";
//
//  std::array<int, 6> a { 6, 2, 3, 4, 5, 6 };
//  c = ranges::count( a, 6 );
//  cout << "array:    " << c << "\n";
//}

///[count]
