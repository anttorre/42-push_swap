/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:06:04 by anttorre          #+#    #+#             */
/*   Updated: 2023/08/10 15:11:24 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_pos(t_data *data)
{
	int		i;
	t_list	*aux;

	aux = data->stack_a;
	i = 0;
	aux = data->stack_a;
	while (aux)
	{
		aux->pos = ++i;
		aux = aux->next;
	}
	i = 0;
	aux = data->stack_b;
	while (aux)
	{
		aux->pos = ++i;
		aux = aux->next;
	}
}
