/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 23:12:35 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/09 23:44:32 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i ++;
	}
	return (i);
}

int	ft_total_length(int size, char **strs, char *sep)
{
	int	strs_length;
	int	sep_length;
	int	i;

	i = 0;
	strs_length = 0;
	sep_length = (size - 1) * ft_strlen(sep);
	while (i < size)
	{
		strs_length += ft_strlen(strs[i]);
		i++;
	}
	return (strs_length + sep_length + 1);
}

char	*ft_null_str(void)
{
	char	*empty_string;

	empty_string = malloc(1);
	if (empty_string == NULL)
		return (0);
	empty_string[0] = '\0';
	return (empty_string);
}

void	ft_insert_sep(char	*str, int *c, char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		str[(*c)] = sep[i];
		i++;
		(*c)++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*final_string;
	int		final_string_length;
	int		i;
	int		j;
	int		c;

	if (size == 0)
		return (ft_null_str());
	final_string_length = ft_total_length(size, strs, sep);
	final_string = malloc(sizeof(char) * final_string_length);
	i = 0;
	c = 0;
	if (final_string == NULL)
		return (0);
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			final_string[c++] = strs[i][j++];
		if (i != size - 1)
			ft_insert_sep(final_string, &c, sep);
		i++;
	}
	final_string[c] = '\0';
	return (final_string);
}
