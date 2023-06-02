/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarquar <fmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 10:33:22 by fmarquar          #+#    #+#             */
/*   Updated: 2023/05/31 11:28:56 by fmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	find_path(char *envp[])
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
				printf("%s\n", path[j]);
				j++;
			}
		}
		i++;
	}
	return ;
}
