/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:04:21 by anttorre          #+#    #+#             */
/*   Updated: 2023/08/08 14:43:13 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *data)
{
	int	size;
	int	aux;

	size = ft_lstsize(data->stack_a);
	if (size > 1)
	{
		aux = data->stack_a->value;
		data->stack_a->value = data->stack_a->next->value;
		data->stack_a->next->value = aux;
	}
	ft_printf("sa\n");
}

void	sb(t_data *data)
{
	int	size;
	int	aux;

	size = ft_lstsize(data->stack_b);
	if (size > 1)
	{
		aux = data->stack_b->value;
		data->stack_b->value = data->stack_b->next->value;
		data->stack_b->next->value = aux;
	}
	ft_printf("sb\n");
}

void	ss(t_data *data)
{
	int	size;
	int	aux;

	size = ft_lstsize(data->stack_a);
	if (size > 1)
	{
		aux = data->stack_a->value;
		data->stack_a->value = data->stack_a->next->value;
		data->stack_a->next->value = aux;
	}
	size = ft_lstsize(data->stack_b);
	if (size > 1)
	{
		aux = data->stack_b->value;
		data->stack_b->value = data->stack_b->next->value;
		data->stack_b->next->value = aux;
	}
	ft_printf("ss\n");
}

void	pb(t_data *data)
{
	int		value;
	t_list	*aux;
	int		index;

	value = data->stack_a->value;
	index = data->stack_a->index;
	aux = data->stack_a->next;
	ft_lstdelone(data->stack_a, &del_content);
	data->stack_a = aux;
	aux = ft_lstnew(value, index, 0, 0);
	if (!aux)
		return ;
	ft_lstadd_front(&data->stack_b, aux);
	ft_printf("pb\n");
}

void	pa(t_data *data)
{
	int		value;
	t_list	*aux;
	int		index;
	int		target_p;

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
	ft_printf("pa\n");
}
