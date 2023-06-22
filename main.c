/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarquar <fmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:54:59 by fmarquar          #+#    #+#             */
/*   Updated: 2023/06/22 10:27:22 by fmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	char	*cmd1;
	t_smw	*smw;

	smw = create_smw(argc, argv);
	fill_smw(smw, envp, argv);
	ft_printf("ENV: %s\n", smw->path[0]);
	ft_printf("ENV: %s\n", smw->path[1]);
	ft_printf("ENV: %s\n", smw->path[2]);
	if (argc != 5)
	{
		ft_printf("Input Format: ./pipex file1 cmd1 cmd2 file2\n");
		return (0);
	}
	//fill_pipe(smw, argv, envp);
	cmd1 = argv[2];
	find_path(envp);
	ft_printf("Trolollol\n");
	execute(envp, smw, argv);
	free_smw(smw);
	return (0);
}
