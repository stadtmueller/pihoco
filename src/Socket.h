#ifndef SOCKET_H
#define SOCKET_H

#include "RCSwitch.h"
#include <string>

class Socket : public RCSwitch
{
    public:
        Socket( std::string systemCode_, int unitCode_, int id_ );
	void off();
	void on();
	void toggle();
    private:
	std::string systemCode;
	int unitCode;
	int id;
	int state;
};

#endif
