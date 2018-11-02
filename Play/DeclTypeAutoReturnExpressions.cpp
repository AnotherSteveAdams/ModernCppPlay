#include <iostream>
using namespace std;
/////////////////////// decltype auto return expressions /////////////////////////////////////

template <typename T1, typename T2>
auto compose(T1 t1, T2 t2) //-> decltype(t1 + t2)  << in 14 you don't need to declare the retunr type like this it can work it out if all
// return types have expressions with the same type.
{
   return t1+t2;
}

void DeclTypeAutoReturnExpressions()
{
	auto v = compose(2, 3.14);
	cout << "a 1 :" << v << std::endl;
}
