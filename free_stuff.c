/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarquar <fmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:12:24 by fmarquar          #+#    #+#             */
/*   Updated: 2023/06/23 15:38:16 by fmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//free Super Mario World from Bowser - or Stuff that was allocated before
void	free_smw(t_smw *smw)
{
	free_double_char(smw->path);
	if (smw != NULL)
		free(smw);
	//free(smw->path);
	ft_printf("Prinzessin befreit\n");
	return ;
}

void	free_double_char(char **stuff)
{
	int	i;

	i = 0;
	if (stuff[0] != NULL)
	{
		while (stuff[i] != NULL)
		{
			free (stuff[i]);
			i++;
		}
	}
	return ;
}
