/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:06:04 by anttorre          #+#    #+#             */
/*   Updated: 2023/08/11 16:44:29 by anttorre         ###   ########.fr       */
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
	int		aux_index;
	t_list	*aux_a;
	t_list	*aux_b;

	aux_b = data->stack_b;
	while (aux_b)
	{
		aux_a = data->stack_a;
		i = 1;
		aux_index = MAX_INT;
		aux_b->target_pos = MAX_INT;
		while (aux_a)
		{
			if (aux_b->index < aux_a->index && aux_index > aux_a->index)
			{
				aux_index = aux_a->index;
				aux_b->target_pos = i;
			}
			if (i++ && aux_a->next == NULL && aux_b->target_pos == MAX_INT)
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
			aux->cost_b = (size - aux->pos + 1) * -1;
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
			aux->cost_a = (size - aux->target_pos + 1) * -1;
		aux = aux->next;
	}
}

void	cheapest_node(t_data *data)
{
	t_list	*aux_b;
	t_list	*node_cheap;
	int		cost_total;

	aux_b = data->stack_b;
	node_cheap = aux_b;
	while (aux_b)
	{
		cost_total = cost(aux_b);
		if (cost_total < cost(node_cheap))
			node_cheap = aux_b;
		aux_b = aux_b->next;
	}
	ft_printf("\n\n\n%d\n\n\n", node_cheap->index);
}

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
