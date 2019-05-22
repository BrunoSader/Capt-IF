PC = g++ -g -ansi -pedantic -Wall -std=c++11


demo : Attribut.o Capteur.o Decision.o GestionCapteur.o GestionMesure.o Mesure.o main.o
	$(PC) -o demo  Attribut.o Capteur.o Decision.o GestionCapteur.o GestionMesure.o Mesure.o main.o

Attribut.o : ../Source/Attribut.cpp ../En-tete/Attribut.h
	@echo "compil de Attribut \<Attribut.cpp\>"
	$(PC) -c  ../Source/Attribut.cpp

Capteur.o : ../Source/Capteur.cpp ../En-tete/Capteur.h
	@echo "compil de Capteur \<Capteur.cpp\>"
	$(PC) -c  ../Source/Capteur.cpp

Decision.o : ../Source/Decision.cpp ../En-tete/Decision.h
	@echo "compil de Decision \<Decision.cpp\>"
	$(PC) -c  ../Source/Decision.cpp

GestionCapteur.o : ../Source/GestionCapteur.cpp ../En-tete/GestionCapteur.h 
	@echo "compil de GestionCapteur \<GestionCapteur.cpp\>"
	$(PC) -c  ../Source/GestionCapteur.cpp

GestionMesure.o : ../Source/GestionMesure.cpp ../En-tete/GestionMesure.h
	@echo "compil de GestionMesure \<GestionMesure.cpp\>"
	$(PC) -c  ../Source/GestionMesure.cpp

Mesure.o : ../Source/Mesure.cpp ../En-tete/Mesure.h
	@echo "compil de Mesure \<Mesure.cpp\>"
	$(PC) -c  ../Source/Mesure.cpp

main.o : ../Source/main.cpp ../En-tete/main.h ../En-tete/Mesure.h ../En-tete/GestionMesure.h ../En-tete/GestionCapteur.h ../En-tete/Decision.h ../En-tete/Capteur.h ../En-tete/Attribut.h
	@echo "compil de main \<../Source/main.cpp\>"
	$(PC) -c  ../Source/main.cpp

clean :
	rm *.o demo
