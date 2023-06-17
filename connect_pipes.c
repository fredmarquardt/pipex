/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_pipes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarquar <fmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:45:24 by fmarquar          #+#    #+#             */
/*   Updated: 2023/06/17 18:32:10 by fmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* void	fill_pipe(t_smw smw char *argv[], char *envp[])
{
	pip.path = find_path(envp);
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
		pip.heredoc = 1;
	return ;
} */

void	execute(char *envp[], t_smw *smw, char *argv[])
{
	envp[0] = "/Users/fmarquar/Documents/gitrepos/pipex/";
	envp[1] = NULL;
	pipe(smw->end);
	mario_input(smw, envp, argv);
	luigi_output(smw, envp);
	ft_printf("Gabel oder was???\n");
	return ;
}

void	mario_input(t_smw *smw, char *envp[], char *argv[])
{
	char	**cmd_args;
	int		child_id;
	int		fd_in;

	cmd_args = find_cmd_args(smw, envp, argv);
	//cmd_args = ft_strjoin(smw)
	fd_in = open("test.txt", O_RDWR);
	child_id = fork();
	if (child_id == 0)
	{
		ft_printf("Erstes Kind\n");
		if (dup2(fd_in, STDIN_FILENO) == -1)
			ft_printf("\nERROR\n");
		if (dup2(smw->end[1], STDOUT_FILENO) == -1)
			ft_printf("\nERROR\n");
		close(fd_in);
		close(smw->end[1]);
		ft_printf("%i\nlollol\n", fd_in);
		ft_printf("%i\n123GuteLaune\n", fd_in);
		if (execve(smw->cmd_in, cmd_args, envp) == -1)
			ft_printf("Ooops! Something went wrong!\n");
		ft_printf("Auftrag ausgefuehrt!!!\n");
	}
	waitpid(child_id, NULL, 0);
	return ;
}

void	luigi_output(t_smw *smw, char *envp[])
{
	char	cmd[] = "/bin/cat";
	char	*argv[] = {"bin/cat", NULL};
	int		child_id;
	int		fd_out;

	fd_out = open("output.txt", O_RDWR | O_CREAT | O_APPEND, 0644);
	child_id = fork();
	if (child_id == 0)
	{
		ft_printf("Zweites Kind\n");
		if (dup2(smw->end[0], STDIN_FILENO) == -1)
			ft_printf("\nERROR\n");
		if (dup2(fd_out, STDOUT_FILENO) == -1)
			ft_printf("\nERROR\n");
		ft_printf("Landet das jetzt im Textfile??\n");
		if (access(cmd, F_OK) != 0)
			ft_printf("CMD2:%s\nDa hat sich der Fehlerteufel eingeschlichen\n", cmd);
		if (execve(cmd, argv, envp) == -1)
			ft_printf("Ooops! Something went wrong!\n");
		close(fd_out);
		close(smw->end[1]);
		ft_printf("Auftrag ausgefuehrt!!!\n");
	}
	//waitpid(c_id, NULL, 0);
	ft_printf("%i\nwo bin ich gelandet?\n", fd_out);
	return ;
}