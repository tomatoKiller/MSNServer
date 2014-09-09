#ifndef DBCRITICAL_H
#define DBCRITICAL_H 
#include <memory>

namespace MSN_DBCMN {
	class DBCritical
	{
	public:
		DBCritical(){}
		~DBCritical(){}
	
		void Enter(){}
		void Leave(){}
	};

	class DBCriticalMng
	{
	public:
		DBCriticalMng(std::shared_ptr<DBCritical> ptr):m_pDBCritical(ptr) {
			m_pDBCritical->Enter();
		}
		~DBCriticalMng() {
			m_pDBCritical->Leave();
		}
	
	private:
		std::shared_ptr<DBCritical> m_pDBCritical;
	};
}

#endif


