CC:=g++
CFLAG:= -g -Wall -O3

%.o:src/%.cpp
	mkdir -p bin/
	$(CC) $(CFLAG) -c $^ -o bin/$@

clean:
	rm -rf ./bin
