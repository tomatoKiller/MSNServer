#ifndef MSNSERVER_H
#define MSNSERVER_H

#include <iostream>
#include <map>
#include <list>
#include <string>
#include <memory>
#include <chrono>
#include <ctime>
#include "module/Module.h"
#include "MSNServerListener.h"
#include "util/Version.h"
#include "util/DateTime.h"
#include "database/DBConnectionManager.h"

using namespace std;

class Module;

class MSNServer {
public:

	static MSNServer* getInstance() {
		// if(instance)
		return instance;
	}

	~MSNServer();

	void start();

	void addServerListener(MSNServerListener* listener);
	void removeServerListener(MSNServerListener* listener);

	// string getDataTimeString();
	

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

	map<string, shared_ptr<Module>> modules;

	list<MSNServerListener*> listeners;

	
	string name;
	string host;
	Version version;
	DateTime startDate;

	bool started;


	//Private Member function
	MSNServer();

	void loadModules();
	void loadModule(Module *);
	void initModules();
	void startModules();
	void verifyDataSource();

};



#endif
