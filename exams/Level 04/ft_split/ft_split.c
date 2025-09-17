/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 23:07:49 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/28 23:19:22 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int ft_sep(char c)
{
    if (c == ' ' || (c >= 9 && c <= 13))
        return (1);
    return (0);
}

int ft_total(char *str)
{
    int i;
    int length;
    int current_word_count;

    i = 0;
    length = 0;
    current_word_count = 0;
    while (str[i])
    {
        if (ft_sep(str[i]))
        {
            if (current_word_count)
            {
                length++;
                current_word_count = 0;
            }
        }
        else
            current_word_count++;
        i++;
    }
    if (current_word_count)
        length++;
    return (length);
}

int ft_get_wtalength(char *str)
{
    int i;

    i = 0;
    while (str[i] && !(ft_sep(str[i])))
        i++;
    return (i);
}

char    *ft_add(char *str, int size)
{
    char    *dest;
    int     i;

    i = 0;
    dest = (char *)malloc(sizeof(char) * (size + 1));
    if (!dest)
        return (NULL);
    while (i < size)
    {
        dest[i] = str[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char    **ft_split(char *str)
{
    char    **words;
    int     words_total;
    int     word_to_add_length;
    int     i;
    int     j;

    words_total = ft_total(str);
    words = (char **)malloc(sizeof(char *) * (words_total + 1));
    if (!words)
        return (NULL);
    i = 0;
    j = 0;
    word_to_add_length = 0;
    while (str[i])
    {
        while (ft_sep(str[i]))
            i++;
        word_to_add_length = ft_get_wtalength(&str[i]);
        if (word_to_add_length)
        {
            words[j] = ft_add(&str[i], word_to_add_length);
            j++;
        }
        i+= word_to_add_length;
    }
    words[j] = NULL;
    return (words);
}