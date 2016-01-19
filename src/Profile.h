#ifndef PROFILE_H
#define PROFILE_H

#include <ctime>
#include <vector>
#include <string>

#include "Socket.h"

class Profile
{
  public:
    Profile( std::vector<std::tm> onTimes_, std::vector<std::tm> offTimes_,
             std::vector<Socket> sockets_, std::string owner_ );
    void setOnTime( std::vector<std::tm> onTimes_ );
    void setOffTime( std::vector<std::tm> offTimes_ );
    void addSocket( Socket s );
    int start(); // Accesspoint to start the time circle. Returns exit status.
  private:
    void switchSocketsOn();
    void switchSocketsOff();
    std::vector<std::tm> onTimes;
    std::vector<std::tm> offTimes;
    std::vector<Socket> sockets;
    std::string owner;
};

/*
 *
 *
 *
 *
 *
 *
 *
 */

std::tm tmFactory( int hour, int minute, int second );
std::tm *now();

#endif
