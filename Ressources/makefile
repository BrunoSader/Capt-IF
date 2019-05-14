CPFLAGS = -Wall -ansi -pedantic -std=c++11  -g
EXECUTABLE = main.o Warning.o
ENTETES = ../En-tete/Warning.h

captair : $(EXECUTABLE)
	@echo "EDL"
	g++ -o captair $(EXECUTABLE)

%.o : ../Source/%.cpp ../En-tete/%.h
	@echo "Compil de :$@"
	g++ -c $(CPFLAGS) $<

main.o : $(ENTETES)

clean :
	rm *.o

run :
	./captair
