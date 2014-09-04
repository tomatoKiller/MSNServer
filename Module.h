#ifndef MODULE_H
#define MODULE_H

#include <string>
#include "MSNServer.h"

using namespace std;

class MSNServer;

class Module{
	// string name
	virtual string getName()=0;
	virtual void initialize(MSNServer* server)=0;
	virtual void start()=0;
	virtual void stop()=0;
	virtual void destroy()=0;
};

#endif