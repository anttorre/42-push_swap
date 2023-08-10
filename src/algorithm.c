/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:39:19 by anttorre          #+#    #+#             */
/*   Updated: 2023/08/08 15:12:38 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_index(t_data *data)
{
	long long	min;
	t_list		*aux;
	t_list		*node_min;
	int			index;

	min = (long long)MAX_INT + 1;
	node_min = data->stack_a;
	index = 1;
	aux = data->stack_a;
	while (data->lst_size >= index)
	{
		while (aux)
		{
			if (aux->value < min && aux->index == 0)
			{
				min = aux->value;
				node_min = aux;
			}
			aux = aux->next;
		}
		min = (long long)MAX_INT + 1;
		node_min->index = index;
		aux = data->stack_a;
		index++;
	}
}

int	check_order(t_data *data)
{
	int		i;
	t_list	*aux;

	i = 1;
	aux = data->stack_a;
	while (data->lst_size >= i)
	{
		if (i != aux->index)
			return (EXIT_FAILURE);
		aux = aux->next;
		i++;
	}
	return (EXIT_SUCCESS);
}

void	sort_3(t_data *data)
{
	t_list	*lst;

	lst = data->stack_a;
	if (lst->index == 3)
	{
		ra(data, 1);
		lst = data->stack_a;
		if (lst->next->index == 1)
			sa(data);
	}
	else if (lst->next->index == 3)
	{
		rra(data, 1);
		lst = data->stack_a;
		if (lst->next->index == 1)
			sa(data);
	}
	else
		sa(data);
}

void	sort_all(t_data *data)
{
	t_list	*aux;

	aux = data->stack_a;
	while (aux && ft_lstsize(data->stack_a) > 3)
		pb(data);
}
