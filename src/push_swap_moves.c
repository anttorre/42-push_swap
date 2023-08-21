/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:04:21 by anttorre          #+#    #+#             */
/*   Updated: 2023/08/21 15:20:25 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *data, int flag)
{
	int		size;
	t_list	*first;
	t_list	*second;

	size = ft_lstsize(data->stack_a);
	if (size > 1)
	{
		first = data->stack_a;
		second = data->stack_a->next;
		first->next = second->next;
		second->next = first;
		data->stack_a = second;
	}
	if (flag == 1)
		ft_printf("sa\n");
}

void	sb(t_data *data, int flag)
{
	int		size;
	t_list	*first;
	t_list	*second;

	size = ft_lstsize(data->stack_b);
	if (size > 1)
	{
		first = data->stack_b;
		second = data->stack_b->next;
		first->next = second->next;
		second->next = first;
		data->stack_b = second;
	}
	if (flag == 1)
		ft_printf("sb\n");
}

void	ss(t_data *data, int flag)
{
	sa(data, 0);
	sa(data, 0);
	if (flag == 1)
		ft_printf("ss\n");
}

void	pb(t_data *data, int flag)
{
	int		value;
	t_list	*aux;
	int		index;

	if (ft_lstsize(data->stack_a) == 0)
		return ;
	value = data->stack_a->value;
	index = data->stack_a->index;
	aux = data->stack_a->next;
	ft_lstdelone(data->stack_a, &del_content);
	data->stack_a = aux;
	aux = ft_lstnew(value, index, 0, 0);
	if (!aux)
		return ;
	ft_lstadd_front(&data->stack_b, aux);
	if (flag == 1)
		ft_printf("pb\n");
}

void	pa(t_data *data, int flag)
{
	int		value;
	t_list	*aux;
	int		index;
	int		target_p;

	if (ft_lstsize(data->stack_b) == 0)
		return ;
	value = data->stack_b->value;
	index = data->stack_b->index;
	target_p = data->stack_b->target_pos;
	aux = data->stack_b->next;
	ft_lstdelone(data->stack_b, &del_content);
	data->stack_b = aux;
	aux = ft_lstnew(value, index, 0, target_p);
	if (!aux)
		return ;
	ft_lstadd_front(&data->stack_a, aux);
	if (flag == 1)
		ft_printf("pa\n");
}
