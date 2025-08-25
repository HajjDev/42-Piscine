/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 15:32:06 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/24 15:32:07 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

t_dict	*init_dictionary(char *filename)
{
	int		dict_size;
	t_dict	*dict;

	dict_size = count_valid_lines(filename);
	if (dict_size <= 0)
	{
		ft_putstr("Dict Error\n");
		return (NULL);
	}
	dict = parse_dictionary(filename, dict_size);
	if (!dict)
		return (NULL);
	sort_dict(dict, get_dict_len(dict));
	return (dict);
}

void	process_line(char *line, t_dict *dict)
{
	char	*input_to_convert;
	int		first;

	if (!is_valid_number(line))
	{
		ft_putstr("Error\n");
		return ;
	}
	first = 1;
	input_to_convert = ft_strdup(line);
	if (!input_to_convert)
	{
		ft_putstr("Dict Error\n");
		return ;
	}
	convert_number(input_to_convert, dict, &first);
	ft_putstr("\n");
}

static void	process_stdin_char(char c, char *buffer, int *i, t_dict *dict)
{
	if (c == '\n')
	{
		buffer[*i] = '\0';
		if (*i > 0)
			process_line(buffer, dict);
		*i = 0;
	}
	else if (*i < 4095)
	{
		buffer[*i] = c;
		(*i)++;
	}
}

int	handle_input(char *dict_path)
{
	t_dict	*dict;
	char	buffer[4096];
	int		bytes_read;
	int		i;
	char	c;

	dict = init_dictionary(dict_path);
	if (!dict)
		return (1);
	i = 0;
	while (1)
	{
		bytes_read = read(0, &c, 1);
		if (bytes_read <= 0)
			break ;
		process_stdin_char(c, buffer, &i, dict);
	}
	free_dict(dict);
	return (0);
}
