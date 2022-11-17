SRCS = ft_isalpha.c	ft_isdigit.c	ft_isalnum.c	ft_isascii.c	ft_isprint.c	ft_strlen.c	ft_memset.c	ft_bzero.c	ft_memcpy.c	ft_memmove.c	ft_strlcpy.c	ft_strlcat.c	ft_toupper.c	ft_tolower.c	ft_strchr.c	ft_strrchr.c	ft_strncmp.c	ft_memchr.c	ft_memcmp.c	ft_strnstr.c	ft_atoi.c	ft_calloc.c	ft_strdup.c	ft_substr.c	ft_strjoin.c	ft_strtrim.c	ft_split.c	ft_itoa.c	ft_strmapi.c	ft_striteri.c	ft_putchar_fd.c	ft_putstr_fd.c	ft_putendl_fd.c	ft_putnbr_fd.c

OBJS =  ${SRCS:.c=.o}

SRCS_BONUS =	ft_lstnew_bonus.c	ft_lstadd_front_bonus.c	ft_lstsize_bonus.c	ft_lstlast_bonus.c	ft_lstadd_back_bonus.c	ft_lstdelone_bonus.c	ft_lstclear_bonus.c	ft_lstiter_bonus.c	ft_lstmap_bonus.c

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

CC =    gcc

CFLAGS = -Wall -Werror -Wextra

NAME =  libft.a

RM =    rm -f

all:	$(NAME)	
	
.c.o:
		@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):   ${OBJS}
		@ar -r ${NAME} ${OBJS}

clean:
		@${RM} ${OBJS} ${OBJS_BONUS}

fclean:	clean
		@${RM} printf/*.o printf/*.a
		@${RM} gnl/*.o

re:		fclean	all

bonus:	all	${OBJS_BONUS}
		@ar -r ${NAME} ${OBJS_BONUS}

extra:	bonus fclean
		@make -C printf/
		@make -C gnl/ bonus
		@ar -r ${NAME} printf/*.o gnl/*.o
		@make -C gnl/ clean_bonus
		@make -C printf/ fclean
		@echo "libft.a was created correctly. You can use it without problem :)"

.PHONY:	all	fclean	clean	re	bonus	extra
