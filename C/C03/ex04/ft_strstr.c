/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 23:15:50 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/06 23:53:47 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	current_valid_length;
	int	to_find_length;

	i = 0;
	current_valid_length = 0;
	to_find_length = ft_strlen(to_find);
	while (str[i])
	{
		if (current_valid_length == to_find_length)
			return (&str[i - to_find_length]);
		if (str[i] == to_find[current_valid_length])
			current_valid_length++;
		else
			current_valid_length = 0;
		i++;
	}
	if (current_valid_length == to_find_length)
		return (&str[i - to_find_length]);
	return (0);
}
