#include "MSNServer.h"


MSNServer *MSNServer::instance = new MSNServer();
MSNServer::DeleteInstance MSNServer::di = MSNServer::DeleteInstance();


MSNServer::MSNServer():version(0,0,0,0){
	// startDate = chrono::system_clock::now();
	// modules = map<string, Module*>();
	// listeners = list<MSNServerListener*>();
	// modules["jfdjf"] = new Module;
	// version = Version{0,0,0,0};
	start();
}

MSNServer::~MSNServer() {
	cout<<"~MSNServer"<<endl;
}

void MSNServer::start(){

	verifyDataSource();

	loadModules();
	initModules();
	startModules();

}


void MSNServer::addServerListener(MSNServerListener* listener){
	listeners.push_back(listener);
}


void MSNServer::removeServerListener(MSNServerListener* listener){
	listeners.remove(listener);
}


void MSNServer::loadModules(){

}


void MSNServer::loadModule(Module *mptr){
	modules[mptr->getName()] = shared_ptr<Module>(mptr);
}


void MSNServer::initModules(){
	for(auto module : modules)
		module.second->initialize(this);
}


void MSNServer::startModules(){
	for(auto module : modules)
		module.second->start();
}


void MSNServer::verifyDataSource(){

}