/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarquar <fmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 10:33:22 by fmarquar          #+#    #+#             */
/*   Updated: 2023/06/29 10:27:06 by fmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_cmd_path(char *envp[], char *argv)
{
	char	**path;
	char	**cmd;
	char	*acc1;
	char	*acc2;
	int		i;

	i = 0;
	acc2 = NULL;
	cmd = ft_split(argv, ' ');
	path = find_path(envp);
	while (path && path[i] != NULL)
	{
		acc1 = ft_strjoin("/", cmd[0]);
		acc2 = ft_strjoin(path[i], acc1);
		free(acc1);
		if (access(acc2, F_OK) == 0)
			break ;
		free(acc2);
		acc2 = NULL;
		i++;
	}
	if ((access(acc2, F_OK) != 0))
		acc2 = ft_strdup(cmd[0]);
	return (free_double_char(cmd), free_double_char(path), acc2);
}

void	find_cmd_args_in(t_smw *smw, char *argv, char *envp[])
{
	int		i;

	i = 0;
	smw->args_in = ft_split(argv, ' ');
	free(smw->args_in[0]);
	smw->args_in[0] = find_cmd_path(envp, argv);
	return ;
}

void	find_cmd_args_out(t_smw *smw, char *argv, char *envp[])
{
	int		i;

	i = 0;
	smw->args_out = ft_split(argv, ' ');
	free(smw->args_out[0]);
	smw->args_out[0] = find_cmd_path(envp, argv);
	return ;
}

char	**find_path(char *envp[])
{
	int		i;
	char	**path;

	i = 0;
	path = NULL;
	while (envp[i] != NULL)
	{
		if (ft_memcmp(envp[i], "PATH", 4) == 0)
		{
			path = ft_split(envp[i], ':');
		}
		i++;
	}
	return (path);
}
