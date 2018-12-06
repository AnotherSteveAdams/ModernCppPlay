#if __cplusplus > 201402L
#include <range/v3/all.hpp>   //specific includes
#endif

#include "/lxhome/adamsste/dev/cpplinq/CppLinq/cpplinq.hpp"

//#include <range/v3/algorithm/count.hpp>   //specific includes
//#include <range/v3/view/group_by.hpp>   //specific includes
//#include <range/v3/action/sort.hpp>   //specific includes
//#include <range/v3/view/for_each.hpp>   //specific includes
#include <vector>
#include <iostream>
#include <string>
#include <list>
#include <tuple>

#include <numeric>
#include <functional>
#include <unordered_map>
using std::cout;
using std::vector;
using std::string;
using std::endl;
using std::get;
using std::unordered_map;
#if __cplusplus > 201402L
using ranges::v3::distance;
using ranges::v3::accumulate;
using ranges::v3::max;
using ranges::v3::view::transform;
using ranges::v3::action::sort;
using ranges::v3::view::transform;

//using ranges::v3::view::transform;
//using namespace std;
using namespace ranges::v3::view;
using namespace ranges::v3::action;

typedef  std::tuple<string, int> TSI;
// map of name, score pairs.

namespace a= ranges::v3::action;
namespace v= ranges::v3::view;
namespace v3=ranges::v3;

#endif
