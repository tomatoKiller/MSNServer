#ifndef MSNSERVER_H
#define MSNSERVER_H
#include <iostream>
using namespace std;

class MSNServer {
public:

	int i;

	static MSNServer* getInstance() {
		// if(instance)
		return instance;
	}

	~MSNServer();

	void test() {
		cout<<sizeof(di)<<endl;
	}


private:
	MSNServer();
	
	

	class DeleteInstance{
	public:
		DeleteInstance() {
			cout<<"DeleteInstance Constructor"<<endl;
		}
		~DeleteInstance(){
			// cout<<"~DeleteInstance"<<endl;
			// delete MSNServer::instance;
			if (MSNServer::instance != nullptr)
			{
				cout<<"djfjd"<<endl;
				delete MSNServer::instance;
			}
		}
	};

	static DeleteInstance di;
	static MSNServer *instance;

};



#endif
