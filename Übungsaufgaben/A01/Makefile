CPPC=g++

all: Hello.exe Klassik.exe
	./Hello.exe
	./Klassik.exe

%.exe : %.cpp
	$(CPPC) -o $@ $<

clean:
	rm -f *.exe

.PHONY: all clean
