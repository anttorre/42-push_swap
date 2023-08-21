/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:13:41 by anttorre          #+#    #+#             */
/*   Updated: 2023/08/21 15:24:03 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_all_3(t_data *data, t_list *cheap_node)
{
	if (cheap_node->cost_a >= 0 && cheap_node->cost_b <= 0)
	{
		while (cheap_node->cost_a-- > 0)
			ra(data, 1);
		while (cheap_node->cost_b < 0)
		{
			rrb(data, 1);
			cheap_node->cost_b++;
		}
	}
	else
	{
		while (cheap_node->cost_a < 0)
		{
			rra(data, 1);
			cheap_node->cost_a++;
		}
		while (cheap_node->cost_b > 0)
		{
			rb(data, 1);
			cheap_node->cost_b--;
		}
	}
}

int	is_sorted(t_list **stack)
{
	t_list	*aux;

	if (stack == NULL)
		return (0);
	aux = *stack;
	while (aux && aux->next)
	{
		if (aux->value > aux->next->value)
			return (0);
		aux = aux->next;
	}
	return (1);
}
