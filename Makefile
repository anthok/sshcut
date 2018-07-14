# compiler
CC=g++
CFLAGS=-Wall -std=c++11
INCLUDE=-I $(PWD)/inc
LIBS=-pthread

DEBUG_TARGETS=sshcut-debug

RELEASE_TARGETS=sshcut

all: $(DEBUG_TARGETS) $(RELEASE_TARGETS)

debug: $(DEBUG_TARGETS)

release: $(RELEASE_TARGETS)
	
sshcut-debug:
	mkdir -p bin/debug 
	$(CC) $(CFLAGS) $(INCLUDE) -DDEBUG -g -o bin/debug/$@ src/*.cpp

sshcut:
	mkdir -p bin/release 
	$(CC) $(CFLAGS) $(INCLUDE) -o bin/release/$@ src/*.cpp
	strip -s bin/release/$@

clean:
	rm -f *.o
	rm -r bin

