/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 15:31:16 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/24 15:31:18 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

void	process_division(t_big_int num, t_dict *entry, t_dict *dict, int *first)
{
	t_big_int	quotient;
	t_big_int	remainder;

	bigint_div_mod(num, entry->number, &quotient, &remainder);
	if (!quotient || !remainder)
	{
		ft_error("Dict Error\n");
		free(quotient);
		free(remainder);
		return ;
	}
	convert_number(quotient, dict, first);
	ft_putstr(" ");
	ft_putstr(entry->number_name);
	*first = 0;
	if (bigint_cmp(remainder, "0") != 0)
	{
		convert_number(remainder, dict, first);
	}
	else
		free(remainder);
}

void	process_subtraction(t_big_int num, t_dict *entry, t_dict *dict, int *f)
{
	t_big_int	remainder;

	if (!(*f))
		ft_putstr(" ");
	ft_putstr(entry->number_name);
	*f = 0;
	remainder = bigint_sub(num, entry->number);
	if (!remainder)
	{
		ft_error("Dict Error\n");
		return ;
	}
	if (bigint_cmp(remainder, "0") != 0)
	{
		convert_number(remainder, dict, f);
	}
	else
		free(remainder);
}
