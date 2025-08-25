/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 15:31:22 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/24 15:31:23 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

int	handle_direct_cases(t_big_int num, t_dict *dict, int *first)
{
	t_dict	*entry;

	if (bigint_cmp(num, "0") == 0)
	{
		if (*first)
		{
			entry = find_entry("0", dict);
			if (entry)
				ft_putstr(entry->number_name);
		}
		*first = 0;
		return (1);
	}
	entry = find_entry(num, dict);
	if (entry)
	{
		if (!(*first))
			ft_putstr(" ");
		ft_putstr(entry->number_name);
		*first = 0;
		return (1);
	}
	return (0);
}

void	convert_number(t_big_int n, t_dict *dict, int *first)
{
	t_dict		*entry;
	t_big_int	num_to_process;

	num_to_process = ft_strdup(n);
	free(n);
	if (!num_to_process)
	{
		ft_error("Dict Error\n");
		return ;
	}
	num_to_process = trim_leading_zeros(num_to_process);
	if (handle_direct_cases(num_to_process, dict, first))
	{
		free(num_to_process);
		return ;
	}
	entry = find_largest_smaller(num_to_process, dict);
	if (!entry)
		ft_error("Dict Error\n");
	else if (bigint_cmp(entry->number, "100") >= 0)
		process_division(num_to_process, entry, dict, first);
	else
		process_subtraction(num_to_process, entry, dict, first);
	free(num_to_process);
}
