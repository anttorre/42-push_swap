/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:31:38 by anttorre          #+#    #+#             */
/*   Updated: 2023/08/16 11:41:17 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cost(t_list *aux_b)
{
	int	cost_total;

	if (aux_b->cost_a > 0 && aux_b->cost_b > 0)
	{
		if (aux_b->cost_a > aux_b->cost_b)
			cost_total = aux_b->cost_a;
		else
			cost_total = aux_b->cost_b;
	}
	else if (aux_b->cost_a < 0 && aux_b->cost_b < 0)
	{
		if (aux_b->cost_a < aux_b->cost_b)
			cost_total = aux_b->cost_a * -1;
		else
			cost_total = aux_b->cost_b * -1;
	}
	else
		cost_total = abs(aux_b->cost_a) + abs(aux_b->cost_b);
	return (cost_total);
}

int	max_index_stack_a(t_data *data)
{
	t_list	*aux_a;
	t_list	*max_node;

	aux_a = data->stack_a;
	max_node = data->stack_a;
	while (aux_a)
	{
		if (max_node->index < aux_a->index)
			max_node = aux_a;
		aux_a = aux_a->next;
	}
	return (max_node->pos);
}

void	ra_rra(t_data *data)
{
	int		middle;
	t_list	*aux;

	middle = ft_lstsize(data->stack_a) / 2;
	aux = data->stack_a;
	if (data->stack_a->index > middle)
	{
		while (aux->index != 1)
		{
			rra(data, 1);
			aux = data->stack_a;
		}
	}
	else
	{
		while (aux->index != 1)
		{
			ra(data, 1);
			aux = data->stack_a;
		}
	}
}

void	sort_all_1(t_data *data, t_list *cheap_node)
{
	if (cheap_node->cost_a > cheap_node->cost_b)
	{
		while (cheap_node->cost_a++ < 0)
		{
			rrr(data);
			cheap_node->cost_b++;
		}
		while (cheap_node->cost_b++ < 0)
			rrb(data, 1);
	}
	else if (cheap_node->cost_b > cheap_node->cost_a)
	{
		while (cheap_node->cost_b++ < 0)
		{
			rrr(data);
			cheap_node->cost_a++;
		}
		while (cheap_node->cost_a++ < 0)
			rra(data, 1);
	}
	else
	{
		while (cheap_node->cost_a++ && cheap_node->cost_b++)
			rrr(data);
	}
}

void	sort_all_2(t_data *data, t_list *cheap_node)
{
	if (cheap_node->cost_a > cheap_node->cost_b)
	{
		while (cheap_node->cost_b-- > 0)
		{
			rr(data);
			cheap_node->cost_a--;
		}
		while (cheap_node->cost_a-- > 0)
			ra(data, 1);
	}
	else if (cheap_node->cost_b > cheap_node->cost_a)
	{
		while (cheap_node->cost_a-- > 0)
		{
			rr(data);
			cheap_node->cost_b--;
		}
		while (cheap_node->cost_b-- > 0)
			rb(data, 1);
	}
	else
	{
		while (cheap_node->cost_a-- && cheap_node->cost_b--)
			rr(data);
	}
}
