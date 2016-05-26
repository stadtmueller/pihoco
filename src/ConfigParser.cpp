#include "ConfigParser.h"
#include "Socket.h"
#include "Profile.h"

#include <iostream>
#include <fstream>

ConfigParser::ConfigParser( std::string file_ ):
file( file_ )
{
    this -> profileBuffer = { };
}

std::vector<Profile> ConfigParser::getProfiles()
{
    if( this -> parse() )
    {
        std::cout << "Error reading config file" << std::endl;
        this -> good = false;
    }
    
    return this -> profileBuffer;
}

int ConfigParser::parse()
{
    std::ifstream f( (this -> file.c_str()) );
    std::string s = { };

    if( !f )
    {
	return 1;
    }

    char c;

    while( f.get( c ) )
    {
	s += c;
    }

    if( f.eof() )
    {
	f.clear();
    }

    f.close();

    std::cout << s << std::endl;

    return 0;
}

