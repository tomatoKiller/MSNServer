#include "DateTime.h"

DateTime::DateTime() {
	datetime = chrono::system_clock::now();
}

string DateTime::getDateTimeString(){
	auto t = chrono::system_clock::to_time_t(datetime);
	char mbstr[100];
	if(strftime(mbstr, sizeof(mbstr), "%Y-%m-%d %H:%M:%S", localtime(&t))){
		return string(mbstr);
	} else 
		return "";

}
