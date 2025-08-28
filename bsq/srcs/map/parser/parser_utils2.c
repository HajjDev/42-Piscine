/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:28:35 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/27 16:58:49 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	correct_map_info(int n, char **lines)
{
	int	i;

	if (n == 0)
		return (0);
	i = 0;
	while (lines[i + 1])
		i++;
	return (i == n);
}

int	follow_pattern(char **lines)
{
	int		i;
	int		len;
	char	legend[4];

	if (!lines[0])
		return (0);
	len = ft_strlen(lines[0]);
	if (len < 4)
		return (0);
	i = 0;
	while (i < len - 3)
	{
		if (!(lines[0][i] >= '0' && lines[0][i] <= '9'))
			return (0);
		i++;
	}
	assign_legend(lines[0], legend);
	if (legend[0] == legend[1] || legend[0] == legend[2]
		|| legend[1] == legend[2])
		return (0);
	if (!correct_map_info(ft_atoi(lines[0]), lines))
		return (0);
	return (correct_chars(legend, lines));
}

int	same_length(char **lines)
{
	int	i;
	int	len;

	if (!lines[1])
		return (1);
	len = ft_strlen(lines[1]);
	if (len == 0)
		return (0);
	i = 2;
	while (lines[i])
	{
		if (ft_strlen(lines[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

char	*resize_buffer(char *old, long size, long new_cap)
{
	char	*new_buf;
	long	i;

	new_buf = malloc(new_cap);
	if (!new_buf)
	{
		free(old);
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		new_buf[i] = old[i];
		i++;
	}
	free(old);
	return (new_buf);
}

void	ft_initialize_read(long *size, long *capacity, char **content)
{
	*size = 0;
	*capacity = BUF_SIZE;
	*content = malloc(*capacity);
}
