#include "Version.h"

Version::Version(int major, int minor, int micro, int statusVersion){
	major = major;
    minor = minor;
    micro = micro;
    statusVersion = statusVersion;
}

Version::~Version(){
	
}


string Version::getVersionString(){
	return versionString;
}

int Version::getMajor(){
	return major;
}

int Version::getMinor(){
	return minor;
}

int Version::getMicro(){
	return micro;
}

int Version::getStatusVersion(){
	return statusVersion;
}