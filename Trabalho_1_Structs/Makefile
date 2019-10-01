all: project

project: main.o nice_holidays.o utilities.o menu.o packs.o clients.o
			g++ main.o nice_holidays.o  utilities.o  menu.o packs.o clients.o -o nice


main.o : main.cpp nice_holidays.cpp utilities.cpp menu.cpp packs.cpp clients.cpp
			g++ -c main.cpp 

nice_holidays.o: nice_holidays.cpp nice_holidays.cpp utilities.cpp menu.cpp packs.cpp clients.cpp
				g++ -c nice_holidays.cpp 

utilities.o: nice_holidays.cpp utilities.cpp menu.cpp packs.cpp clients.cpp
		g++ -c utilities.cpp 

menu.o: nice_holidays.cpp utilities.cpp menu.cpp packs.cpp clients.cpp
		g++ -c menu.cpp

clients.o: nice_holidays.cpp utilities.cpp menu.cpp packs.cpp clients.cpp
		g++ -c clients.cpp

packs.o: nice_holidays.cpp utilities.cpp menu.cpp packs.cpp clients.cpp
		g++ -c packs.cpp
clean: 
		rm -rf *o nice

