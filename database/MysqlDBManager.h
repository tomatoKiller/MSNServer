#ifndef MYSQLDBMANAGER_H
#define MYSQLDBMANAGER_H 

#include "DBManager.h"
#include "DBManagerCommon.h"
#include <string>
#include <mysql/mysql.h>

namespace MSN_DBCMN {

	using std::string;

	class MysqlDBManager: public DBManager {
		

	public:

		MysqlDBManager(bool isUsingLock);
		~MysqlDBManager();
	
	public:

		void open(const char* Host, unsigned int Port, const char* User, 
		const char* Pass, const char* DBname, const char* Charset) throw(DBException);

		void close();

	public:

		bool executeNoQuery(const string &conn) const override ;

		string executeScalar(const string &conn) const override;	

		std::shared_ptr<DBTable> executeQuery(const string &conn) const override;

		bool releaseResultSet() override;

	private:

		bool m_IsOpened;

		// MYSQL*				m_pSQLData;
		MYSQL			m_Mysql;
		// string			m_Host;
		// string			m_Port;
		// string			m_DBname;
		// string			m_User;
		// string			m_Charset;
		// string			m_Pass;
	};
}

#endif

