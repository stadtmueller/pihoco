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
