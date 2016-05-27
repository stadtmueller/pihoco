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


#include "buttonpress.h"
#include "Profile.h"
#include "Socket.h"
#include <iostream>
#include <vector>
#include <wiringPi.h>
#include <thread>

int main()
{
    std::cout << "Welcome to Pi-Remote controls" << std::endl;

    std::cout << "Setting up wiringPi..." << std::endl;

    // See additional/schema.png for details on the wiring

    if( wiringPiSetup() == -1 )
        return 1;

    piHiPri( 30 );

    pinMode( 2, OUTPUT );
    pinMode( 3, OUTPUT );
    pinMode( 21, OUTPUT );
    pinMode( 22, OUTPUT );
    pinMode( 23, OUTPUT );

    pinMode( 1, INPUT );
    wiringPiISR( 1, INT_EDGE_RISING, &button::shutdown );

    pinMode( 4, INPUT );
    wiringPiISR( 4, INT_EDGE_RISING, &button::pause48h );

    pinMode( 5, INPUT );
    wiringPiISR( 5, INT_EDGE_RISING, &button::masterButton );

    pinMode( 6, INPUT );
    wiringPiISR( 6, INT_EDGE_RISING, &button::button1Pressed );

    pinMode( 26, INPUT );
    wiringPiISR( 26, INT_EDGE_RISING, &button::button2Pressed );


    //
    //    CONFIGURATION - - - CONFIGURATION - - - CONFIGURATION
    //
    // Configure the following
    //   Timing:
    //     Add as many std::tm's to the on and off vectors as you need.
    //   Sockets:
    //     This is representing your power socket. Get their code from the DIP-switch.
    //     ( A = 1; B = 2; ... )
    //   Profiles:
    //     Add as many profiles as you've defined on/off vector pairs @ timing
    //

    /*

    ConfigParser parser( "profiles.conf" );

    if( parser.parse() )
    {
	std::cout << "Error parsing!" << std::endl;
	return 1;
    }

    std::vector<Profile> prof = parser.getProfile();

    */

    std::cout << "Setting up profiles..." << std::endl;

    // Profile 1:
    std::vector<std::tm> prof1On = { tmFactory( 12, 10, 00 ) };  // 18:00:00
    std::vector<std::tm> prof1Off = { tmFactory( 12, 11, 00 ) }; // 06:15:00

    Socket s1( "11111", 1, 1 );
    // ...

    std::vector<Socket> prof1Sockets = { s1 };


    Profile prof1( prof1On, prof1Off, prof1Sockets, "Tim" );

    //
    // End of configuration
    //


    std::cout << "Starting..." << std::endl;

    std::thread t1( [&prof1]{ prof1.start(); } );
    t1.join();

    return 0;
}
