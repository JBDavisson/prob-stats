CCC 		= g++
CCFLAGS 	= -g -Wall -std=c++14
SRC 		= ./src
BUILDDIR 	= ./build
OBJDIR 		= ./build/obj
OBJ 		= $(OBJDIR)/main.o
DEP 		= $(SRC)/utils.h $(SRC)/mathTypes.h
BIN 		= $(BUILDDIR)/test

$(BIN): $(OBJ)
	@echo 'Building executable: $(BIN)'
	@$(CCC) $(CCFLAGS) $(OBJ) -o $(BIN)
	@echo 'Creating symbolic link to executable in root project directory.'
	@ln -s build/test test
	
$(OBJDIR)/main.o: $(DEP)
	@echo 'Creating sub directories: $(OBJDIR) in root project directory.'
	@mkdir -p $(OBJDIR)
	@echo 'Building object file: $(OBJ)'
	@$(CCC) $(CCFLAGS) -c $(SRC)/main.cpp -o $(OBJDIR)/main.o

clean:
	@rm -f $(OBJDIR)/*.o
	@rm -f $(BIN)
	@rm -f ./test
	@echo 'Object files: $(OBJ), Symbolic link,'
	@echo 'and executable: $(BIN) removed from directory structure.'
	@rm -rf build
	@echo 'Removed directories: $(BUILDDIR) and $(OBJDIR)'
	@echo 'from root project directory.'

#