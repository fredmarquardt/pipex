/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_pipes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarquar <fmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:45:24 by fmarquar          #+#    #+#             */
/*   Updated: 2023/06/30 18:21:07 by fmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute(char *envp[], t_smw *smw, char *argv[])
{
	pipe(smw->end);
	mario_input(smw, envp, argv);
	luigi_output(smw, envp, argv);
	smw->luigi_cleared = TRUE;
	return ;
}

void	mario_input(t_smw *smw, char *envp[], char *argv[])
{
	int		fd_in;

	find_cmd_args_in(smw, argv[2], envp);
	fd_in = open(argv[1], O_RDWR);
	if (fd_in == -1)
		return (perror("ERROR"));
	smw->child_id1 = fork();
	if (smw->child_id1 == 0)
	{
		if (dup2(fd_in, STDIN_FILENO) == -1)
			return (perror("ERROR"));
		if (dup2(smw->end[1], STDOUT_FILENO) == -1)
			return (perror("ERROR"));
		close(fd_in);
		close(smw->end[1]);
		close(smw->end[0]);
		if (execve(smw->cmd_in, smw->args_in, envp) == -1)
			perror("ERROR");
		exit(1);
	}
	return ;
}

void	luigi_output(t_smw *smw, char *envp[], char *argv[])
{
	pid_t	child_id;
	int		fd_out;

	find_cmd_args_out(smw, argv[3], envp);
	fd_out = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd_out == -1)
		return (perror("Error"));
	child_id = fork();
	if (child_id == 0)
	{
		if (dup2(smw->end[0], STDIN_FILENO) == -1)
			return (perror("ERROR"));
		if (dup2(fd_out, STDOUT_FILENO) == -1)
			return (perror("ERROR"));
		if (access(smw->cmd_out, F_OK) != 0)
			return (perror("ERROR"));
		close(fd_out);
		close(smw->end[1]);
		close(smw->end[0]);
		if (execve(smw->cmd_out, smw->args_out, envp) == -1)
			return (perror("ERROR"));
		exit(1);
	}
	return ;
}
