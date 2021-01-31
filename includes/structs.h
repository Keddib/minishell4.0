/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouzid <abbouzid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:13:03 by keddib            #+#    #+#             */
/*   Updated: 2021/01/31 09:04:21 by abbouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

/*
** structures prototypes
*/

typedef	struct s_command
{
	t_list		*name_and_args;
	t_list		*infiles;
	t_list		*outfiles;
	t_list		*append_outfiles;
	int 		output_stream;
	char 		built_in;
}				t_command;

typedef struct s_pipeline
{
	t_list  	*cmds
}				t_pipeline;

typedef  struct s_token
{
	char 	*tkn;
	int		id;
}				t_token;

typedef	struct	s_stack
{
	char				character;
	int 				meta;
	int					special;
}				t_stack;

typedef struct s_env_var
{
	char		*name;
	char		*value;
}				t_env_var;

typedef struct s_data
{
	t_list		*env_vars;
	t_list		*unset_vars;
	char		*input_cmd;
	t_pipeline	*parse_tree;
	int			exit_status;
}				t_data;


#endif
