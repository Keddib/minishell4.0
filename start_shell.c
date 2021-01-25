/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_shell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouzid <abbouzid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 09:28:43 by abbouzid          #+#    #+#             */
/*   Updated: 2021/01/25 15:51:50 by abbouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

t_data  *start_shell(int argc, char **argv, char **envp)
{
    t_data  *data;

    argc = 0;
    argv = NULL;
    if (!(data = (t_data *)malloc(sizeof(t_data))))
        return (NULL);
    data->exit_status = 0;
    data->env_vars = build_env_vars(envp);
    data->unset_vars = NULL;
    return (data);
}

// void show_prompt(t_data *data)
// {
//     char    *cwd;
//     char    *home;

//     cwd = NULL;
//     home = NULL;
//     //ft_putstr_fd("\033[1;32m", 1);
//     if ((cwd = getcwd(cwd, 0)))
//     {
//         home = search_var(&data->env_vars, "HOME")->value;
//         if (ft_strcmp(cwd, home) == 0)
//             cwd = "~";
//         else
//             cwd = ft_strrchr(cwd, '/');
//         if (cwd[1])
//         {
//             ft_putstr_fd(cwd+1, 1);
//             g_prompt = ft_strdup(cwd+1);
//         }
//         else
//         {
//             ft_putstr_fd(cwd, 1);
//             g_prompt = ft_strdup(cwd);
//         }
//         //free(cwd);
//     }
//     g_prompt = ft_strjoin("\n", g_prompt);
//     g_prompt = ft_strjoin(g_prompt, "$ ");
//     ft_putstr_fd("$ ", 1);
//     //ft_putstr_fd("\033[0m", 1);

// }
