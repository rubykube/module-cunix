
CC					:= gcc

RM					:= rm -rf

LDFLAGS			+= -Llib

CFLAGS			+= -Iinclude

SRCS				:= $(wildcard src/*.c)

OBJS				:= $(SRCS:.c=.o)

NAME				:= printf_test

all:				$(NAME)

$(NAME):		$(OBJS)
						$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
						$(RM) $(OBJS)
						$(RM) output.test

fclean: 		clean
						$(RM) $(NAME)

re: 				fclean all

test:				re
						$(shell ./$(NAME) > output.test)
						@(diff -q output.verif output.test && echo "Test success" || echo "Test Fails")
