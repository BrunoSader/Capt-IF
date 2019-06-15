CPFLAGS = -Wall -ansi -pedantic -std=c++11  -g
EXECUTABLE = Attribut.o Capteur.o Decision.o GestionCapteur.o GestionMesure.o Mesure.o Warning.o LectureFichier.o
ENTETES = ../En-tete/*.h
EXECUTABLETEST = TestGestionCapteur.o TestGestionMesure.o TestWarning.o

captair : $(EXECUTABLE) main.o
	@echo "EDL"
	g++ -o captair $(EXECUTABLE) main.o

testing :$(EXECUTABLETEST) $(EXECUTABLE) mainTest.o
	@echo "EDL de Testing"
	g++ -o testing $(EXECUTABLE) $(EXECUTABLETEST) mainTest.o

mainTest.o :
	g++ -c $(CPPFLAGS) ../Source/mainTest.cpp

%.o : ../Source/%.cpp ../En-tete/%.h
	@echo "Compil de :$@"
	g++ -c $(CPFLAGS) $<

main.o : $(ENTETES)

clean :
	rm *.o

cleanTest :
	rm Test*.o
	rm mainTest.o

test :
	./captair AttributeType.csv Sensors.csv FichierTest.csv
