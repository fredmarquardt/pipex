/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarquar <fmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 10:33:22 by fmarquar          #+#    #+#             */
/*   Updated: 2023/06/19 13:26:38 by fmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"



char	*find_cmd_path(t_smw *smw, char *envp[], char *argv)
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
		ft_printf("Does this work?? PATH = %s\n", acc);
		acc = ft_strjoin(path[i], acc);
		ft_printf("Does this work?? PATH = %s\n", acc);
		if (access(acc, F_OK) == 0)
		{
			ft_printf("HOORAY!! CMD = %s\n", acc);
			break ;
		}
		i++;
	}
	i = smw->fd1;
	return (acc);
}

char	**find_cmd_args(t_smw *smw, char *envp[], char *argv)
{
	char	**argv_in;
	char	**args;
	char	**path;
	int		i;

	i = 0;
	argv_in = ft_split(argv, ' ');
	while (argv_in != NULL)
		i++;
	args = malloc((i + 2) * sizeof(char *));
	path = find_path(envp);
	i = 0;
	args[0] = smw->cmd_in;
	while (argv_in[i] != NULL)
	{
		args[i + 1] = argv_in[i];
		i++;
	}
	args[i + 1] = NULL;
	return (args);
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
