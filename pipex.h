/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarquar <fmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:11:22 by fmarquar          #+#    #+#             */
/*   Updated: 2023/06/14 14:18:26 by fmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"

//struct Super Mario World
typedef struct s_smw
{
	int			fd1;
	int			fd2;
	int			end[2];
	bool		heredoc;
	char		**path;
}t_smw;

//main
int				main(int argc, char *argv[], char *envp[]);

//connect_pipes.c
void			fill_pipe(t_smw *smw, char *argv[], char *envp[]);
void			execute(char *envp[], t_smw *smw);
void			mario_input(t_smw *smw, char *envp[]);
void			luigi_output(t_smw *smw, char *envp[]);
//pathfinder.c
t_smw			*create_smw(int argc);
void			fill_smw(t_smw smw);
char			**find_path(char *envp[]);

//free_stuff
void			free_smw(t_smw *smw);

#endif