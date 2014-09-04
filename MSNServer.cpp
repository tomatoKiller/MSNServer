#include "MSNServer.h"

MSNServer *MSNServer::instance = new MSNServer();
MSNServer::DeleteInstance MSNServer::di = MSNServer::DeleteInstance();

MSNServer::MSNServer(){
	// di = DeleteInstance();
}

MSNServer::~MSNServer() {
	cout<<"~MSNServer"<<endl;
}