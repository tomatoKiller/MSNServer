#ifndef VERSION_H
#define VERSION_H

#include <string>

using namespace std;

class Version{
public:
	Version(int major, int minor, int micro, int statusVersion);
	~Version();
	string getVersionString();
	int getMajor();
	int getMinor();
	int getMicro();
	int getStatusVersion();

private:
	int major;
	int minor;
	int micro;
	int statusVersion;
	string versionString; 
};

#endif