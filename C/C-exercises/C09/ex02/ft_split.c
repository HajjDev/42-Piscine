/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 10:07:35 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/12 08:17:26 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_seperator(char c, char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (sep[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_count(char *str, char *sep)
{
	int	i;
	int	word_count;
	int	current_word_length;

	i = 0;
	word_count = 0;
	current_word_length = 0;
	while (str[i])
	{
		if (ft_is_seperator(str[i], sep))
		{
			if (current_word_length > 0)
			{
				word_count++;
				current_word_length = 0;
			}
		}
		else
			current_word_length++;
		i++;
	}
	if (current_word_length > 0)
		word_count++;
	return (word_count);
}

int	ft_get_word_to_add_length(char *str, char *sep)
{
	int	length;

	length = 0;
	while (str[length] && !(ft_is_seperator(str[length], sep)))
	{
		length++;
	}
	return (length);
}

char	*ft_add_word(char *str, int length)
{
	int		i;
	char	*word;

	word = malloc((length + 1) * sizeof(char));
	if (word == NULL)
		return (0);
	i = 0;
	while (i < length)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**strings;
	int		word_to_add_length;
	int		i;
	int		j;

	strings = (char **)malloc((ft_count(str, charset) + 1) * sizeof(char *));
	if (strings == NULL)
		return (0);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (ft_is_seperator(str[i], charset))
			i++;
		word_to_add_length = ft_get_word_to_add_length(&str[i], charset);
		if (word_to_add_length)
		{
			strings[j] = ft_add_word(&str[i], word_to_add_length);
			j++;
		}
		i += word_to_add_length;
	}
	strings[j] = 0;
	return (strings);
}

/*
#include <stdio.h>

void print_split(char **split)
{
    int i = 0;
    while (split[i])
    {
        printf("Word %d: \"%s\"\n", i, split[i]);
        i++;
    }
}

int main(void)
{
    char str1[] = "Hello world this is C";
    char charset1[] = " ";

    char str2[] = "abc,def;ghi";
    char charset2[] = ",;";

    char **result;

    // Test 1
    printf("Test 1:\n");
    result = ft_split(str1, charset1);
    print_split(result);

    for (int i = 0; result[i]; i++)
        free(result[i]);
    free(result);

    // Test 2
    printf("\nTest 2:\n");
    result = ft_split(str2, charset2);
    print_split(result);

    for (int i = 0; result[i]; i++)
        free(result[i]);
    free(result);

    return 0;
}
*/