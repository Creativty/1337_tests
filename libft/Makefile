NAME := verify
FLAGS := -Wall -Wextra -Werror
 
SOURCES := $(wildcard funcs/*.c) $(SOURCES_LIBFT:%=../../libft/%) auto/groups.c main.c
INCLUDES := -I=../../libft -I=./

$(NAME): $(SOURCES)
	./generate_data.sh > auto/data.h
	./generate_group.sh > auto/groups.c
	$(CC) $(FLAGS) $(INCLUDES) $(SOURCES) -o $(NAME)

all: $(NAME)

sanitize:
	$(CC) $(FLAGS) -g -fsanitize=address $(INCLUDES) $(SOURCES) -o $(NAME) -D MODE_SANITIZE

clean:
	rm -rf $(NAME)
	rm -rf $(NAME).dSYM

re: clean $(NAME)

.PHONY: sanitize clean sh_source
