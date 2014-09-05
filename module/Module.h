#ifndef MODULE_H
#define MODULE_H

#include <string>
#include "../MSNServer.h"

using namespace std;

class MSNServer;

class Module{
	
public:
	Module(string name){
		this->name = name;
	}
	string getName(){return name;}
	virtual void initialize(MSNServer* server)=0;
	virtual void start()=0;
	virtual void stop()=0;
	virtual void destroy()=0;

private:
	string name;
};

#endif