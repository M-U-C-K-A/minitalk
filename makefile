SOURCES = server.c client.c utils.c
OBJECTS = $(SOURCES:.c=.o)
OBJECT_DIRS = $(patsubst %.o,objs/%.o,$(OBJECTS))

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: server client
	@clear
	@STYLE="\033[2m\033[32m"; RESET="\033[0m\033[36m"; \
	echo "$$STYLE███╗   ███╗██╗███╗  ██╗██╗$$RESET████████╗ █████╗ ██╗     ██╗  ██╗"; \
	echo "$$STYLE████╗ ████║██║████╗ ██║██║$$RESET╚══██╔══╝██╔══██╗██║     ██║ ██╔╝"; \
	echo "$$STYLE██╔████╔██║██║██╔██╗██║██║$$RESET   ██║   ███████║██║     █████═╝ "; \
	echo "$$STYLE██║╚██╔╝██║██║██║╚████║██║$$RESET   ██║   ██╔══██║██║     ██╔═██╗ "; \
	echo "$$STYLE██║ ╚═╝ ██║██║██║ ╚███║██║$$RESET   ██║   ██║  ██║███████╗██║ ╚██╗"; \
	echo "$$STYLE╚═╝     ╚═╝╚═╝╚═╝  ╚══╝╚═╝$$RESET   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝";

server: objs/server.o objs/utils.o
	$(CC) -o $@ $^

client: objs/client.o objs/utils.o
	$(CC) -o $@ $^

objs/%.o: %.c | objs
	$(CC) -c $(CFLAGS) -o $@ $<

objs:
	mkdir -p $@

clean:
	rm -rf objs

fclean: clean
	rm -f server client

re: fclean all

.PHONY: all bonus clean fclean re

