# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abbouzid <abbouzid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/20 12:43:22 by abbouzid          #+#    #+#              #
#    Updated: 2021/02/01 18:04:28 by abbouzid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= minishell

GCC				= gcc -Wall -Wextra -Werror

STR				= strings

BUILTINS		= builtins

SRCS			= minishell.c						\
				$(STR)/strings.c					\
				$(STR)/strings_2.c					\
				$(STR)/ft_split.c					\
				$(STR)/ft_strjoin.c					\
				$(STR)/ft_putstr_fd.c				\
				$(STR)/ft_itoa.c					\
				$(STR)/ft_strrchr.c					\
				lexer.c								\
				stack.c								\
				parser.c							\
				command.c							\
				pipeline.c							\
				tokens.c							\
				expansions.c						\
				env_var.c							\
				start_shell.c						\
				execution.c							\
				arguments_array.c					\
				find_binary_path.c					\
				variables.c							\
				$(BUILTINS)/builtin_methodes.c		\
				$(BUILTINS)/cd.c					\
				$(BUILTINS)/echo.c					\
				$(BUILTINS)/env.c					\
				$(BUILTINS)/exit.c					\
				$(BUILTINS)/export.c				\
				$(BUILTINS)/pwd.c					\
				$(BUILTINS)/unset.c					\
				sort.c								\
				redirections.c						\
				signals.c							\
				piping.c							\
				lst_methodes.c


all:	$(NAME)

$(NAME) : $(SRCS)
	$(MAKE) -C get_next_line
	$(GCC) -g  -o $(NAME) $(SRCS) gnl.a

clean:
	rm $(NAME)

fclean: clean
	rm -rf *.dSYM minishell

re: clean all

.PHONY: clean re all
