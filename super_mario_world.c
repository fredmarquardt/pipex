/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   super_mario_world.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarquar <fmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:26:46 by fmarquar          #+#    #+#             */
/*   Updated: 2023/06/19 15:05:53 by fmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h";

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
	smw->in_opt = count_c_in_string(argv[2], " ");
	smw->out_opt = count_c_in_string(argv[3], " ");
	smw->path = find_path(envp);
	smw->cmd_in = find_cmd_path(smw, envp, argv[2]);
	smw->cmd_out = find_cmd_path(smw, envp, argv[3]);
	return ;
}