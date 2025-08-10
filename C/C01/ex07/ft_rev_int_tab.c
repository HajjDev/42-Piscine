/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 23:41:44 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/05 23:47:49 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	replacement;

	i = 0;
	j = size - 1;
	while (i < size / 2)
	{
		replacement = tab[i];
		tab[i] = tab[j];
		tab[j] = replacement;
		i++;
		j--;
	}
}
