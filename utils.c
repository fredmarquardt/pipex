/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarquar <fmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:51:00 by fmarquar          #+#    #+#             */
/*   Updated: 2023/06/19 12:59:05 by fmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count_c_in_string(char *string, char c)
{
	int	i;
	int	special_k;

	i = 0;
	special_k = 0;
	while (string[i] != NULL)
	{
		if (string[i] == c)
			special_k++;
		i++;
	}
	return (special_k);
}
