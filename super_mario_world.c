/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   super_mario_world.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarquar <fmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:26:46 by fmarquar          #+#    #+#             */
/*   Updated: 2023/06/26 14:56:54 by fmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_smw	*create_smw(int argc, char *argv[])
{
	t_smw	*smw;
	int		argc_in_cmd;
	int		i;

	i = argc;
	smw = (t_smw *)malloc(sizeof(t_smw));
	if (smw == NULL)
	{
		ft_printf("Memory allocation failed\n");
	}
	argc_in_cmd = count_c_in_string(argv[2], ' ' );
	smw->path = (char **) ft_calloc(argc_in_cmd + 2, sizeof(char *));
	smw->cmd_in = (char *) ft_calloc(1, sizeof(char));
	smw->cmd_out = (char *) ft_calloc(1, sizeof(char));
	if (smw->path == NULL || smw->cmd_in == NULL || smw->cmd_out == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		free(smw);
	}
	return (smw);
}

void	fill_smw(t_smw *smw, char *envp[], char *argv[])
{
	smw->in_opt = count_c_in_string(argv[2], ' ');
	smw->out_opt = count_c_in_string(argv[3], ' ');
	if (smw->path)
		free_double_char(smw->path);
	smw->path = find_path(envp);
	if (smw->cmd_in)
		free(smw->cmd_in);
	smw->cmd_in = find_cmd_path(envp, argv[2]);
	if (smw->cmd_out)
		free(smw->cmd_out);
	smw->cmd_out = find_cmd_path(envp, argv[3]);
	return ;
}
