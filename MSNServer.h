#ifndef MSNSERVER_H
#define MSNSERVER_H

#include <iostream>
#include <map>
#include <list>
#include <string>
#include "Module.h"
#include "MSNServerListener.h"
#include "Version.h"

using namespace std;

class Module;

class MSNServer {
public:

	static MSNServer* getInstance() {
		// if(instance)
		return instance;
	}

	~MSNServer();

	void addServerListener(MSNServerListener* listener);
	void removeServerListener(MSNServerListener* listener);

	

	void test() {
		cout<<sizeof(di)<<endl;
	}


private:

	//Private Member variables
	
	// the only function of DeleteInstance is to delete instance pointer
	class DeleteInstance{
	public:
		DeleteInstance() {
			cout<<"DeleteInstance Constructor"<<endl;
		}
		~DeleteInstance(){

			if (MSNServer::instance != nullptr)
			{
				delete MSNServer::instance;
			}
		}
	};

	static DeleteInstance di;
	static MSNServer *instance;

	map<string, Module*> modules;

	list<MSNServerListener*> listeners;

	Version version;


	//Private Member function
	MSNServer();



};



#endif
