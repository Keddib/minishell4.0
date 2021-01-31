/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouzid <abbouzid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:11:11 by keddib            #+#    #+#             */
/*   Updated: 2021/01/31 09:44:28 by abbouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

/*
** stack to handle the double quote strings
*/

char    pop(t_list **stack);
void	push(t_list**stack, char character);
char    top_stack(t_list **stack);
int		empty_stack(t_list **stack, t_list **tokens);
void	is_metacharacter(t_stack **stack);
void	push_str_to_stack(t_stack **stack, char *str);

#endif
