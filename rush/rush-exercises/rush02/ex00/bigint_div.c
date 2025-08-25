/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint_div.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 15:31:02 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/24 15:31:06 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

static char	*process_div_digit(char *rem, t_big_int n2, char *q, int *q_idx)
{
	char	*new_rem;
	int		count;

	rem = trim_leading_zeros(rem);
	count = 0;
	while (bigint_cmp(rem, n2) >= 0)
	{
		new_rem = bigint_sub(rem, n2);
		free(rem);
		rem = new_rem;
		if (!rem)
			return (NULL);
		count++;
	}
	q[*q_idx] = count + '0';
	(*q_idx)++;
	return (rem);
}

static void	division_loop(t_big_int n1, t_big_int n2, t_big_int *q, char **rem)
{
	int		i;
	int		q_idx;
	int		len;
	char	*temp;

	i = 0;
	q_idx = 0;
	while (n1[i])
	{
		len = ft_strlen(*rem);
		temp = malloc(len + 2);
		if (temp)
		{
			ft_strcpy(temp, *rem);
			temp[len] = n1[i];
			temp[len + 1] = '\0';
		}
		free(*rem);
		*rem = temp;
		*rem = process_div_digit(*rem, n2, *q, &q_idx);
		if (!*rem || !*q)
			return ;
		i++;
	}
	(*q)[q_idx] = '\0';
}

void	perform_long_division(t_big_int n1, t_big_int n2, t_big_int *q,
		t_big_int *r)
{
	char	*rem;

	rem = malloc(ft_strlen(n1) + 2);
	*q = malloc(ft_strlen(n1) + 1);
	if (!rem || !*q)
	{
		free(rem);
		free(*q);
		*q = NULL;
		return ;
	}
	rem[0] = '\0';
	division_loop(n1, n2, q, &rem);
	if (!*q)
	{
		free(rem);
		return ;
	}
	*q = trim_leading_zeros(*q);
	*r = rem;
}

void	bigint_div_mod(t_big_int n1, t_big_int n2, t_big_int *q, t_big_int *r)
{
	if (ft_strlen(n2) == 1 && n2[0] == '0')
	{
		*q = NULL;
		*r = NULL;
		return ;
	}
	if (bigint_cmp(n1, n2) < 0)
	{
		*q = ft_strdup("0");
		*r = ft_strdup(n1);
		return ;
	}
	perform_long_division(n1, n2, q, r);
}
