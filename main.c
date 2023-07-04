/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarquar <fmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:54:59 by fmarquar          #+#    #+#             */
/*   Updated: 2023/07/04 14:23:41 by fmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

bool	cmd_check_return(char **cmd, char **path, char *acc2, bool boohoo);
bool	cmds_are_correct(char argv[], char *envp[]);

/* void	wait_exit(t_smw smw)
{
	pid_t	pid;

	ft_printf("Wait EXIT\n");
	pid = waitpid(smw->child_id1, NULL, 0);
	while (pid != -1)
		pid = waitpid(smw->child_id1, NULL, 0);
	return ;
} */
void	wait_exit(void)
{
	pid_t	pid;

	pid = waitpid(0, NULL, 0);
	while (pid != -1)
		pid = waitpid(0, NULL, 0);
}


int	main2(int argc, char *argv[], char *envp[])
{
	char	*cmd1;
	t_smw	*smw;
	int		statloc;

	if (argc != 5)
	{
		ft_printf("Input Format: ./pipex file1 cmd1 cmd2 file2\n");
		return (0);
	}
	/* if (cmds_are_correct(argv[2], envp) == FALSE)
		return (0);
	if (cmds_are_correct(argv[3], envp) == FALSE)
		return (0); */
	smw = create_smw(argc, argv);
	fill_smw(smw, envp, argv);
	cmd1 = argv[2];
	execute(&statloc, envp, smw, argv);
	//waitpid(-1, NULL, 0);
	/* waitpid(smw->child_id1, &statloc, WUNTRACED);
	waitpid(smw->child_id2, &statloc, WNOHANG); */
	//wait_exit();
	//while (waitpid(1, NULL, WUNTRACED) != -1);
	waitpid(smw->child_id1,NULL, 0);
	waitpid(smw->child_id2, NULL, 0);
	free_smw(smw);
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
