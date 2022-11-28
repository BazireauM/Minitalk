NAME = client

NAME2 = server

SRCS1	=	client.c

SRCS2	=	server.c

OBJS1	=	$(SRCS1:.c=.o)

OBJS2	=	$(SRCS2:.c=.o)

CC	=	gcc

CFLAGS	=	-Wall -Werror -Wextra

RM	=	rm -f

all	:	$(NAME)

$(NAME)	:	$(OBJS2) $(OBJS1)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS1)
		$(CC) $(CFLAGS) -o $(NAME2) $(OBJS2)

clean	:
		$(RM) $(OBJS1) $(OBJS2)

fclean	:	clean
		$(RM) $(NAME) $(NAME2)

re	:	fclean $(NAME)
