/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils_3_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:13:41 by anttorre          #+#    #+#             */
/*   Updated: 2023/08/16 18:30:05 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
