/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarquar <fmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:12:24 by fmarquar          #+#    #+#             */
/*   Updated: 2023/05/31 17:24:13 by fmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	destroy_pipe(t_pipe *my_pipe)
{
	if (my_pipe != NULL)
	{
		free(my_pipe->path);
		free(my_pipe);
	}
}
