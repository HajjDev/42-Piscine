/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 22:48:09 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/06 22:59:08 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	if (n > 0)
	{
		i = 0;
		while (s1[i] && s2[i] && i < n)
		{
			if (s1[i] != s2[i])
			{
				return ((int)s1[i] - (int)s2[i]);
			}
			i++;
		}
		if (i < n)
		{
			return ((int)s1[i] - (int)s2[i]);
		}
		return (0);
	}
	return (0);
}
