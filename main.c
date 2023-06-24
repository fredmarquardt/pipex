/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarquar <fmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:54:59 by fmarquar          #+#    #+#             */
/*   Updated: 2023/06/24 19:48:32 by fmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main2(int argc, char *argv[], char *envp[])
{
	char	*cmd1;
	t_smw	*smw;

	if (argc != 5)
	{
		ft_printf("Input Format: ./pipex file1 cmd1 cmd2 file2\n");
		return (0);
	}
	smw = create_smw(argc, argv);
	fill_smw(smw, envp, argv);
	cmd1 = argv[2];
	execute(envp, smw, argv);
	free_smw(smw);
	return (0);
}

int	main(int argc, char *argv[], char *envp[])
{
	main2(argc, argv, envp);
	system("leaks pipex");
}
