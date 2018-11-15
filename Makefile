CC=g++-8
CFLAGS=-Wall -std=c++17
INCLUDE=-I $(PWD)/inc
LIBS=-lstdc++fs

sshcut:
	mkdir -p bin/
	$(CC) $(CFLAGS) $(INCLUDE) -g -o bin/$@ src/*.cpp $(LIBS)

clean:
	rm -f *.o
	rm -r bin

