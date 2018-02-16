CPPC=g++

all: 9.cpp
	$(CPPC) -o 9.exe 9.cpp
	
%.o : %.cpp
	$(CPPC) -c $<

clean:
	rm -f *.exe

.PHONY: all clean
