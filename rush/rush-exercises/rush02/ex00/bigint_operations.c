/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 15:31:11 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/24 15:31:13 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

int	bigint_cmp(t_big_int s1, t_big_int s2)
{
	int	len1;
	int	len2;

	if (!s1 || !s2)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len1 != len2)
		return (len1 - len2);
	return (ft_strcmp(s1, s2));
}

t_big_int	trim_leading_zeros(t_big_int str)
{
	int		i;
	char	*new_str;

	if (!str || ft_strlen(str) <= 1)
		return (str);
	i = 0;
	while (str[i] == '0' && str[i + 1] != '\0')
		i++;
	if (i == 0)
		return (str);
	new_str = ft_strdup(&str[i]);
	free(str);
	return (new_str);
}

static void	sub_loop(int *v, t_big_int n1, t_big_int n2, char *res)
{
	int	borrow;
	int	sub;

	borrow = 0;
	while (v[2] >= 0)
	{
		sub = (n1[v[2]] - '0') - borrow;
		if (v[3] >= 0)
			sub -= (n2[v[3]] - '0');
		borrow = (sub < 0);
		if (borrow)
			sub += 10;
		res[v[2]] = sub + '0';
		v[2]--;
		v[3]--;
	}
}

t_big_int	bigint_sub(t_big_int n1, t_big_int n2)
{
	int		vars[4];
	char	*res;

	vars[0] = ft_strlen(n1);
	vars[1] = ft_strlen(n2);
	res = malloc(vars[0] + 1);
	if (!res)
		return (NULL);
	res[vars[0]] = '\0';
	vars[2] = vars[0] - 1;
	vars[3] = vars[1] - 1;
	sub_loop(vars, n1, n2, res);
	return (trim_leading_zeros(res));
}
