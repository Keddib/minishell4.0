/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 08:27:29 by abbouzid          #+#    #+#             */
/*   Updated: 2021/02/08 17:21:42 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			parse_redirection(t_list **tokens, t_command *command, int stream)
{
	t_token			*token;
	t_redirection	*redirection;

	del_token_head(tokens);
	token = (t_token *)((*tokens)->content);
	if ((*tokens) && token->id >= WORD)
	{
		redirection = new_redirection(token->tkn, stream);
		ft_lstadd_back(&(command->redirections), ft_lstnew(redirection));
		del_token_head(tokens);
		return (1);
	}
	return (0);
}

int			parse_name_and_args(t_list **tokens, t_command *command)
{
	char	*namearg;

	namearg = ft_strdup(((t_token *)((*tokens)->content))->tkn);
	ft_lstadd_back(&(command->name_and_args), ft_lstnew(namearg));
	del_token_head(tokens);
	return (1);
}

t_command	*parse_command(t_list **tokens)
{
	t_command	*command;
	int			id;

	if (!(command = new_cmd()))
		return (NULL);
	while (*tokens && ((t_token *)((*tokens)->content))->id != PIPE
			&& ((t_token *)((*tokens)->content))->id != SEMICOLON)
	{
		id = ((t_token *)((*tokens)->content))->id;
		if (id == OUTPUT || id == INPUT || id == APPEND_OUT)
		{
			if (!parse_redirection(tokens, command, id))
			{
				free_command(command);
				return (NULL);
			}
		}
		else if (!parse_name_and_args(tokens, command))
		{
			free_command(command);
			return (NULL);
		}
	}
	return (command);
}

t_pipeline	*parse_pipe_line(t_list **tokens)
{
	t_pipeline		*pipeline;
	t_command		*command;
	t_token			*tkn;

	tkn = (t_token *)((*tokens)->content);
	if (tkn->id == SEMICOLON || tkn->id == PIPE)
		return (NULL);
	if (!(pipeline = new_pipe_line()))
		return (NULL);
	while (*tokens && ((t_token *)((*tokens)->content))->id != SEMICOLON)
	{
		if (!(command = parse_command(tokens)))
		{
			free_pipeline(pipeline);
			return (NULL);
		}
		ft_lstadd_back(&(pipeline->cmds), ft_lstnew(command));
		if ((*tokens) && ((t_token *)((*tokens)->content))->id == PIPE)
		{
			del_token_head(tokens);
			continue;
		}
	}
	return (pipeline);
}

t_list		*parser(char *input_cmd)
{
	t_list			*tokens;
	t_list			*pipelines;
	t_pipeline		*tmp;

	tokens = lexer(input_cmd);
	pipelines = NULL;
	while (tokens)
	{
		if (!(tmp = parse_pipe_line(&tokens)))
		{
			ft_lstclear(&pipelines, free_pipeline);
			ft_lstclear(&tokens, free);
			return (NULL);
		}
		ft_lstadd_back(&pipelines, ft_lstnew(tmp));
		if (tokens && ((t_token *)((tokens)->content))->id == SEMICOLON)
		{
			del_token_head(&tokens);
			continue;
		}
	}
	return (pipelines);
}
