/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 15:31:50 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/24 15:31:52 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

void	free_dict(t_dict *dict)
{
	int	i;

	i = 0;
	if (!dict)
		return ;
	while (dict[i].number_name != NULL)
	{
		free(dict[i].number);
		free(dict[i].number_name);
		i++;
	}
	free(dict);
}

void	sort_dict(t_dict *dict, int size)
{
	int		i;
	int		j;
	t_dict	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (bigint_cmp(dict[j].number, dict[j + 1].number) > 0)
			{
				temp = dict[j];
				dict[j] = dict[j + 1];
				dict[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

t_dict	*find_entry(t_big_int n, t_dict *dict)
{
	int	i;

	i = 0;
	while (dict[i].number_name != NULL)
	{
		if (bigint_cmp(dict[i].number, n) == 0)
			return (&dict[i]);
		i++;
	}
	return (NULL);
}

t_dict	*find_largest_smaller(t_big_int n, t_dict *dict)
{
	int		i;
	t_dict	*found;

	i = 0;
	found = NULL;
	while (dict[i].number_name != NULL)
	{
		if (bigint_cmp(dict[i].number, n) <= 0)
			found = &dict[i];
		i++;
	}
	return (found);
}

int	get_dict_len(t_dict *dict)
{
	int	i;

	i = 0;
	if (!dict)
		return (0);
	while (dict[i].number_name != NULL)
		i++;
	return (i);
}
