/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_parser_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 15:31:40 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/24 15:31:41 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

int	is_valid_line(char *line)
{
	int	i;

	i = 0;
	while (ft_is_space(line[i]))
		i++;
	if (!(line[i] >= '0' && line[i] <= '9'))
		return (0);
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	while (ft_is_space(line[i]))
		i++;
	if (line[i] != ':')
		return (0);
	i++;
	while (ft_is_space(line[i]))
		i++;
	if (!is_printable(line[i]))
		return (0);
	return (1);
}

static void	copy_value(char *dest, char *src, int start, int end)
{
	int	j;

	j = 0;
	while (start < end)
	{
		dest[j] = src[start];
		j++;
		start++;
	}
	dest[j] = '\0';
}

t_dict	extract_entry(char *line)
{
	t_dict	entry;
	int		num_s;
	int		num_e;
	int		val_s;
	int		val_e;

	get_key_indices(line, &num_s, &num_e);
	get_val_indices(line, &val_s, &val_e);
	entry.number = malloc(num_e - num_s + 1);
	entry.number_name = malloc(val_e - val_s + 1);
	if (!entry.number || !entry.number_name)
	{
		free(entry.number);
		free(entry.number_name);
		entry.number = NULL;
		entry.number_name = NULL;
		return (entry);
	}
	copy_value(entry.number, line, num_s, num_e);
	copy_value(entry.number_name, line, val_s, val_e);
	return (entry);
}

int	key_exists(t_big_int num, t_dict *dict, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (bigint_cmp(dict[i].number, num) == 0)
			return (1);
		i++;
	}
	return (0);
}
