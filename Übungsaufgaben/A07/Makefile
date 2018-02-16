CPPC=g++

all: 7.exe
	./7.exe

%.exe : %.cpp
	$(CPPC) -o $@ $<

clean:
	rm -f *.exe

.PHONY: all clean
