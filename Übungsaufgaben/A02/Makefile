CPPC=g++

all: 2_1.exe 2_2.exe 2_3.exe 2_4a.exe 2_4b.exe 2_4c.exe
	./2_1.exe
	./2_2.exe
	./2_3.exe
	./2_4a.exe
	./2_4b.exe
	./2_4c.exe

%.exe : %.cpp
	$(CPPC) -o $@ $<

clean:
	rm -f *.exe

.PHONY: all clean
