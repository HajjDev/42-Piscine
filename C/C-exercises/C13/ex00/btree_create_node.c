/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 14:29:34 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/17 12:50:06 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree	*btree_create_node(void *item)
{
	t_btree	*root;

	root = malloc(sizeof(t_btree));
	if (root == NULL)
		return (NULL);
	root->item = item;
	root->left = 0;
	root->right = 0;
	return (root);
}

/* ************************************************************************** */
/*                                                                            */
/* ************************************************************************** */

/*
Node created in this example:
	4
   / \
  0   0
*/

/*
#include <stdio.h>

int	main(void)
{
	int	n = 3;
	void	*item = &n;
	t_btree	*node = btree_create_node(item);

	printf("%d\n", *(int *)node->item);
	printf("%p\n", node->left);
	printf("%p\n", node->right);
	return (0);
}
*/