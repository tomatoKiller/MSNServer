class ConnectionProvider
{
public:
	bool isPooled()=0;
	MYSQL getConnection()=0;
	void start()=0;
	void restart()=0;
	void destroy()=0;
};