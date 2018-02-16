CPPC=g++

all: 5.exe
	./5.exe

%.exe : %.cpp
	$(CPPC) -o $@ $<

clean:
	rm -f *.exe

.PHONY: all clean
