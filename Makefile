CCC = g++
CCFLAGS = -g -Wall -std=c++11
OBJ = main.o
DEP = utils.h
BIN = test

$(BIN): 
	$(CCC) $(CCFLAGS) main.cpp -o $(BIN)
	
#main.o: $(DEP)
#	$(CCC) $(CCFLAGS) main.cpp -o $(BIN)
	
clean:
	rm -f ./*.o
	rm -f ./$(BIN)
