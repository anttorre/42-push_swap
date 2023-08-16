/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 17:02:44 by anttorre          #+#    #+#             */
/*   Updated: 2023/08/14 16:02:40 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	rrr(t_data *data)
{
	if ((ft_lstsize(data->stack_a) < 2) || (ft_lstsize(data->stack_b) < 2))
		return ;
	rra(data, 0);
	rrb(data, 0);
	ft_printf("rrr\n");
}
