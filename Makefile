:# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbliss <rbliss@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/31 11:14:47 by rbliss            #+#    #+#              #
#    Updated: 2021/01/09 10:34:50 by rbliss           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
SRCS		= ft_strutils.c\
			ft_chrutils.c\
			ft_nbrutils.c\
			ft_otherutils.c\
			ft_hexutils.c\
			ft_someput.c\
			ft_wiacutils.c\
			ft_seter.c\
			ft_printf.c\
			ft_itoa.c\
			ft_secifier.c\
			ft_secifier_int.c\
			ft_secifier_hex.c\
			
OBJS		= ${SRCS:.c=.o}
CC			= gcc
CFLAGS		= -Werror -Wextra -Wall
.c.o :
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I.
$(NAME) :	${OBJS}
			ar rc $(NAME) ${OBJS}
			ranlib $(NAME)
so :        
			${CC} -shared -o ${OBJS}
all :		$(NAME)
clean :
			rm -f ${OBJS} ${OBJS_B}
fclean :	clean
			rm -f $(NAME)
re :		fclean all
.PHONY:		all clean fclean re .c.o test
