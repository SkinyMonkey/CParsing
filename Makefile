SRCS_FOLDER	= ./srcs

CC	=	clang

CFLAGS	=	-Wall -Wextra -g3 -I./includes

SRCS	=	$(SRCS_FOLDER)/Callback.c\
		$(SRCS_FOLDER)/Capture.c\
		$(SRCS_FOLDER)/Context.c\
		$(SRCS_FOLDER)/lifo.c\
		$(SRCS_FOLDER)/ParsingBase.c\
		$(SRCS_FOLDER)/Primitives.c\
		$(SRCS_FOLDER)/stream.c\
		$(SRCS_FOLDER)/trace.c\
		./tests/test.c

OBJS	=	$(SRCS:.c=.o)

all:	$(OBJS)
	$(CC) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -rf ./a.out

re: fclean all
