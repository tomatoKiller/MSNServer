#include <iostream>
#include "MSNServer.h"

using namespace std;

int fun()
{
	static int i = 0;
	i++;
	cout<<i<<endl;
}

int main(int argc, char const *argv[])
{
	auto server = MSNServer::getInstance();
	server->i = 7;
	auto ser77 = MSNServer::getInstance();
	// cout<<ser77->i<<endl;
	server->test();
	// delete server;
	return 0;
}