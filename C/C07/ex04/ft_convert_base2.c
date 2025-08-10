/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 00:02:51 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/10 00:14:16 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_valid_base(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (!(str[0]) || !(str[1]))
		return (0);
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
		{
			return (0);
		}
		j = i + 1;
		while (str[j])
		{
			if (str[j] == str[i])
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_pre_traversal(int *i, int *signe, char *str)
{
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
	{
		(*i)++;
	}
	while (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
		{
			*signe *= -1;
		}
		(*i)++;
	}
}

int	ft_find(char *base, char to_find)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == to_find)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

int	ft_strlen(char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		i++;
	}
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	valid_base;
	int	signe;
	int	nb;
	int	length;
	int	i;

	valid_base = ft_check_valid_base(base);
	if (valid_base)
	{
		i = 0;
		signe = 1;
		length = ft_strlen(base);
		ft_pre_traversal(&i, &signe, str);
		nb = 0;
		while (str[i] && (ft_find(base, str[i]) != -1))
		{
			nb = (nb * length) + ft_find(base, str[i]);
			i++;
		}
		return (nb * signe);
	}
	return (0);
}
