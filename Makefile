output: main.o Person.o Customer.o Bartender.o Drink.o Alcoholic.o Non-Alcoholic.o Food.o Menu.o 
	g++ main.o Person.o Customer.o Bartender.o Drink.o Alcoholic.o Non-Alcoholic.o Food.o Menu.o  -o output

main.o: main.cpp
	g++ -c main.cpp

Person.o: Person.cpp Person.h
	g++ -c Person.cpp 

Customer.o: Customer.cpp Customer.h
	g++ -c Customer.cpp

Bartender.o: Bartender.cpp Bartender.h
	g++ -c Bartender.cpp

Drink.o: Drink.cpp Drink.h
	g++ -c Drink.cpp

Alcoholic.o: Alcoholic.cpp Alcoholic.h
	g++ -c Alcoholic.cpp	

Non-Alcoholic.o: Non-Alcoholic.cpp Non-Alcoholic.h
	g++ -c Non-Alcoholic.cpp	

Food.o: Food.cpp Food.h
	g++ -c Food.cpp	

Menu.o: Menu.cpp Menu.h
	g++ -c Menu.cpp

clean:
	rm *.o output		