/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:06:04 by anttorre          #+#    #+#             */
/*   Updated: 2023/08/10 16:56:36 by anttorre         ###   ########.fr       */
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

void	set_target_pos(t_data *data)
{
	int		i;
	t_list	*aux_a;
	t_list	*aux_b;

	aux_b = data->stack_b;
	while (aux_b)
	{
		aux_a = data->stack_a;
		i = 1;
		while (aux_a)
		{
			if (aux_b->index < aux_a->index)
			{
				aux_b->target_pos = i;
				break ;
			}
			i++;
			if (aux_a->next == NULL)
				aux_b->target_pos = i;
			aux_a = aux_a->next;
		}
		aux_b = aux_b->next;
	}
}

void	set_cost_b(t_data *data)
{
	int		middle;
	int		size;
	t_list	*aux;

	aux = data->stack_b;
	size = ft_lstsize(data->stack_b);
	if (size % 2 != 0)
		middle = size / 2 + 1;
	else
		middle = size / 2;
	while (aux)
	{
		if (aux->pos <= middle)
			aux->cost_b = aux->pos - 1;
		else
			aux->cost_b = size - aux->pos + 1;
		aux = aux->next;
	}
}

void	set_cost_a(t_data *data)
{
	int		middle;
	int		size;
	t_list	*aux;

	aux = data->stack_b;
	size = ft_lstsize(data->stack_a);
	if (size % 2 != 0)
		middle = size / 2 + 1;
	else
		middle = size / 2;
	while (aux)
	{
		if (aux->target_pos <= middle)
			aux->cost_a = aux->target_pos - 1;
		else
			aux->cost_a = size - aux->target_pos + 1;
		aux = aux->next;
	}
}