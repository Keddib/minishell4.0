/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 07:33:33 by abbouzid          #+#    #+#             */
/*   Updated: 2021/02/06 17:58:06 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		handle_single_quote(t_list **stack, char **input_cmd)
{
	BOOL second_quote;

	second_quote = 0;
	while (**input_cmd)
	{
		push(stack, *(*input_cmd)++);
		if (top_stack(stack) == 0x27)
		{
			second_quote = 1;
			break;
		}
	}
	if (!second_quote)
		return (0);
	if (**input_cmd == '\0' && top_stack(stack) != 0x27)
		return (0);
	return (1);
}

int		handle_double_quote(t_list **stack, char **input_cmd)
{
	while(**input_cmd)
	{
		push(stack, *(*input_cmd)++);
		if (top_stack(stack) != '"')
			continue ;
		else
		{
			if (special(*stack))
				continue ;
			else
				return (1);
		}
	}
	return (0);
}

int		special(t_list *stack)
{
	int     special;

	special = 0;
	stack = stack->next;
	while (stack)
	{
		if (((t_stack *)(stack->content))->character == 0x5c)
		{
			special++;
			stack = stack->next;
		}
		else
			break ;
	}
	return (special % 2);
}

int		handle_quotes(t_list **stack, char **input_cmd, int *error)
{
	char       quote;

	*error = 0;
	quote = top_stack(stack);
	if (!special((*stack)))
	{
		if (quote == '\'')
		{
			if (!handle_single_quote(stack, input_cmd))
				*error = 1;
		}
		else
		{
			if (!handle_double_quote(stack, input_cmd))
				*error = 1;
		}
		if (*error)
			return (0);
		return (1);
	}
	return (1);
}

int		handle_metacharacter(t_list **stack, t_list **tokens, char **input_cmd)
{
	char		top;
	int			append;

	append = 0;
	top = top_stack(stack);
	pop(stack);
	if ((*stack) && !empty_stack(stack, tokens))
		return (0);
	push(stack, top);
	if ((top == '>' && **input_cmd == '>') && (append = 1))
		push(stack, *(*input_cmd)++);
	else if (is_meta(**input_cmd))
	{
		ft_lstclear(stack, free);
		ft_lstclear(tokens, free_token);
		return (0);
	}
	if (!empty_stack(stack, tokens))
		return (0);
	pop(stack);
	if (append)
		pop(stack);
	return (1);
}

int		handle_space(t_list **stack, t_list **tokens, int *error)
{
	if (special(*stack))
		return (1);
	pop(stack);
	if (top_stack(stack) != '\0' && *stack != NULL)
	{
		if (!empty_stack(stack, tokens))
		{
			*error = 1;
			return (0);
		}
	}
	*error = 0;
	return (1);
}

int		handle_end_token(t_list **stack, t_list **tokens)
{
	if (*stack != NULL)
	{
		pop(stack);
		if (*stack != NULL)
			empty_stack(stack, tokens);
		return (1);
	}
	return (0);
}

int		handle_meta(t_list **stack, t_list **tokens, char **input_cmd)
{
	if (*stack && ((t_stack *)((*stack)->content))->meta)
	{
		if (!handle_metacharacter(stack, tokens, input_cmd))
			return (1);
	}
	else if (top_stack(stack) == '\0')
		if (handle_end_token(stack, tokens))
			return (1);
	return (0);
}