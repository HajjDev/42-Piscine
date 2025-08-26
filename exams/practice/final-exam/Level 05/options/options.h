/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 21:49:58 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/26 21:59:33 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTIONS_H
# define OPTIONS_H

#include <unistd.h>

int     ft_find(char *str, char c);
void	ft_add(char *options, char bits[]);
int     error(void);
void    ft_putstr(char str[]);
int     ft_valid(char *option);
void	ft_split_print(char bits[]);

#endif