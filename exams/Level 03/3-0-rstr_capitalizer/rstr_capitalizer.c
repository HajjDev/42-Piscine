/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 21:04:06 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/28 21:05:50 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
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
}

void    ft_str_cap(char *str)
{
    int i;

    if (!str)
        return ;
    i = 0;
    while (str[i])
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        i++;
    }
    i = ft_strlen(str) - 2;
    if (str[ft_strlen(str) - 1] >= 'a' && str[ft_strlen(str) - 1] <= 'z')
        str[ft_strlen(str) - 1] -= 32;
    while (str[i])
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            if (str[i + 1] == ' ' || (str[i + 1] >= 9 && str[i + 1] <= 13))
                str[i] -= 32;
        }
        i--;
    }
    ft_putstr(str);
}

int main(int argc, char **argv)
{
    int i;

    if (argc < 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    i = 1;
    while (argv[i])
    {
        ft_str_cap(argv[i]);
        write(1, "\n", 1);
        i++;
    }
    return (0);
}