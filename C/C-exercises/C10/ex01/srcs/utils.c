/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 22:54:03 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/20 21:08:46 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"

void	ft_putstr_err(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}

int	ft_showerror(char *prog, char *filename)
{
	ft_putstr_err(prog);
	ft_putstr_err(": ");
	ft_putstr_err(filename);
	ft_putstr_err(": ");
	ft_putstr_err(strerror(errno));
	ft_putstr_err("\n");
	return (1);
}
