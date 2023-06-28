/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarquar <fmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:11:22 by fmarquar          #+#    #+#             */
/*   Updated: 2023/06/27 18:34:28 by fmarquar         ###   ########.fr       */
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

# define FALSE 0
# define TRUE 1

//struct Super Mario World
typedef struct s_smw
{
	int			in_opt;
	int			out_opt;
	int			end[2];
	pid_t		child_id1;
	pid_t		child_id2;
	bool		luigi_cleared;
	char		**path;
	char		**args_in;
	char		**args_out;
	char		*cmd_in;
	char		*cmd_out;
}t_smw;

//main
int				main(int argc, char *argv[], char *envp[]);

//super_mario_world.c
t_smw			*create_smw(int argc, char *argv[]);
void			fill_smw(t_smw *smw, char *envp[], char *argv[]);

//connect_pipes.c
void			fill_pipe(t_smw *smw, char *argv[], char *envp[]);
void			execute(char *envp[], t_smw *smw, char *argv[]);
void			mario_input(t_smw *smw, char *envp[], char *argv[]);
void			luigi_output(t_smw *smw, char *envp[], char *argv[]);

//pathfinder.c
char			*find_cmd_path(char *envp[], char *argv);
char			**find_path(char *envp[]);
void			find_cmd_args_in(t_smw *smw, char *argv, char *envp[]);
void			find_cmd_args_out(t_smw *smw, char *argv, char *envp[]);

//free_stuff
void			free_smw(t_smw *smw);
void			free_double_char(char **stuff);

//utils
int				count_c_in_string(char *string, char c);

#endif