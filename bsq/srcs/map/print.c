/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:25:39 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/27 16:25:40 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_print(char **map)
{
	char	*start_ptr;
	long	map_data_size;
	int		i;

	if (!map || !map[0])
	{
		if (map)
			free(map);
		return ;
	}
	start_ptr = map[0];
	i = 0;
	while (map[i + 1])
	{
		*(map[i + 1] - 1) = '\n';
		i++;
	}
	map_data_size = (map[i] + ft_strlen(map[i])) - start_ptr;
	write(1, start_ptr, map_data_size);
	write(1, "\n", 1);
	free(map);
}
