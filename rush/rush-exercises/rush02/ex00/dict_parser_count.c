/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_parser_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 15:31:27 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/24 15:31:29 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

static void	process_char_for_count(char c, char *line, long *i, int *count)
{
	if (c == '\n')
	{
		line[*i] = '\0';
		if (is_valid_line(line))
			(*count)++;
		*i = 0;
	}
	else if (*i < 1023)
	{
		line[*i] = c;
		(*i)++;
	}
}

int	count_valid_lines(char *file)
{
	int		fd;
	int		count;
	char	c;
	char	line[1024];
	long	i;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	count = 0;
	i = 0;
	while (read(fd, &c, 1) > 0)
		process_char_for_count(c, line, &i, &count);
	line[i] = '\0';
	if (i > 0 && is_valid_line(line))
		count++;
	close(fd);
	return (count);
}
