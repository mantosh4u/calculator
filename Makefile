CC = g++ -std=c++11 -Wall -pthread
DFLAG = -g -gdwarf-2 
GTKMM = pkg-config gtkmm-3.0 --cflags --libs

ocalc: widget.o main.o
	$(CC) $(DFLAG) widget.o main.o -o ocalc `$(GTKMM)`

widget.o: widget.cpp
	$(CC) $(DFLAG) -c widget.cpp `$(GTKMM)`

main.o: main.cpp
	$(CC) $(DFLAG) -c main.cpp  `$(GTKMM)`

clean: 
	rm -f *.o ocalc
