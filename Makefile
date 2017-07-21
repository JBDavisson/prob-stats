CCC 	= g++
CCFLAGS = -g -Wall -std=c++11
SRC 	= ./src
OBJDIR 	= ./obj
OBJ 	= $(OBJDIR)/main.o 
DEP 	= $(SRC)/utils.h $(SRC)/mathTypes.h
BIN 	= test

$(BIN): $(OBJ)
	$(CCC) $(CCFLAGS) $(OBJ) -o $(BIN)
	
./obj/main.o: $(DEP)
	$(CCC) $(CCFLAGS) -c $(SRC)/main.cpp -o $(OBJDIR)/main.o

#mathTypes.o: mathTypes.h
#	$(CCC) $(CCFLAGS) -c mathTypes.cpp -o mathTypes.o

clean:
	rm -f $(OBJDIR)/*.o
	rm -f ./$(BIN)
