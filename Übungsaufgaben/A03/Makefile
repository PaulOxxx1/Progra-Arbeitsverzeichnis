CPPC=g++

all: 3_1_1.exe 3_1_2.exe
	./3_1_1.exe
	./3_1_2.exe

%.exe : %.cpp
	$(CPPC) -o $@ $<

clean:
	rm -f *.exe

.PHONY: all clean
