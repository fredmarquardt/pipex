/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarquar <fmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 10:33:22 by fmarquar          #+#    #+#             */
/*   Updated: 2023/06/14 14:12:27 by fmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_smw	*create_smw(int argc)
{
	t_smw	*smw;
	int		path_size;

	ft_printf("Number of arguments: %i\n", argc);
	smw = (t_smw *)malloc(sizeof(t_smw));
	if (smw == NULL)
	{
		ft_printf("Memory allocation failed\n");
	}
	path_size = 10;
	smw->path = (char **) malloc(path_size * sizeof(char *));
	if (smw->path == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		free(smw);
	}
	return &(*smw);
}

void	fill_smw(t_smw smw)
{
	pipe(smw.end);
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
