all: fsrs ltd

fsrs: FitStudioReg.o List.o Member.o
	g++ -Wall -o fsrs FitStudioReg.o List.o Member.o

ltd: ListTestDriver.o List.o Member.o
	g++ -Wall -o ltd ListTestDriver.o List.o Member.o

ListTestDriver.o: ListTestDriver.cpp List.h Member.h
	g++ -Wall -c ListTestDriver.cpp

FitStudioReg.o: FitStudioReg.cpp List.h Member.h
	g++ -Wall -c FitStudioReg.cpp

List.o: List.h List.cpp
	g++ -Wall -c List.cpp

Member.o: Member.h Member.cpp
	g++ -Wall -c Member.cpp

clean:
	rm -f ltd fsrs *.o