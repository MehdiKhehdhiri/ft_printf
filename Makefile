SRCS   =   ft_printf.c\
		   ft_intlen.c\
		   ft_putstr.c\
		   ft_abs.c\
		   ft_putchar.c\
		   ft_integer.c\
		   ft_unsigned.c\
		   ft_hex.c\
		   ft_pointer.c\
		   ft_pointer_hex.c\
		   ft_pointer_intlen.c

OBJS    = ${SRCS:.c=.o}

NAME    = libftprintf.a

CC  = gcc

CFLAGS  = -Wall -Wextra -Werror

RM  = rm -f

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}        

all:        ${NAME}

${NAME}:    ${OBJS}
		ar rc ${NAME} ${OBJS}
clean:
		${RM} ${OBJS}
fclean:     clean
		${RM} ${NAME}

re:     fclean  all

.PHONY:     all clean fclean re
