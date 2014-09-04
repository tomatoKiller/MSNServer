#include <iostream>
#include "MSNServer.h"

using namespace std;



class A{
public:
	virtual void test(){cout<<"A"<<endl;}
};

class B:public A{
public:
	virtual void test(){cout<<"B"<<endl;}
};

void fun(A* a)
{
	a->test();
}

int main(int argc, char const *argv[])
{
	// B* b = new B();
	// fun(b);
	// auto server = MSNServer::getInstance();
	// server->i = 7;
	// auto ser77 = MSNServer::getInstance();
	// // cout<<ser77->i<<endl;
	// server->test();
	// // delete server;
	return 0;
}