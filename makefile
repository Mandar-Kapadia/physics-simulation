CC =g++
CFLAGS = -Wall -Werror -pedantic --std=c++17
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
DEPS = CelestialBody.h Universe.h
all:NBody style
%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS)  -I/opt/homebrew/Cellar/sfml/2.5.1_1/include -c $<

NBody: main.o CelestialBody.o Universe.o
	$(CC) $(CFLAGS)  -L/opt/homebrew/Cellar/sfml/2.5.1_1/lib -o $@ $^ $(LIBS)
clean:
	rm -f *.o 
	rm -f NBody
style:
	cpplint --filter=-runtime/references,-build/header_guard --extensions=cpp,hpp,h Universe.cpp
	cpplint --filter=-runtime/references,-build/header_guard --extensions=cpp,hpp,h Universe.h
	cpplint --filter=-runtime/references,-build/header_guard --extensions=cpp,hpp,h CelestialBody.cpp
	cpplint --filter=-runtime/references,-build/header_guard --extensions=cpp,hpp,h CelestialBody.h
	cpplint --filter=-runtime/references,-build/header_guard --extensions=cpp,hpp,h main.cpp