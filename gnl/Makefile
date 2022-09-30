SRCS = get_next_line.c	get_next_line_utils.c

OBJS = ${SRCS:.c=.o}

SRCS_BONUS = get_next_line_bonus.c	get_next_line_utils_bonus.c

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

.c.o:
	@gcc -Wall -Werror -Wextra -c $< -o ${<:.c=.o}

all:	${OBJS}

clean:	
	@rm -rf ${OBJS} ${OBJS_BONUS}

bonus:	${OBJS_BONUS}

clean_bonus:
	@rm -rf ${OBJS_BONUS}

.PHONY:	all clean
