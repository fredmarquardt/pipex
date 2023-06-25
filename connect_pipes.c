/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_pipes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarquar <fmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:45:24 by fmarquar          #+#    #+#             */
/*   Updated: 2023/06/25 18:49:31 by fmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute(char *envp[], t_smw *smw, char *argv[])
{
	pipe(smw->end);
	mario_input(smw, envp, argv);
	luigi_output(smw, envp, argv);
	return ;
}

void	mario_input(t_smw *smw, char *envp[], char *argv[])
{
	pid_t	child_id;
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
		ft_printf("Duplikation 1 abgeschlossen\n");
		close(fd_in);
		close(smw->end[1]);
		if (execve(smw->cmd_in, smw->args_in, envp) == -1)
			perror("Ooops! Something went wrong!\n");
		ft_printf("Auftrag ausgefuehrt!!!\n");
	}
	//waitpid(child_id, NULL, 0);
	return ;
}

void	luigi_output(t_smw *smw, char *envp[], char *argv[])
{
	pid_t	child_id;
	int		fd_out;

	find_cmd_args_out(smw, argv[3], envp);
	fd_out = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	child_id = fork();
	ft_printf("Child ID: %i\n", child_id);
	if (child_id == 0)
	{
		ft_printf("Zweites Kind\n");
		if (dup2(smw->end[0], STDIN_FILENO) == -1)
			ft_printf("\nERROR\n");
		if (dup2(fd_out, STDOUT_FILENO) == -1)
			ft_printf("\nERROR\n");
		ft_printf("Duplikation abgeschlossen\n");
		if (access(smw->cmd_out, F_OK) != 0)
			ft_printf("Da hat sich der Fehlerteufel eingeschlichen\n");
		ft_printf("mach ma hinne\n");
		close(fd_out);
		close(smw->end[1]);
		if (execve(smw->cmd_out, smw->args_out, envp) == -1)
			perror("Ooops! Something went wrong!\n");
		ft_printf("Auftrag ausgefuehrt!!!\n");
		ft_printf("Auftrag ausgefuehrt!!!\n");
	}
	//waitpid(0, NULL, 0);
	ft_printf("%i\nwo bin ich gelandet?\n", fd_out);
	return ;
}
