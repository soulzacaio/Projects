# all: card deck pile aceFoundation kingFoundation game main.cpp
# 	g++ -pedantic-errors -g main.cpp card deck pile AceFoundation kingFoundation game -o main
# card: card.cpp card.h
# 	g++ -pedantic-errors -g -c card.cpp -o card
# deck: deck.cpp deck.h
# 	g++ -pedantic-errors -g -c deck.cpp -o deck
# pile: pile.cpp pile.h
# 	g++ -pedantic-errors -g -c pile.cpp -o pile
# aceFoundation: aceFoundation.cpp aceFoundation.h
# 	g++ -pedantic-errors -g -c aceFoundation.cpp -o aceFoundation
# kingFoundation: kingFoundation.cpp kingFoundation.h
# 	g++ -pedantic-errors -g -c kingFoundation.cpp -o kingFoundation
# game: game.cpp game.h
# 	g++ -pedantic-errors -g -c game.cpp -o game
CXX = g++
CXXFLAGS = -pedantic-errors -fdiagnostics-color=always -g

all: main

main: main.o deck.h card.o pile.o aceFoundation.o kingFoundation.o game.o
	$(CXX) $(CXXFLAGS) $^ -o $@

main.o: main.cpp deck.h card.h pile.o aceFoundation.o kingFoundation.o game.o
	$(CXX) $(CXXFLAGS) -c $< -o $@



card.o: card.cpp card.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

pile.o: pile.cpp pile.h deck.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

aceFoundation.o: aceFoundation.cpp aceFoundation.h deck.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

kingFoundation.o: kingFoundation.cpp kingFoundation.h deck.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

game.o: game.cpp game.h deck.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f main *.o