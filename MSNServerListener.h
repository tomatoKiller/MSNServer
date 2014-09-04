#ifndef MSNSERVERLISTENER_H
#define MSNSERVERLISTENER_H

class MSNServerListener{
	virtual void serverStarted()=0;
	virtual void serverStopping()=0;
};

#endif