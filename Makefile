CC   = g++ -g --std=c++11
COMPILE.C  = $(CC) -c 
VPATH   = ./database:./util:./module
CXXFLAGS  =  -lgcc_s 
MAKEEXE   = $(CC) $(LDFLAGS)

OBJ   = main.o MSNServer.o DBConnectionManager.o Version.o DateTime.o
EXE   = MSNServer

all:   $(EXE)

$(EXE):   ${OBJ}
	$(MAKEEXE) $^ -o $@
%.o:   %.cpp
	$(COMPILE.C) $< -o $@
clean:
	rm -f *.o $(EXE) core 