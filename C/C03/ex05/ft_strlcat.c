/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 23:58:28 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/07 09:10:39 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	src_size;
	unsigned int	dest_size;
	unsigned int	i;
	unsigned int	expected_string_length;

	src_size = ft_strlen(src);
	dest_size = ft_strlen(dest);
	i = 0;
	if (size > dest_size)
	{
		expected_string_length = src_size + dest_size;
	}
	else
	{
		expected_string_length = size + src_size;
	}
	while (src[i] && dest_size + 1 < size)
	{
		dest[dest_size] = src[i];
		i++;
		dest_size++;
	}
	dest[dest_size] = '\0';
	return (expected_string_length);
}
