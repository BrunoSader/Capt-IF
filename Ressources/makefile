CPFLAGS = -Wall -ansi -pedantic -std=c++11  -g
EXECUTABLE = ../Executable/main.o ../Executable/Warning.o
ENTETES = ../En-tete/Warning.h

../Executable/captair : $(EXECUTABLE)
	@echo "EDL"
	g++ -o captair $(EXECUTABLE)

../Executable/%.o : ../Source/%.cpp ../En-tete/%.h
	@echo "Compil de :$@"
	g++ -c $(CPFLAGS) $<

../Executable/main.o : $(ENTETES)

clean :
	rm ../Executable/*.o

run :
	../Executable/captair
