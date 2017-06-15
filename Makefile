CCC = g++
CCFLAGS = -g -Wall -std=c++11
OBJ = main.o 
DEP = utils.h mathTypes.h
BIN = test

$(BIN): $(OBJ)
	$(CCC) $(CCFLAGS) $(OBJ) -o $(BIN)
	
main.o: $(DEP)
	$(CCC) $(CCFLAGS) -c main.cpp -o main.o

#mathTypes.o: mathTypes.h
#	$(CCC) $(CCFLAGS) -c mathTypes.cpp -o mathTypes.o

clean:
	rm -f ./*.o
	rm -f ./$(BIN)
