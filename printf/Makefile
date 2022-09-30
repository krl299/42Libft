NAME = libftprintf.a

SRCS = ft_printf.c parsers.c prints.c utils.c handles.c specifiers.c specifier_bonus.c structs.c utils_2.c parser_length_bonus.c

INCLUDES	= ft_printf.h

OBJS	= ${SRCS:.c=.o}

GCC		= gcc

ARRC	= ar rc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

.c.o:
			@${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			@${ARRC} ${NAME} ${OBJS}
			@ranlib ${NAME}

all:		${NAME}

bonus:	all

clean:
			@${RM} ${OBJS}

fclean:		clean
			@${RM} ${NAME}

re :		fclean all

try:		${OBJS}
			@cc ${CFLAGS} ${OBJS} && ./a.out | cat -e

.PHONY:		bonus all clean fclean re try
