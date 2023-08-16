/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves_2_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 17:02:44 by anttorre          #+#    #+#             */
/*   Updated: 2023/08/16 18:30:17 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rrr(t_data *data, int flag)
{
	if ((ft_lstsize(data->stack_a) < 2) || (ft_lstsize(data->stack_b) < 2))
		return ;
	rra(data, 0);
	rrb(data, 0);
	if (flag == 1)
		ft_printf("rrr\n");
}
