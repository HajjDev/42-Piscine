/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 23:20:30 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/28 23:38:33 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void    ft_putchar(char c)
{
    if (c >= 32 && c <= 126)
        write(1, &c, 1);
}

int ft_match(char *code, int i)
{
    int balance;

    balance = 0;
    if (code[i] == '[')
    {
        i++;
        while (!(code[i] == ']' && balance == 0))
        {
            if (code[i] == '[')
                balance++;
            else if (code[i] == ']')
                balance--;
            i++;
        }
        i--;
    }
    else if (code[i] == ']')
    {
        i--;
        while (!(code[i] == '[' && balance == 0))
        {
            if (code[i] == ']')
                balance++;
            else if (code[i] == '[')
                balance--;
            i--;
        }
        i--;
    }
    return (i);
}

void    ft_brainfuck(char *code)
{
    int     i;
    char    bytes[2048];
    int     pointer;

    i = 0;
    pointer = 0;
    while (i < 2048)
    {
        bytes[i] = 0;
        i++;
    }
    i = 0;
    while (code[i])
    {
        if (code[i] == '>')
            pointer++;
        else if (code[i] == '<')
            pointer--;
        else if (code[i] == '+')
            bytes[pointer]++;
        else if (code[i] == '-')
            bytes[pointer]--;
        else if (code[i] == '.')
            ft_putchar(bytes[pointer]);
        else if (code[i] == '[')
        {
            if (bytes[pointer] == 0)
                i = ft_match(code, i);
        }
        else if (code[i] == ']')
        {
            if (bytes[pointer] != 0)
                i = ft_match(code, i);
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    ft_brainfuck(argv[1]);
    return (0);
}