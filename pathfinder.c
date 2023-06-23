/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarquar <fmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 10:33:22 by fmarquar          #+#    #+#             */
/*   Updated: 2023/06/22 16:54:16 by fmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_cmd_path(char *envp[], char *argv)
{
	char	**path;
	char	**cmd;
	char	*acc;
	int		i;

	i = 0;
	cmd = ft_split(argv, ' ');
	ft_printf("CMD[0] = %s\n", cmd[0]);
	path = find_path(envp);
	while (path[i] != NULL)
	{
		acc = ft_strjoin("/", cmd[0]);
		acc = ft_strjoin(path[i], acc);
		ft_printf("Does this work?? PATH = %s\n", acc);
		if (access(acc, F_OK) == 0)
		{
			ft_printf("HOORAY!! CMD = %s\n", acc);
			break ;
		}
		i++;
	}
	return (acc);
}

void	find_cmd_args_in(t_smw *smw, char *argv, char *envp[])
{
	int		i;

	i = 0;
	smw->args_in = ft_split(argv, ' ');
	while (smw->args_in[i] != NULL)
	{
		ft_printf("argv: %s\n", smw->args_in[i]);
		i++;
	}
	smw->args_in[0] = find_cmd_path(envp, argv);
	ft_printf("argv: %s\n", smw->args_in[0]);
	return ;
}

void	find_cmd_args_out(t_smw *smw, char *argv, char *envp[])
{
	int		i;

	i = 0;
	smw->args_out = ft_split(argv, ' ');
	while (smw->args_out[i] != NULL)
	{
		ft_printf("argv: %s\n", smw->args_out[i]);
		i++;
	}
	smw->args_out[0] = find_cmd_path(envp, argv);
	ft_printf("argv: %s\n", smw->args_out[0]);
	return ;
}

char	**find_path(char *envp[])
{
	int		i;
	int		j;
	char	**path;

	i = 0;
	j = 0;
	while (envp[i] != NULL)
	{
		if (ft_memcmp(envp[i], "PATH", 4) == 0)
		{
			path = ft_split(envp[i], ':');
			while (path[j] != NULL)
			{
				//printf("%s\n", path[j]);
				j++;
			}
		}
		i++;
	}
	return (path);
}
