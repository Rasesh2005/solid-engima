UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
	file=.out
else
	file=.exe
endif
default:
	g++ main.cpp -std=c++2a -lstdc++fs
clean:
	rm *$(file)