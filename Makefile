NAME			=	push_swap
NAME_CHK		=	checker
HEADERS			=	push_swap.h
CC				= 	gcc
RM				= 	rm -rf
CFLAGS 			= 	-Wall -Wextra -Werror -g
AR				= 	ar rcs

SRCS	=	main.c	\
			func_push.c	\
			func_reverse.c	\
			func_rotate.c	\
			func_swap.c	\
			find_max_min.c	\
			parsing.c	\
			bring_num_up.c \
			utils1.c \
			utils2.c \

SRCS_BONUS = func_push.c	\
			func_reverse.c	\
			func_rotate.c	\
			func_swap.c	\
			find_max_min.c	\
			parsing.c	\
			bring_num_up.c \
			utils1.c \
			utils2.c \
			func_rest.c \

BONUS	=	my_checker/checker.c 
	
OBJS	= ${SRCS:.c=.o}

OBJS_B	= ${BONUS:.c=.o} ${SRCS_BONUS:.c=.o}

LIBS 	= -L ./libft -lft

COMPIL = ${CC} ${CFLAGS} ${OBJS_B} ${LIBS} -o ${NAME_CHK}

MAKE_EXT	= @make -s --no-print-directory -C

$(NAME):	${OBJS}
			$(MAKE_EXT) ./libft
			${CC} ${CFLAGS} ${OBJS} ${LIBS} -o ${NAME}

all:	${NAME}

%.o: %.c	$(HEADERS)
			@${CC} -c ${CFLAGS} -o $@ $< 

bonus:		${OBJS_B}
			$(MAKE_EXT) ./libft
			@${COMPIL}

clean:
		${MAKE_EXT} ./libft clean
		${RM} ${OBJS} ${OBJS_B}

fclean: clean
		${MAKE_EXT} ./libft fclean
		${RM} ${NAME} ${NAME_CHK}

re:		fclean all

.PHONY:	all clean fclean re bonus