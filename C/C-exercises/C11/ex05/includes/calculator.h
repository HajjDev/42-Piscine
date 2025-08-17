/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:52:58 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/12 15:03:47 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALCULATOR_H
# define CALCULATOR_H

# include <unistd.h>

int		ft_is_valid_operator(char *operator);
int		ft_check_forbidden(int num, char *op);
void	ft_handle_operations(char *a, char *b, char *c);
void	operate(int a, char *op, int b);
int		ft_add(int a, int b);
int		ft_substract(int a, int b);
int		ft_mul(int a, int b);
int		ft_div(int a, int b);
int		ft_modulo(int a, int b);
char	*ft_reverse(int i, char *reversed_nb, int j, char *nb_to_print);
void	ft_convert(int nb);
void	ft_putnbr(int nb);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_atoi(char *str);

#endif