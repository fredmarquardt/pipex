/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarquar <fmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:11:22 by fmarquar          #+#    #+#             */
/*   Updated: 2023/05/31 17:43:53 by fmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"

//struct
typedef struct s_pipe
{
	int			fd1;
	int			fd2;
	char		**path;
}t_pipe;

//main
void			execute(char *envp[]);
t_pipe			*create_t_pipe(void);

//connect_pipes.c

//pathfinder.c
void			find_path(char **envp);

//free_stuff
void			destroy_pipe(t_pipe *my_pipe);

#endif