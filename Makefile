CC = g++ -std=c++11 -Wall -pthread
#CC = /home/mantosh/gcc-4.9.1/bin/g++ -std=c++1y -Wall -pthread
DFLAG = -g -gdwarf-2 
GTKMM = pkg-config gtkmm-3.0 --cflags --libs

ocalc: widget.o main.o expression.o common.o
	$(CC) $(DFLAG) widget.o main.o expression.o common.o -o ocalc `$(GTKMM)`

widget.o: widget.cpp
	$(CC) $(DFLAG) -c widget.cpp `$(GTKMM)`

main.o: main.cpp
	$(CC) $(DFLAG) -c main.cpp  `$(GTKMM)`

expression.o: expression.cpp
	$(CC) $(DFLAG) -c expression.cpp 

common.o: common.cpp
	$(CC) $(DFLAG) -c common.cpp  `$(GTKMM)`

clean: 
	rm -f *.o ocalc

