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


#include "Socket.h"
#include "RCSwitch.h"

#include <iostream>

Socket::Socket( std::string systemCode_, int unitCode_, int id_ ):
  systemCode( systemCode_ ),
  unitCode( unitCode_ ),
  id( id_ )
{
    std::cout << "Created new socket with system code " << systemCode
              << " and unit code " << unitCode << std::endl;

    state = -1;

    setPulseLength( 300 );
    enableTransmit( 0 );
}

void Socket::off()
{
    std::cout << id << ": Off" << std::endl;
    state = 0;
    switchOff( systemCode, unitCode );
}

void Socket::on()
{
    std::cout << id << ": On" << std::endl;
    state = 1;
    switchOn( systemCode, unitCode );
}

void Socket::toggle()
{
    std::cout << "Toggle: ";

    switch( state )
    {
        case 0: this -> on(); break;
        case 1: this -> off(); break;
        case -1: std::cout << "State has never been set. Nothing to toggle." << std::endl;
    }
}
