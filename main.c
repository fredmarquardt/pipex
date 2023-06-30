/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarquar <fmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:54:59 by fmarquar          #+#    #+#             */
/*   Updated: 2023/06/29 10:11:33 by fmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

bool	cmd_check_return(char **cmd, char **path, char *acc2, bool boohoo);
bool	cmds_are_correct(char argv[], char *envp[]);

int	main2(int argc, char *argv[], char *envp[])
{
	char	*cmd1;
	t_smw	*smw;

	if (argc != 5)
	{
		ft_printf("Input Format: ./pipex file1 cmd1 cmd2 file2\n");
		return (0);
	}
	if (!envp)
		perror("env");
	smw = create_smw(argc, argv);
	fill_smw(smw, envp, argv);
	cmd1 = argv[2];
	execute(envp, smw, argv);
	free_smw(smw);
	if (waitpid(-1, NULL, WNOHANG) == -1)
		return (0);
	return (0);
}

int	main(int argc, char *argv[], char *envp[])
{
	main2(argc, argv, envp);
	//system("leaks pipex");
	return (0);
}

bool	cmds_are_correct(char argv[], char *envp[])
{
	char	**path;
	char	**cmd;
	char	*acc1;
	char	*acc2;
	int		i;

	i = 0;
	cmd = ft_split(argv, ' ');
	path = find_path(envp);
	while (path && path[i] != NULL)
	{
		acc1 = ft_strjoin("/", cmd[0]);
		acc2 = ft_strjoin(path[i], acc1);
		free(acc1);
		if (access(acc2, F_OK) == 0)
			return (cmd_check_return(cmd, path, acc2, TRUE));
		free(acc2);
		i++;
	}
	if (access(acc2, F_OK) != 0)
		return (cmd_check_return(cmd, path, acc2, FALSE));
	return (FALSE);
}

bool	cmd_check_return(char **cmd, char **path, char *acc2, bool boohoo)
{
	if (boohoo == TRUE)
		free(acc2);
	if (boohoo == FALSE)
		perror("command not found");
	free_double_char(cmd);
	free_double_char(path);
	return (boohoo);
}
