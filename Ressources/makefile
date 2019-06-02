CPFLAGS = -Wall -ansi -pedantic -std=c++11  -g
EXECUTABLE = Attribut.o Capteur.o Decision.o GestionCapteur.o GestionMesure.o Mesure.o Warning.o main.o
ENTETES = ../En-tete/*.h

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
