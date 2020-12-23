/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouzid <abbouzid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 22:49:46 by abbouzid          #+#    #+#             */
/*   Updated: 2020/12/23 11:15:52 by abbouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>

#define SHELL "/bin/sh"
#define PROMPT "minishell:>"

/******************************************************************************/
/*	macros 																	  */
/******************************************************************************/
#define TRUE 1
#define FALSE 0
#define STDIN 0
#define STDOUT 1
#define bool int

int				ft_printf(const char *s, ...);
/******************************************************************************/
/*	structures prototypes													  */
/******************************************************************************/
typedef	struct s_arguments
{
	char 				*arg;
	struct s_argument 	*next;
}				t_arguments;

typedef	struct s_simple_command
{
	char		*cmd_name;
	t_arguments *arguments;
	char		*infile;
	char		*outfile;
	char		*append_outfile;
	struct s_simple_command		*next;
}				t_simple_command;

typedef struct s_pipeline
{
	t_simple_command 	*simple_cmd;
	struct 	s_pipeline  *next;
}				t_pipeline;

/******************************************************************************/
/*	stack to handle the double quote strings 								  */
/******************************************************************************/

typedef	struct	s_stack
{
	char				character;
	struct 		s_stack *next;
	
}				t_stack;

char    pop(t_stack **stack_head);
void	push(t_stack **stack_head, char character);
int     stack_len(t_stack **stack_head);
char    top_stack(t_stack **stack_head);
void    free_stack(t_stack **stack);
char    *empty_stack(t_stack **stack_head);

/******************************************************************************/
/*	get_input and tokenizing 												  */
/******************************************************************************/
enum token {OUTPUT, INPUT, APPEND_OUT, PIPE, SEMICOLON, WORD, UNKNOWN};

typedef  struct s_token
{
	char 	*tkn;
	int		id;
	struct 	s_token *next;
}				t_token;

int					get_input(char	**input);

t_token		*new_token(char **str);
t_token		*last_token(t_token *tokens);
void		add_token(t_token **tokens, t_token *new_token);
t_token     *tokenizing(char *input_cmd);
void     	free_tokens(t_token **head);
int     	handle_single_quote(t_stack **stack, char **input_cmd);
void            identify_all_tokens(t_token *tokens);
/******************************************************************************/
/*	strings manipulation prototypes											  */
/******************************************************************************/
char				*ft_strcpy(char *dst, char *src);
int					ft_strlen(char *str);
void				ft_strlcpy(char *dst, char *src, int len);
int					ft_strcmp(char *str1, char *str2);
void				*ft_memset(void	*b, int c, size_t len);
bool				is_white_character(char c);
char				*ft_strdup(char *str);
/******************************************************************************/
/* environment variables linked list functions prototypes					  */
/******************************************************************************/
typedef struct s_env_vars
{
	char		*name;
	char		*value;
	struct	s_env_vars *next;
}				t_env_vars;

t_env_vars			*create_env_var(char *name, char *value);
t_env_vars			*last_env_var(t_env_vars *env_vars);
char				*get_env_name(char *name_value);
char				*get_env_value(char *name_value);
void				add_back_env(t_env_vars **vars, t_env_vars *new_var);
t_env_vars			*build_env_vars(char *envp[]);
t_env_vars			*search_var(t_env_vars **env_vars, char *var_name);
int					change_env_var(t_env_vars **vars, char *var_name, char *new_value);

#endif
