/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_pipes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarquar <fmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:45:24 by fmarquar          #+#    #+#             */
/*   Updated: 2023/06/22 16:23:32 by fmarquar         ###   ########.fr       */
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
	pipe(smw->end);
	ft_printf("Pipe successfull\n");
	mario_input(smw, envp, argv);
	ft_printf("mario successfull\n");
	luigi_output(smw, envp, argv);
	ft_printf("luigi successfull\n");
	return ;
}

void	mario_input(t_smw *smw, char *envp[], char *argv[])
{
	int		child_id;
	int		fd_in;

	find_cmd_args_in(smw, argv[2], envp);
	fd_in = open(argv[1], O_RDWR);
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
		if (execve(smw->cmd_in, smw->args_in, envp) == -1)
			perror("Ooops! Something went wrong!\n");
		ft_printf("Auftrag ausgefuehrt!!!\n");
	}
	return ;
}

void	luigi_output(t_smw *smw, char *envp[], char *argv[])
{
	int		child_id;
	int		fd_out;

	find_cmd_args_out(smw, argv[3], envp);
	fd_out = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	child_id = fork();
	if (child_id == 0)
	{
		ft_printf("Zweites Kind\n");
		if (dup2(smw->end[0], STDIN_FILENO) == -1)
			ft_printf("\nERROR\n");
		if (dup2(fd_out, STDOUT_FILENO) == -1)
			ft_printf("\nERROR\n");
		if (access(smw->cmd_out, F_OK) != 0)
			ft_printf("Da hat sich der Fehlerteufel eingeschlichen\n");
		if (execve(smw->cmd_out, smw->args_out, envp) == -1)
			perror("Ooops! Something went wrong!\n");
		ft_printf("Auftrag ausgefuehrt!!!\n");
		close(fd_out);
		close(smw->end[1]);
		ft_printf("Auftrag ausgefuehrt!!!\n");
	}
	ft_printf("%i\nwo bin ich gelandet?\n", fd_out);
	return ;
}
