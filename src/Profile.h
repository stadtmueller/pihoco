/*  pihoco - Pi-Home-Controler : Control remote sockets
 *  Copyright (C) 2016  Tim Stadtmueller
 *
 *  pihoco is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  pihoco is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with pihoco.  If not, see <http://www.gnu.org/licenses/>.
 */


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
 */

std::tm tmFactory( int hour, int minute, int second );
std::tm *now();

#endif
