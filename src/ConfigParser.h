#ifndef CONFIGPARSER_H
#define CONFIGPARSER_H

#include "Profile.h"
#include <string>
#include <vector>

class ConfigParser
{
    public:
	ConfigParser( std::string file_ );
	std::vector<Profile> getProfiles();
        int parse();
    private:
	std::string file
	std::vector<Profile> profileBuffer;
	
#endif
