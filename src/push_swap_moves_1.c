/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:54:59 by anttorre          #+#    #+#             */
/*   Updated: 2023/08/08 15:07:20 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_data *data, int flag)
{
	int		value;
	t_list	*aux;
	int		index;
	int		pos;
	int		target_p;

	value = data->stack_a->value;
	index = data->stack_a->index;
	pos = data->stack_a->pos;
	target_p = data->stack_a->target_pos;
	aux = data->stack_a->next;
	ft_lstdelone(data->stack_a, &del_content);
	data->stack_a = aux;
	aux = ft_lstnew(value, index, pos, target_p);
	if (!aux)
		return ;
	ft_lstadd_back(&data->stack_a, aux);
	if (flag == 1)
		ft_printf("ra\n");
}

void	rb(t_data *data, int flag)
{
	int		value;
	t_list	*aux;
	int		index;
	int		pos;
	int		target_p;

	value = data->stack_b->value;
	index = data->stack_b->index;
	pos = data->stack_b->pos;
	target_p = data->stack_b->target_pos;
	aux = data->stack_b->next;
	ft_lstdelone(data->stack_b, &del_content);
	data->stack_b = aux;
	aux = ft_lstnew(value, index, pos, target_p);
	if (!aux)
		return ;
	ft_lstadd_back(&data->stack_b, aux);
	if (flag == 1)
		ft_printf("rb\n");
}

void	rr(t_data *data)
{
	ra(data, 0);
	rb(data, 0);
	ft_printf("rr\n");
}

void	rra(t_data *data, int flag)
{
	int		value;
	t_list	*aux;
	int		index;
	int		pos;
	int		target_p;

	value = data->stack_a->value;
	index = data->stack_a->index;
	pos = data->stack_a->pos;
	target_p = data->stack_a->target_pos;
	value = ft_lstlast(data->stack_a)->value;
	ft_lstdelone(ft_lstlast(data->stack_a), &del_content);
	aux = data->stack_a;
	while (aux->next->next)
		aux = aux->next;
	aux->next = NULL;
	aux = ft_lstnew(value, index, pos, target_p);
	if (!aux)
		return ;
	ft_lstadd_front(&data->stack_a, aux);
	if (flag == 1)
		ft_printf("rra\n");
}

void	rrb(t_data *data, int flag)
{
	int		value;
	t_list	*aux;
	int		index;
	int		pos;
	int		target_p;

	value = data->stack_b->value;
	index = data->stack_b->index;
	pos = data->stack_b->pos;
	target_p = data->stack_b->target_pos;
	value = ft_lstlast(data->stack_b)->value;
	ft_lstdelone(ft_lstlast(data->stack_b), &del_content);
	aux = data->stack_b;
	while (aux->next->next)
		aux = aux->next;
	aux->next = NULL;
	aux = ft_lstnew(value, index, pos, target_p);
	if (!aux)
		return ;
	ft_lstadd_front(&data->stack_b, aux);
	if (flag == 1)
		ft_printf("rrb\n");
}
