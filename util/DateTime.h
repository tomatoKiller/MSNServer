#ifndef DATETIME_H
#define DATETIME_H

#include <chrono>
#include <string>
using namespace std;

class DateTime{
public:
	DateTime();
	// ~DateTime();

	string getDateTimeString();
private:

	chrono::time_point<chrono::system_clock> datetime;
};

#endif