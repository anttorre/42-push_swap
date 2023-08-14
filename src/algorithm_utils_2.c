/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:31:38 by anttorre          #+#    #+#             */
/*   Updated: 2023/08/14 13:16:34 by anttorre         ###   ########.fr       */
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
	while (data->stack_a->index > ft_lstlast(data->stack_a)->index)
		ra(data, 1);
}
