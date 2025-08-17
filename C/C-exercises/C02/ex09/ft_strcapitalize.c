/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 12:42:30 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/06 13:36:22 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;
	int	c;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			c = str[i];
			c += 32;
			str[i] = (char)c;
		}
		i++;
	}
	return (str);
}

int	ft_isvalid(char l)
{
	if (!(l >= 'a' && l <= 'z'))
	{
		if (!(l >= 'A' && l <= 'Z'))
		{
			if (!(l >= '0' && l <= '9'))
			{
				return (0);
			}
		}
	}
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	c;

	str = ft_strlowcase(str);
	i = 0;
	while (str[i])
	{
		if (i == 0 && str[i] >= 'a' && str[i] <= 'z')
		{
			c = str[i];
			c -= 32;
			str[i] = (char)c;
		}
		else if (!(ft_isvalid(str[i - 1])))
		{
			if (str[i] >= 'a' && str[i] <= 'z')
			{
				c = str[i];
				c -= 32;
				str[i] = (char)c;
			}
		}
		i++;
	}
	return (str);
}
