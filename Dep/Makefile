SRC=$(wildcard *.cpp)
EXE=$(addsuffix .exe, $(basename $(SRC)))
CPPC=g++
CPPC_FLAGS=-Wall -Wextra -pedantic -O3 -std=c++14

all : $(EXE)

%.exe : %.cpp
	$(CPPC) $(CPPC_FLAGS) $< -o $@

clean :
	rm -f $(EXE)

.PHONY: all clean

