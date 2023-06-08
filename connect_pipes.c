/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_pipes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarquar <fmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:45:24 by fmarquar          #+#    #+#             */
/*   Updated: 2023/06/07 15:20:40 by fmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fill_pipe(t_pipe pip, char *argv[], char *envp[])
{
	pip.path = find_path(envp);
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
		pip.heredoc = 1;
	return ;
}
