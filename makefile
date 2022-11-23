CXX = g++
CFLAGS := -Wall -g
EXEC = food
SRCS := $(wildcard *.cpp)
OBJS := $(patsubst %.cpp,%.o,$(SRCS))
# List of object files needed to
# build the executable.
${EXEC}: ${OBJS}
	${CXX} ${CXXFLAGS} -o ${EXEC} ${OBJS}
menu.o: Menu.cpp Menu.h server_client.h
	${CXX} ${CXXFLAGS} -c Menu.cpp
Users.o: Users.cpp Users.h
	${CXX} ${CXXFLAGS} -c Users.cpp
location.o: location.cpp location.h
	${CXX} ${CXXFLAGS} -c location.cpp
Logger.o:Logger.cpp Logger.h
	${CXX} ${CXXFLAGS} -c Logger.cpp
main.o: main.cpp Menu.h location.h Users.h Logger.h
	${CXX} ${CXXFLAGS} -c main.cpp
clean:
	rm -f ${EXEC} ${OBJS}
