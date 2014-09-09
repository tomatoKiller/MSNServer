#include "DBManagerCommon.h"
#include <sstream>

namespace MSN_DBCMN {

	DBException::DBException() {
		m_errorId	= 0;
		m_dbTyp		= DBType_Mysql;
	}

	std::string DBException::what() {
		std::stringstream helperstr;
		helperstr<<"DBException :" 
				<<" DBType: " << m_dbTyp 
				<<" Position: " << m_position 
				<<" SQL: " << m_sql 
				<<" Description :" << m_descript 
				<<" Error ID: " << m_errorId;

		return helperstr.str();
	}

}