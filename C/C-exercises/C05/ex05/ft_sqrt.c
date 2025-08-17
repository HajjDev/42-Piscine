/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 12:28:11 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/09 14:35:44 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt_rec(int nb, int i)
{
	if (nb > 2147395600)
	{
		return (0);
	}
	if (i * i == nb)
	{
		return (i);
	}
	if (i * i < nb)
	{
		return (ft_sqrt_rec(nb, i + 1));
	}
	return (0);
}

int	ft_sqrt(int nb)
{
	return (ft_sqrt_rec(nb, 0));
}
