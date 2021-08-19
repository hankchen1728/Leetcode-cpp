SHELL := /bin/bash
CC:=clang++
CFLAG:= -Wall -std=c++17 -O3

%:
	@mkdir -p ./bin
	$(eval prob := $(shell ls ./src | grep "^${@}_*"))
	@if [ -z $(prob) ]; then \
		echo "No matched problem ID found"; \
	else \
		echo "Compiling binary file: bin/$(prob)"; \
		$(CC) $(CFLAG) src/$(prob)/main.cpp src/Utils/myUtils.cpp -o bin/$(prob); \
	fi

clean:
	rm -rf ./bin/*
