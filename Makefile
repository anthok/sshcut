# compiler
CC=g++-8
CFLAGS=-Wall -std=c++17
INCLUDE=-I $(PWD)/inc
LIBS=-lstdc++fs

# DEBUG_TARGETS=sshcut-debug

# RELEASE_TARGETS=sshcut

# all: $(DEBUG_TARGETS) $(RELEASE_TARGETS)

# debug: $(DEBUG_TARGETS)

# release: $(RELEASE_TARGETS)
	
# sshcut-debug:
# 	mkdir -p bin/debug 
# 	$(CC) $(CFLAGS) $(INCLUDE) -DDEBUG -g -o bin/debug/$@ src/*.cpp

sshcut:
	mkdir -p bin/
	$(CC) $(CFLAGS) $(INCLUDE) -g -o bin/$@ src/*.cpp $(LIBS)
	# strip -s bin/release/$@

clean:
	rm -f *.o
	rm -r bin

