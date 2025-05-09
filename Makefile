CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
INCLUDES = -I. -Itests

# Testavimas
test: tests/RO5testas.cpp tests/PapildomiTestai.cpp studentas.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) tests/RO5testas.cpp tests/PapildomiTestai.cpp studentas.cpp -o testai
	./testai

# Pagrindinė programa
run: funkcijos.cpp studentas.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) funkcijos.cpp studentas.cpp -o programa
	./programa

# Išvalyti sukurtus failus
clean:
	rm -f testai programa