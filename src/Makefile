CXX=g++
FLAGS=-Wall -std=c++11 
LDFLAGS=-pthread -lwiringPi

all: main

main: main.o RCSwitch.o Socket.o Profile.o ConfigParser.o buttonpress.o
	$(CXX) -o main main.o RCSwitch.o Socket.o Profile.o ConfigParser.o buttonpress.o $(FLAGS) $(LDFLAGS)

main.o: main.cpp
	$(CXX) -c main.cpp $(FLAGS)

RCSwitch.o: RCSwitch.h RCSwitch.cpp
	$(CXX) -c RCSwitch.cpp $(FLAGS)

Socket.o: Socket.h Socket.cpp
	$(CXX) -c Socket.cpp $(FLAGS)

Profile.o: Profile.h Profile.cpp
	$(CXX) -c Profile.cpp $(FLAGS)

ConfigParser.o: ConfigParser.h ConfigParser.cpp
	$(CXX) -c ConfigParser.cpp $(FLAGS)

buttenpress.o: buttonpress.h buttonpress.cpp
	$(CXX) -c buttonpress.cpp $(FLAGS)


test: test.o Socket.o RCSwitch.o
	$(CXX) -o test test.o Socket.o RCSwitch.o $(FLAGS) $(LDFLAGS)

test.o: test.cpp
	$(CXX) -c test.cpp $(FLAGS)


clean:
	rm -f *.o main test
