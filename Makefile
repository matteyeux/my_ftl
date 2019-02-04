##
## ETNA PROJECT, 12/11/2018 by hauteb_m
## My_FTL
## File description:
##      Makefile for My_FTL project
##

CC      = gcc
CFLAGS  = -I. -Wall -Wextra -Werror -g3

RM      = rm -f
TARGET  = my_ftl

SRC 	= 	src/main.c \
			src/my_string.c \
			src/my_readline.c \
			src/air_shed.c \
			src/container.c \
			src/system_control.c \
			src/system_repair.c \
			src/system_break.c \
			src/game.c \
			src/commands.c \
			src/enemy.c \
			src/fight.c \
			src/my_putnbr.c

OBJ = $(SRC:.c=.o)

.PHONY: all $(TARGET) clean fclean re

all : $(TARGET)

$(TARGET): $(OBJ) 
	@echo "LD	$@"
	@$(CC) $(OBJ) -o $@

src/%.o : src/%.c
	@echo "CC	$<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(TARGET)

re : fclean all
