/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 09:59:42 by keddib            #+#    #+#             */
/*   Updated: 2021/02/09 18:53:41 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

/*
** execution functions
*/

int		execute_binary(t_data *data, t_command *cmd);
int		execute_built_in(char built_in, t_data *data, t_command *cmd);
int		execute_child(t_data *data, t_command *cmd);
void	execute(t_data *data);
void	execute_pipeline(t_data *data, t_list *cmds);
void	execute_pipe(t_command *cmd, t_data *data);
void	return_status(int *save_std, t_data *data);
void	set_fds(int save_std[2], int tmp_fd[2]);
void	execute_simple_cmd(t_data *data, t_pipeline *pipeline);
int		execve_error(char *path, char **argv, char **envp);
int		no_cmd(t_data *data, int *save_std);

#endif
