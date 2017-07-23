CCC 		= g++
CCFLAGS 	= -g -Wall -std=c++14
SRC 		= ./src
BUILDDIR 	= ./build
OBJDIR 		= ./build/obj
OBJ 		= $(OBJDIR)/main.o 
DEP 		= $(SRC)/utils.h $(SRC)/mathTypes.h
BIN 		= $(BUILDDIR)/test

$(BIN): $(OBJ)
	$(CCC) $(CCFLAGS) $(OBJ) -o $(BIN)
	ln -s build/test test
	
$(OBJDIR)/main.o: $(DEP)
	$(CCC) $(CCFLAGS) -c $(SRC)/main.cpp -o $(OBJDIR)/main.o

clean:
	rm -f $(OBJDIR)/*.o
	rm -f $(BIN)
	rm -f ./test