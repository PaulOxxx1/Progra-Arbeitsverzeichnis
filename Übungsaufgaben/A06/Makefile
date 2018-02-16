CPPC=g++

all: 6.exe
	./6.exe

%.exe : %.cpp
	$(CPPC) -o $@ $<

clean:
	rm -f *.exe

.PHONY: all clean
