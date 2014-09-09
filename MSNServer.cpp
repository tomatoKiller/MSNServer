#include "MSNServer.h"


MSNServer *MSNServer::instance = new MSNServer();
MSNServer::DeleteInstance MSNServer::di = MSNServer::DeleteInstance();


MSNServer::MSNServer():version(0,0,0,0){
	dbManager = make_shared<MSN_DBCMN::MysqlDBManager>(true);
	// startDate = chrono::system_clock::now();
	// modules = map<string, Module*>();
	// listeners = list<MSNServerListener*>();
	// modules["jfdjf"] = new Module;
	// version = Version{0,0,0,0};
	start();
}

MSNServer::~MSNServer() {
	// cout<<"~MSNServer"<<endl;
	dbManager->close();
}

void MSNServer::start(){

	try {
		verifyDataSource();
	} catch (MSN_DBCMN::DBException e) {
		cout<<e.what()<<endl;
		exit(1);
	}
	

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


void MSNServer::verifyDataSource() throw(MSN_DBCMN::DBException) {
	
	dbManager->open("localhost", 3306, "root", "123", "jfinal_demo");


}