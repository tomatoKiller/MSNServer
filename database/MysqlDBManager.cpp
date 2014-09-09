#include "MysqlDBManager.h"
#include "DBCritical.h"
#include <regex>


namespace MSN_DBCMN {

	MysqlDBManager::MysqlDBManager(bool isUsingLock): DBManager(isUsingLock) {
		m_IsOpened = false;
	}

	MysqlDBManager::~MysqlDBManager() {
		if(m_IsOpened) {
			mysql_close(&m_Mysql);
		}
	}

	void MysqlDBManager::open(const char* Host, unsigned int Port, const char* User, 
		const char* Pass, const char* DBname, const char* Charset)  throw(DBException) {
		//Enter the critical section
		DBCriticalMng mng(m_pCritical);

		if (m_IsOpened) {
			return ;
		}

		// if (conn.length() == 0) {
		// 	HiDBHelperOnError("function Open", "connection string is empty", "", 0);
		// }

		// const std::regex pattern("host=([\\s\\S]+);port=");
		mysql_init(&m_Mysql);

		if (mysql_real_connect(&m_Mysql, Host, User, Pass, DBname, Port, NULL, 0))
		{
			m_IsOpened = true;

			string charsetString = string("set names ") + Charset;

			mysql_query(&m_Mysql, charsetString.c_str());

			return ;

		} else {
			long id = mysql_errno(&m_Mysql);
			const char* err = mysql_error(&m_Mysql);
			//关闭连接
			mysql_close(&m_Mysql);


			DBHelperOnError("function Open", err, "", id);
		}

	}

	void MysqlDBManager::close() {
		DBCriticalMng mng(m_pCritical);

		mysql_close(&m_Mysql);

		m_IsOpened = false;

	}

	bool MysqlDBManager::executeNoQuery(const string &conn) const {
		return false;
	}

	string MysqlDBManager::executeScalar(const string &conn) const {
		return "";
	}

	std::shared_ptr<DBTable> MysqlDBManager::executeQuery(const string &conn) const {
		return nullptr;
	}

	bool MysqlDBManager::releaseResultSet() {
		return false;
	}

}