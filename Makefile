CC   = g++ -g --std=c++11
CXXFLAGS  =  -lmysqlclient 
COMPILE.C  = $(CC) -c 
VPATH   = ./database:./util:./module
# LDFLAGS += -L/usr/lib/x86_64-linux-gnu
# LDFLAGS += -lmysqlclient
MAKEEXE   = $(CC) $(LDFLAGS) 

OBJ   = main.o MSNServer.o Version.o DateTime.o DBManagerCommon.o MysqlDBManager.o
EXE   = MSNServer

all:   $(EXE)

$(EXE):   ${OBJ}
	$(MAKEEXE) $^ -o $@ $(CXXFLAGS)
%.o:   %.cpp
	$(COMPILE.C) $< -o $@
clean:
	rm -f *.o $(EXE) core 