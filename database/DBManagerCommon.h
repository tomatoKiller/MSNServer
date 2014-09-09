#ifndef DBMANAGERCOMMON_H
#define DBMANAGERCOMMON_H 

#include <vector>
#include <map>

namespace MSN_DBCMN {

	enum DBType {
		DBType_Mysql	
	};

	using DBMap = std::map<std::string, std::string>;
	using DBTable = std::vector<DBMap>;
	// typedef std::map<std::string, std::string> DBMap;
	// typedef std::vector<HiDBMap> DBTable;

	class DBException {
	public:
		DBException();

		std::string what();

		std::string		m_sql;			/**<  本次操作的SQL语句 */
		std::string		m_descript;		/**<  异常描述 */
		std::string		m_position;		/**<  异常位置 */
		long			m_errorId;		/**<  异常编号 */
		DBType			m_dbTyp;		/**<  数据库类型 */
	};

	/** @brief 异常语句宏 */
	#define DBHelperOnError(ps, script,sql, id) \
		DBException exception;\
		exception.m_position = ps;\
		exception.m_descript = script;\
		exception.m_sql = sql;\
		exception.m_errorId = id;\
		throw exception;\
		//return false;

}

#endif


