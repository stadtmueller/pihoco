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
#include <wiringPi.h>

int main()
{
    if( wiringPiSetup() != 0 )
	return 1;

    Socket s1( "10110", 1, 1 );

    while( true )
    {
	s1.on();
	delay( 1000 );
	s1.off();
	delay( 1000 );
    }
}
