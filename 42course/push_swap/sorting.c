/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:17:38 by youngski          #+#    #+#             */
/*   Updated: 2022/12/24 21:06:42 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	*node_to_arr(t_list *root)
{
	t_list	*temp;
	int		*ret;
	int		i;
	int		count;

	i = 0;
	count = 0;
	temp = root;
	while (temp->next)
	{
		temp = temp->next;
		count++;
	}
	ret = (int *)malloc(sizeof(int) * count);
	while (root)
	{
		ret[i] = root->data;
		root = root->next;
	}
	return (ret);
}

int	*bubble_sort(int *arr, int size)
{
	int	i;
	int	temp;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 2)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (arr);
}

int	*make_arr(t_list *root)
{
	t_list	*temp;
	int		count;
	int		*ret;

	temp = root;
	count = 0;
	while (temp)
	{
		temp = temp->next;
		count++;
	}
	ret = (int *)malloc(sizeof(int) * count + 2);
	count = 0;
	while (root)
	{
		ret[count] = root->data;
		root = root->next;
		count++;
	}
	ret[count] = 0;
	ret[count + 1] = 0;
	return (ret);
}

void	make_list_index(t_list *root, int *sorted, int size)
{
	int		i;
	t_list	*temp;

	temp = root;
	while (root)
	{
		i = 0;
		while (i < size)
		{
			if (root->data == sorted[i])
			{
				root->data = i;
				break ;
			}
			i++;
		}
		root = root->next;
	}
	root = temp;
}
