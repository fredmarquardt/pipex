/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarquar <fmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:54:59 by fmarquar          #+#    #+#             */
/*   Updated: 2023/05/31 17:42:13 by fmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute(char *envp[]);

int	main(int argc, char *argv[], char *envp[])
{
	char	*cmd1;
	t_pipe	*pip;

	pip = create_t_pipe();
	if (argc != 5)
	{
		ft_printf("Input Format: ./pipex file1 cmd1 cmd2 file2\n");
		return (0);
	}
	fill_pipe(pip);
	cmd1 = argv[2];
	find_path(envp);
	ft_printf("Trolollol\n");
	execute(envp);
	destroy_pipe(pip);
	return (0);
}

t_pipe	*create_t_pipe(void)
{
	t_pipe	*my_pipe;
	int		path_size;

	my_pipe = (t_pipe *)malloc(sizeof(t_pipe));
	if (my_pipe == NULL)
	{
		ft_printf("Memory allocation failed\n");
		return (NULL);
	}
	path_size = 10;
	my_pipe->path = (char **) malloc(path_size * sizeof(char *));
	if (my_pipe->path == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		free(my_pipe);
		return (NULL);
	}
	return (my_pipe);
}



void	execute(char *envp[])
{
	char	cmd[] = "/bin/ls";
	char	*argv[] = {"ls", "-l", NULL};

	envp[0] = "/Users/fmarquar/Documents/gitrepos/";
	envp[1] = NULL;
	if (execve(cmd, argv, envp) == -1)
		ft_printf("Ooops! Something went wrong!\n");
	ft_printf("lollol\n");
	return ;
}
