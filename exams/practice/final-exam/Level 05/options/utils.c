/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 21:35:06 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/26 21:58:15 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "options.h"

int ft_find(char *str, char c)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (c == str[i])
            return (1);
        i++;
    }
    return (0);
}

void	ft_add(char *options, char bits[])
{
	int	i;

	i = 0;
	while (options[i])
	{
		bits[options[i] - 'a'] = '1';
		i++;
	}
}

int error(void)
{
    write(1, "Invalid Option\n", 16);
    return (0);
}

void    ft_putstr(char str[])
{
    int i;

    i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}

int ft_valid(char *option)
{
    int i;

    i = 0;
    if (option[0] == '-')
    {
        i++;
        while (option[i])
        {
            if (!(ft_find("abcdefghijklmnopqrstuvwxyz", option[i])))
                return (0);
            i++;
        }
        return (1);
    }
    return (0);
}