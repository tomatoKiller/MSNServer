#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <memory>
#include <string>
#include "DBManagerCommon.h"
#include "DBCritical.h"

namespace MSN_DBCMN {
	// using DBMap = std::map<std::string, std::string>;
	// using DBTable = std::vector<HiDBMap>;

	using std::string;

	class DBManager{

	public:
		DBManager(bool isUsingLock) {

			m_pCritical = nullptr;

			if (isUsingLock) {
				m_pCritical = std::make_shared<DBCritical>();
			}
		}
		// ~DBManager();
		// ~DBConnectionManager();

		virtual void  open(const char* Host, unsigned int Port, const char* User, 
		const char* Pass, const char* DBname, const char* Charset="utf-8") throw(DBException) = 0;

		virtual void close() = 0;

		virtual bool executeNoQuery(const std::string &conn) const = 0;

		virtual std::string executeScalar(const std::string &conn) const= 0;	

		virtual std::shared_ptr<DBTable> executeQuery(const std::string &conn) const= 0;

		virtual bool releaseResultSet() = 0;

	protected:
		
		std::shared_ptr<DBCritical> m_pCritical;

	};

}

#endif