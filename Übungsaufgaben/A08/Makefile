CPPC=g++

all: polynom.o trigonom.o 8.o integral.o montecarlo.o riemann.o
	$(CPPC) -o 8.exe polynom.o trigonom.o 8.o integral.o montecarlo.o riemann.o
	rm -f *.o	
	
%.o : %.cpp
	$(CPPC) -c $<

clean:
	rm -f *.exe

.PHONY: all clean
