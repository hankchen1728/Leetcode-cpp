SHELL := /bin/bash
CC:=clang++
CFLAG:= -Wall -std=c++17 -O3 -fsanitize=address

ifeq (problem,$(firstword $(MAKECMDGOALS)))
    # use the second argument as problem id
	PROB_ID := $(word 2,$(MAKECMDGOALS))
    # use the rest arguments as problem title
	PROB_TITLE := $(wordlist 3,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
    # ...and turn them into do-nothing targets
    $(eval $(PROB_ID):;@:)
    $(eval $(PROB_TITLE):;@:)
endif

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

problem:
	$(eval PROB_ID = $(shell printf '%04d' $(subst .,,$(PROB_ID))))
	$(eval PROB_TITLE = $(shell echo "${PROB_TITLE}" | sed -e 's/ /_/g'))
	cp -r ./src/Template ./src/$(PROB_ID)_$(PROB_TITLE)
