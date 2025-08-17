/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 23:14:32 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/12 23:38:36 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*to_add_elem;

	to_add_elem = (t_list *)malloc(sizeof(t_list));
	if (to_add_elem == NULL)
		return (0);
	to_add_elem->data = data;
	to_add_elem->next = NULL;
	return (to_add_elem);
}

/*
#include <stdio.h>

int	main(void)
{
	int	i = 42;
	t_list *llist;

	llist = ft_create_elem(&i);
	printf("%d\n", *(int *)llist->data);
	printf("%p\n", (void *)llist->next);

	free(llist);
}
*/