CXX = g++
CXXFLAGS = -std=c++11 -g
OBJS = queue.o vampire.o barbarian.o bluemen.o medusa.o harryPotter.o character.o game.o fantasy.o menu.o
SRCS = queue.cpp vampire.cpp barbarian.cpp bluemen.cpp medusa.cpp harryPotter.cpp character.cpp game.cpp fantasy.cpp menu.cpp
HEADERS = queue.hpp vampire.hpp barbarian.hpp bluemen.hpp medusa.hpp harryPotter.hpp character.hpp game.hpp menu.hpp

fantasy:${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o fantasy

${OBJS}: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} -c ${@:.o=.cpp}

clean:
	rm *.o fantasy

zip:
	zip -D Fantasy_Tournament.zip *.cpp *.hpp *.pdf *.png makefile

val:
	valgrind --leak-check=full ./fantasy