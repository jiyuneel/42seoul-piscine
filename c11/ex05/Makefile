CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
SRCS	= srcs/ft_atoi.c srcs/ft_putnbr.c srcs/ft_strlen.c srcs/calculate.c srcs/main.c
OBJS	= ${SRCS:.c=.o}
INCD	= includes
NAME	= do-op


all:		${NAME}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${OBJS} -o $@

%.o: %.c
			${CC} ${CFLAGS} -c $< -o $@ -I ${INCD}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all
