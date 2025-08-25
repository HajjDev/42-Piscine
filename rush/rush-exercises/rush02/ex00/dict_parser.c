/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 15:31:45 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/24 16:26:39 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

static void	process_fill_buffer(char *line, t_dict *dict, int *idx)
{
	t_dict	entry;

	if (is_valid_line(line))
	{
		entry = extract_entry(line);
		if (!entry.number || !entry.number_name)
		{
			free(entry.number);
			free(entry.number_name);
			return ;
		}
		if (!key_exists(entry.number, dict, *idx))
		{
			dict[*idx] = entry;
			(*idx)++;
		}
		else
		{
			free(entry.number);
			free(entry.number_name);
		}
	}
}

static void	process_char_for_fill(char c, struct s_fill_vars *vars)
{
	if (c == '\n')
	{
		vars->line[vars->i] = '\0';
		process_fill_buffer(vars->line, vars->dict, &vars->dict_idx);
		vars->i = 0;
	}
	else if (vars->i < 1023)
	{
		vars->line[vars->i] = c;
		(vars->i)++;
	}
}

static int	fill_dict(char *file, t_dict *dict)
{
	int						fd;
	char					c;
	struct s_fill_vars		vars;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	vars.i = 0;
	vars.dict_idx = 0;
	vars.dict = dict;
	while (read(fd, &c, 1) > 0)
		process_char_for_fill(c, &vars);
	vars.line[vars.i] = '\0';
	if (vars.i > 0)
		process_fill_buffer(vars.line, dict, &vars.dict_idx);
	close(fd);
	return (vars.dict_idx);
}

t_dict	*parse_dictionary(char *file, int size)
{
	t_dict	*dict;
	int		actual_size;

	dict = malloc(sizeof(t_dict) * (size + 1));
	if (!dict)
	{
		ft_putstr("Dict Error\n");
		return (NULL);
	}
	actual_size = fill_dict(file, dict);
	if (actual_size == -1)
	{
		free(dict);
		ft_putstr("Dict Error\n");
		return (NULL);
	}
	dict[actual_size].number_name = NULL;
	dict[actual_size].number = NULL;
	return (dict);
}
