#include "Profile.h"
#include "buttonReaction.h"
#include "Socket.h"

#include <thread>
#include <string>
#include <wiringPi.h>
#include <iostream>
#include <cstdlib>
// <ctime>, <vector>

#define DEBUG true

std::tm tmFactory( int hour, int minute, int second )
{
    std::tm tmInstance;

    tmInstance.tm_hour   = hour;
    tmInstance.tm_min = minute;
    tmInstance.tm_sec = second;

    return tmInstance;
}

std::tm *tmNow()
{
    std::time_t timestamp;
    std::tm *now;

    timestamp = std::time( 0 );
    now = localtime( &timestamp );

    return now;
}






Profile::Profile( std::vector<std::tm> onTimes_, std::vector<std::tm> offTimes_,
                  std::vector<Socket> sockets_, std::string owner_ ):
  onTimes( onTimes_ ),
  offTimes( offTimes_ ),
  sockets( sockets_ ),
  owner( owner_ )
{
    if( DEBUG )
        std::cout << "Created new profile with timePhases for " << this -> owner << std::endl;
}


void Profile::switchSocketsOn()
{
    for( Socket s : this -> sockets )
        s.on();
}


void Profile::switchSocketsOff()
{
    for( Socket s : this -> sockets )
        s.off();
}


void Profile::setOnTime( std::vector<std::tm> onTimes_ )
{
    onTimes = onTimes_;
}


void Profile::setOffTime( std::vector<std::tm> offTimes_ )
{
    offTimes = offTimes_;
}


void Profile::addSocket( Socket s )
{
    this -> sockets.push_back( s );
}


int Profile::start()
{
    // Validate profile here

    while( true ) // Repeat within a second | TODO: Do profiling here. If one cycle takes
                // longer than a second, timing is messed up
    {
        std::tm *now = tmNow(); // Update to actual time

        if( (now -> tm_wday == 0) || (now -> tm_wday == 6) ) // Saturday or Sunday? -> Skip!
        {
            delay( 700 ); // Don't sleep whole second here
            continue;
        }

        for( std::tm timePoint : onTimes ) // Is one of the timepoints from 'onTimes' equal to 'now'?
        {
            if( (timePoint.tm_hour == now -> tm_hour) &&
                (timePoint.tm_min == now -> tm_min) &&
                (timePoint.tm_sec == now -> tm_sec) )
            {
                this -> switchSocketsOn();
            }
        }

        for( std::tm timePoint : offTimes ) // Same here
        {
            if( (timePoint.tm_hour == now -> tm_hour) &&
                (timePoint.tm_min == now -> tm_min) &&
                (timePoint.tm_sec == now -> tm_sec) )
            {
                this -> switchSocketsOff();
            }
        }

    }

    return 0;

}
