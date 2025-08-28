/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:57:16 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/28 19:04:52 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int error(void)
{
    write(1, "\n", 1);
    return (0);
}

int ft_find(char *str, char c)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == c)
            return (i + 1);
        i++;
    }
    return (-1);
}

void    ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
    write(1, "\n", 1);
}

int main(int argc, char **argv)
{
    int i;
    int j;

    if (argc != 3)
        return (error());
    i = 0;
    j = 0;
    while (argv[1][i])
    {
        if (ft_find(&argv[2][j], argv[1][i]) != -1)
            j += ft_find(&argv[2][j], argv[1][i]);
        else
            return (error());
        i++;
    }
    ft_putstr(argv[1]);
    return (0);
}