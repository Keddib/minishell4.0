/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouzid <abbouzid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 08:27:29 by abbouzid          #+#    #+#             */
/*   Updated: 2021/02/01 09:39:30 by abbouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "includes/minishell.h"

int     parse_redirection(t_list **tokens, t_command *command, int redirection)
{
    t_list        **streams;
    t_token       *token;

    
    if (redirection == OUTPUT)
        streams = &(command->outfiles);
    else if (redirection == INPUT)
        streams = &(command->infiles);
    else
        streams = &(command->append_outfiles);
    del_token_head(tokens);
    token = (t_token *)((*tokens)->content);
    if ((*tokens) && token->id >= WORD)
    {
        ft_lstadd_back(streams, ft_lstnew(ft_strdup(token->tkn)));
        del_token_head(tokens);
        return (1);
    }
    return (0);
}

int     parse_name_and_args(t_list **tokens, t_command *command)
{
    t_token *token;

    token = (t_token *)((*tokens)->content);
    ft_lstadd_back(&(command->name_and_args), ft_strdup(token));
    del_token_head(tokens);
    return (1);
}


t_command    *parse_simple_command(t_list    **tokens)
{
    t_command    *command;
    int                 id;

    if (!(command = new_cmd()))
        return (NULL);
    while (*tokens && ((t_token *)((*tokens)->content))->id != PIPE
                 && ((t_token *)((*tokens)->content))->id != SEMICOLON)
    {
        id  = ((t_token *)((*tokens)->content))->id;
        if (id == OUTPUT || id  == INPUT || id == APPEND_OUT)
        {
            if (!parse_redirection(tokens, command, id))
            {
                free_command(command);
                return (NULL);
            }
            else if (id == OUTPUT || id == APPEND_OUT)
                command->output_stream = id;
        }
        else if(!parse_name_and_args(tokens, command))
        {
            free_command(command);
            return (NULL);
        }
    }
    return (command);
}


t_list      *parse_pipe_line(t_list **tokens)
{
    t_pipeline      *pipeline;
    t_command       *command;
    t_token         *tkn;

    tkn = (t_token *)((*tokens)->content);
    if (tkn->id == SEMICOLON || tkn->id == PIPE)
        return (NULL);
    if (!(pipeline = new_pipe_line()))
        return (NULL);
    while (*tokens && ((t_token *)((*tokens)->content))->id != SEMICOLON)
    {
        if (!(command = parse_simple_command(tokens)))
        {
            free_pipeline(pipeline);
            return (NULL);
        }
        ft_lstadd_back(&(pipeline->cmds), command);
        if ((*tokens) && ((t_token *)((*tokens)->content))->id == PIPE)
        {
            del_token_head(tokens);
            continue;
        }
    }
    return (pipeline);
}


t_pipeline      *parser(char    *input_cmd)
{
    t_list          *tokens;
    t_list          *pipelines;
    t_pipeline      *tmp;

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
        ft_lstadd_back(&pipelines, tmp);
        if (tokens && ((t_token *)((tokens)->content))->id == SEMICOLON)
        {
            del_token_head(&tokens);
            continue;
        }
    }
    return (pipelines);
}
