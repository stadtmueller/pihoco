#include "ConfigParser.h"
#include "Socket.h"
#include "Profile.h"

#include <iostream>
#include <fstream>
#include <deque>

ConfigParser::ConfigParser( std::string file_ ):
file( file_ )
{
    this -> profileBuffer = { };
}

std::vector<Profile> ConfigParser::getProfiles()
{   
    return this -> profileBuffer;
}

int ConfigParser::parse()
{
    // Read and form the file:
    std::ifstream f( this -> file.c_str() );
    std::string s = { };
    std::string sBuf = { };
    std::deque<std::string> lines;

    if( !f )
    {
	return 1;
    }

    char c;

    while( f.get( c ) )
    {
	if( c == ' ' )
	    continue;
	else if( c != '\n' )
	    s += c;
	else
	{
	    lines.push_back( s );
	    s = "";
	}
    }

    if( f.eof() )
    {
	f.clear();
    }

    f.close();


    // Generate data from file content
    bool inProfile = false;
    std::deque<std::tm> onTimes;
    std::deque<std::tm> offTimes;
    std::deque<Socket> sockets;
    std::string owner;

    for( std::string l : lines )
    {
	if( l.find( '#' ) == 0 )
	    continue;

	if( l.find( "<Profile>" && !inProfile ) )
	    inProfile = true;

	if( l.find( "name" ) && inProfile )
	    owner = l;

	if( l.find( "</Profile>" ) )
	{
	    inProfile = false;
	    onTimes = { };
	    offTimes = { };
	    sockets = { };
	    owner = "";
	}
    }

    return 0;
}

