/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 00:06:54 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/10 12:29:28 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);
int	ft_strlen(char *base);
int	ft_check_valid_base(char *str);

void	ft_reverse(char *str, int size, int start)
{
	int		i;
	int		j;
	char	temp;

	i = start;
	j = size;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}

int	ft_digits(int nbr, char *base)
{
	int				base_length;
	int				digits;
	unsigned int	n;

	if (nbr == 0)
		return (1);
	base_length = ft_strlen(base);
	digits = 0;
	if (nbr < 0)
		n = -nbr;
	else
		n = nbr;
	while (n > 0)
	{
		digits += 1;
		n /= base_length;
	}
	return (digits);
}

char	*convert(char *number, int c_number, char *base, int base_length)
{
	int				i;
	unsigned long	n;
	int				is_negative;

	i = 0;
	is_negative = 0;
	if (c_number < 0)
	{
		number[0] = '-';
		is_negative++;
		n = -c_number;
		i++;
	}
	else
		n = c_number;
	while (n > 0)
	{
		number[i] = base[n % base_length];
		n /= base_length;
		i++;
	}
	number[i] = '\0';
	ft_reverse(number, ft_strlen(number) - 1, is_negative);
	return (number);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		converted_number;
	int		digits_needed;
	char	*number;

	if (!(ft_check_valid_base(base_from)) || !(ft_check_valid_base(base_to)))
		return (0);
	converted_number = ft_atoi_base(nbr, base_from);
	if (converted_number == 0)
	{
		number = malloc(2);
		if (number == NULL)
			return (0);
		number[0] = base_to[0];
		number[1] = '\0';
		return (number);
	}
	digits_needed = ft_digits(converted_number, base_to) + 1;
	if (converted_number < 0)
		digits_needed++;
	number = malloc(digits_needed * sizeof(char));
	if (number == NULL)
		return (0);
	return (convert(number, converted_number, base_to, ft_strlen(base_to)));
}
