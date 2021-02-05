/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 09:45:21 by abbouzid          #+#    #+#             */
/*   Updated: 2021/02/05 14:29:26 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		echo(char   **args)
{
	BOOL	new_line;
	int		i;
	int		argsnum;

	argsnum = args_num(args);
	if (argsnum >= 2)
		new_line = ft_strcmp(args[1], "-n");
	else
		new_line = 1;
	i = 1;
	while (args[i] && ft_strcmp(args[i], "-n") == 0)
		i++;
	while (args[i])
	{
		if (args[i][0])
		{
			ft_putstr_fd(args[i], 1);
			if (args[i + 1] && args[i + 1][0])
				ft_putstr_fd(" ", 1);
		}
		i++;
	}
	if (new_line != 0)
		ft_putstr_fd("\n", 1);
	return (0);
}
