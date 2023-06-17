/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarquar <fmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 10:33:22 by fmarquar          #+#    #+#             */
/*   Updated: 2023/06/17 18:33:24 by fmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_smw	*create_smw(int argc)
{
	t_smw	*smw;
	int		path_size;

	//smw = NULL;
	ft_printf("Number of arguments: %i\n", argc);
	smw = (t_smw *)malloc(sizeof(t_smw));
	if (smw == NULL)
	{
		ft_printf("Memory allocation failed\n");
	}
	path_size = 100;
	smw->path = (char **) malloc(path_size * sizeof(char *));
	smw->cmd_in = (char *) malloc(path_size * sizeof(char *));
	smw->cmd_out = (char *) malloc(path_size * sizeof(char *));
	if (smw->path == NULL || smw->cmd_in == NULL || smw->cmd_out == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		free(smw);
	}
	return (smw);
}

void	fill_smw(t_smw *smw, char *envp[], char *argv[])
{
	smw->path = find_path(envp);
	smw->cmd_in = find_cmd_path(smw, envp, argv[2]);
	smw->cmd_out = find_cmd_path(smw, envp, argv[3]);
	return ;
}

char	*find_cmd_path(t_smw *smw, char *envp[], char *argv)
{
	char	**path;
	char	*cmd;
	int		i;

	i = 0;
	path = find_path(envp);
	while (path[i] != NULL)
	{
		cmd = ft_strjoin("/", argv);
		cmd = ft_strjoin(smw->path[i], cmd);
		ft_printf("Does this work?? CMD = %s\n", cmd);
		if (access(cmd, F_OK) == 0)
		{
			ft_printf("HOORAY!! CMD = %s\n", cmd);
			break ;
		}
		i++;
	}
	path = ft_split(cmd, ' ');
	cmd = path[0];
	return (cmd);
}

char	**find_cmd_args(t_smw *smw, char *envp[], char *argv[])
{
	char	**path;
	char	*cmd;
	int		i;

	i = 0;
	path = find_path(envp);
	while (path[i] != NULL)
	{
		cmd = ft_strjoin("/", argv);
		cmd = ft_strjoin(smw->path[i], cmd);
		if (access(cmd, F_OK) == 0)
		{
			ft_printf("HOORAY!! CMD = %s\n", cmd);
			break ;
		}
		i++;
	}
	path = ft_split(cmd, ' ');
	path[0] = smw->cmd_in;
	i = 0;
	while (path[i] != NULL)
	{
		//path[i] = path[i + 1];
		ft_printf("Does this work?? Path = %s\n", path[i]);
		i++;
	}
	return (path);
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
