/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:17:12 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/12 22:56:45 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calculator.h"

int	ft_is_valid_operator(char *operator)
{
	if (operator[1] != '\0')
		return (0);
	if (!(operator[0] == '-' || operator[0] == '+'
			|| operator[0] == '/' || operator[0] == '%' || operator[0] == '*'))
		return (0);
	return (1);
}

int	ft_check_forbidden(int num, char *op)
{
	if (num == 0 && op[0] == '/')
	{
		ft_putstr("Stop : division by zero");
		return (1);
	}
	else if (num == 0 && op[0] == '%')
	{
		ft_putstr("Stop : modulo by zero");
		return (1);
	}
	return (0);
}

void	ft_handle_operations(char *a, char *b, char *c)
{
	int	n1;
	int	n2;

	if (ft_is_valid_operator(b))
	{
		n1 = ft_atoi(a);
		n2 = ft_atoi(c);
		if (!(ft_check_forbidden(n2, b)))
			operate(n1, b, n2);
	}
	else
	{
		ft_putchar('0');
	}
}

void	operate(int a, char *op, int b)
{
	int	result;
	int	(*operator[5])(int, int);

	operator[0] = &ft_add;
	operator[1] = &ft_substract;
	operator[2] = &ft_mul;
	operator[3] = &ft_div;
	operator[4] = &ft_modulo;
	if (op[0] == '+')
		result = operator[0](a, b);
	else if (op[0] == '-')
		result = operator[1](a, b);
	else if (op[0] == '*')
		result = operator[2](a, b);
	else if (op[0] == '/')
		result = operator[3](a, b);
	else
		result = operator[4](a, b);
	ft_putnbr(result);
}
