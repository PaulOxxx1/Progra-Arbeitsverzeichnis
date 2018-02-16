CPPC=g++

all: 4_1.exe 4_2_1.exe 4_2_2.exe 4_2_3.exe 4_3a.exe 4_3b.exe 4_3c.exe
	./4_1.exe
	./4_2_1.exe
	./4_2_2.exe
	./4_2_3.exe
	./4_3a.exe
	./4_3b.exe
	./4_3c.exe

%.exe : %.cpp
	$(CPPC) -o $@ $<

clean:
	rm -f *.exe

.PHONY: all clean
