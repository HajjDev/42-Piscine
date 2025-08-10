/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 10:07:35 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/10 10:50:12 by cel-hajj         ###   ########.fr       */
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
