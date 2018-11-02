#include <iostream>
using namespace std;
////////////////////////// override base methods ///////////////////////////////////////////////////
class B
{
public:
	virtual int DoIt() { return 99; }
};

class D : public B
{
public:
	virtual int DoIt() override;
};
int D::DoIt()  { return 88; }

class D2 : public D
{
public:
	int DoIt() override;
};
int D2::DoIt()  { return 77; }


void OverridePlay()
{
	B b;
	cout << "B do it: " << b.DoIt() << endl;
	/////
	D d;
	cout << "D do it: " << d.DoIt() << endl;
	B &bd = d;
	cout << "BD do it: " << bd.DoIt() << endl;
	/////
	D2 d2;
	cout << "D2 do it: " << d2.DoIt() << endl;
	B &bd2 = d2;
	cout << "BD2 do it: " << bd2.DoIt() << endl;
	D &dd2 = d2;
	cout << "dd2 do it: " << dd2.DoIt() << endl;

};