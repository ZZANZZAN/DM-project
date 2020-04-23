TITLE=dmcp

COMMON_FLAGS=-Wall -Wextra -Wpedantic -Werror -std=c99

CFLAGS_DEBUG=$(COMMON_FLAGS) -fsanitize=undefined,address,leak -g

CFLAGS_RELEASE=$(COMMON_FLAGS) -s -O2

all:
	gcc $(CFLAGS_RELEASE) main.c -o $(TITLE)

debug:
	gcc $(CFLAGS_DEBUG) main.c -o $(TITLE)

clean:
	rm $(TITLE)

run:
	./$(TITLE)

test:
	python3 test.py

production:
	clang $(CFLAGS_RELEASE) main.c -o $(TITLE)
