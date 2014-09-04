#include "MSNServer.h"


MSNServer *MSNServer::instance = new MSNServer();
MSNServer::DeleteInstance MSNServer::di = MSNServer::DeleteInstance();


MSNServer::MSNServer():version(0,0,0,0){
	// modules = map<string, Module*>();
	// listeners = list<MSNServerListener*>();
	// modules["jfdjf"] = new Module;
	// version = Version{0,0,0,0};
	// start();
}

MSNServer::~MSNServer() {
	cout<<"~MSNServer"<<endl;
}

void MSNServer::addServerListener(MSNServerListener* listener){
	listeners.push_back(listener);
}

void MSNServer::removeServerListener(MSNServerListener* listener){
	listeners.remove(listener);
}