/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 21:31:39 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/19 22:19:46 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display_file.h"

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

int	ft_error(int argc)
{
	if (argc == 1)
		ft_putstr_err("File name missing.\n");
	else
		ft_putstr_err("Too many arguments.\n");
	return (0);
}
