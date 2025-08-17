/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 10:59:43 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/08/17 12:51:27 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item, int
(*cmpf)(void *, void *))
{
	if ((*root) == 0)
	{
		(*root) = btree_create_node(item);
		return ;
	}
	if ((*cmpf)(item, (*root)->item) >= 0)
		btree_insert_data(&(*root)->right, item, cmpf);
	else
		btree_insert_data(&(*root)->left, item, cmpf);
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/* ************************************************************************** */

/*
Here are the trees used in these examples:
Trees have to respect the rules of a bst.

Tree 1:
       21
      /  \
    13    34
   / \    / \
  8  19  27  40

Tree 2:
        5
         \
          8
           \
            10
*/

/*
#include <stdio.h>

void	print_node(void *data)
{
	printf("%d ", *(int *)data);
}


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

void btree_free(t_btree *root)
{
	if (!root)
		return;
	btree_free(root->left);
	btree_free(root->right);
	free(root->item);
	free(root);
}

int *make_int(int value)
{
	int *ptr = malloc(sizeof(int));
	if (!ptr)
		return NULL;
	*ptr = value;
	return ptr;
}

int	cmp(void *data1, void *data2)
{
	return (*(int *)data1 - *(int *)data2);
}

void	btree_apply_infix(t_btree *root, void (*applyf)(void *))
{
	if (root == 0)
		return ;
	btree_apply_infix(root->left, applyf);
	(*applyf)(root->item);
	btree_apply_infix(root->right, applyf);
	return ;
}

t_btree *create_tree1(void)
{
	t_btree *n21 = btree_create_node(make_int(21));
	t_btree *n13 = btree_create_node(make_int(13));
	t_btree *n34 = btree_create_node(make_int(34));
	t_btree *n8 = btree_create_node(make_int(8));
	t_btree *n19 = btree_create_node(make_int(19));
	t_btree *n27 = btree_create_node(make_int(27));
	t_btree *n40 = btree_create_node(make_int(40));

	n21->left = n13;
	n21->right = n34;
	n13->left = n8;
	n13->right = n19;
	n34->left = n27;
	n34->right = n40;

	return (n21);
}


t_btree *create_tree2(void)
{
	t_btree *n5 = btree_create_node(make_int(5));
	t_btree *n8a = btree_create_node(make_int(8));
	t_btree *n10 = btree_create_node(make_int(10));

	n5->right = n8a;
	n8a->right = n10;

	return (n5);
}

int	main(void)
{
	t_btree	*tree1 = create_tree1();
	t_btree	*tree2 = create_tree2();

	printf("Inorder Traversal of Tree 1 before inserting element:\n");
	btree_apply_infix(tree1, &print_node);
	printf("\n");
	btree_insert_data(&tree1, make_int(25), &cmp);
	printf("Inorder Traversal of Tree 1 after inserting element \
	with value 25:\n");
	btree_apply_infix(tree1, &print_node);
	printf("\n");
	btree_insert_data(&tree1, make_int(42), &cmp);
	printf("Inorder Traversal of Tree 1 after inserting element \
	with value 42:\n");
	btree_apply_infix(tree1, &print_node);
	printf("\n");
	btree_insert_data(&tree1, make_int(21), &cmp);
	printf("Inorder Traversal of Tree 1 after inserting element \
	with value 21:\n");
	btree_apply_infix(tree1, &print_node);
	printf("\n");

	printf("\n");
	printf("Inorder Traversal of Tree 2 before inserting element:\n");
	btree_apply_infix(tree2, &print_node);
	printf("\n");
	btree_insert_data(&tree2, make_int(4), &cmp);
	printf("Inorder Traversal of Tree 2 after inserting element \
	with value 4:\n");
	btree_apply_infix(tree2, &print_node);
	printf("\n");
	btree_insert_data(&tree2, make_int(13), &cmp);
	printf("Inorder Traversal of Tree 2 after inserting element \
	with value 13:\n");
	btree_apply_infix(tree2, &print_node);
	printf("\n");
	btree_insert_data(&tree2, make_int(6), &cmp);
	printf("Inorder Traversal of Tree 2 after inserting element \
	with value 6:\n");
	btree_apply_infix(tree2, &print_node);
	printf("\n");

	btree_free(tree1);
	btree_free(tree2);
	return (0);
}
*/