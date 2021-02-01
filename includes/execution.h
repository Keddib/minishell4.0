/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouzid <abbouzid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 09:59:42 by keddib            #+#    #+#             */
/*   Updated: 2021/02/01 15:37:37 by abbouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

/*
** execution functions
*/

int     execute_simple_cmd(t_data *data, t_list *pipeline);
void    execute(t_data   *data, t_list *pipelines);
void    execute_pipeline(t_data *data, t_list *pipeline);
int     execute_binary(t_data *data, t_command *cmd);
int     execute_built_in(char built_in, t_data *data, t_command *cmd);

#endif
