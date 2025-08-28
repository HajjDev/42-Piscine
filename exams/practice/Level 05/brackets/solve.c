/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 21:13:32 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/27 23:43:40 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brackets.h"

void	ft_solve(char *str)
{
    char	brackets[ft_strlen(str)];
    int     i;
    int     j;

    i = ft_strlen(str) - 1;
    j = -1;
    while (str[i])
    {
        if (str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
            j++;
            brackets[j] = str[i];
        }
        else if ((str[i] == '(' && brackets[j] == ')') || (str[i] == '{' && brackets[j] == '}') || (str[i] == '[' && brackets[j] == ']'))
        {
            brackets[j] = 0;
            j--;
        }
        else
        {
            if (str[i] == '(' || str[i] == '{' || str[i] == '[')
            {
                error();
                return ;
            }
        }
        i--;
    }
    if (brackets[0])
    {
        error();
        return ;
    }
    write(1, "OK\n", 3);
    return ;
}
