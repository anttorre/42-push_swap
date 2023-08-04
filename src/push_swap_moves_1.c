/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:54:59 by anttorre          #+#    #+#             */
/*   Updated: 2023/08/04 17:01:29 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_data *data)
{
	void	*content;
	t_list	*aux;

	content = data->stack_a->content;
	aux = data->stack_a->next;
	ft_lstdelone(data->stack_a, &del_content);
	data->stack_a = aux;
	aux = ft_lstnew(content);
	if (!aux)
		return ;
	ft_lstadd_back(&data->stack_a, aux);
	ft_printf("ra\n");
}

void	rb(t_data *data)
{
	void	*content;
	t_list	*aux;

	content = data->stack_b->content;
	aux = data->stack_b->next;
	ft_lstdelone(data->stack_b, &del_content);
	data->stack_b = aux;
	aux = ft_lstnew(content);
	if (!aux)
		return ;
	ft_lstadd_back(&data->stack_b, aux);
	ft_printf("rb\n");
}

void	rr(t_data *data)
{
	void	*content;
	t_list	*aux;

	content = data->stack_a->content;
	aux = data->stack_a->next;
	ft_lstdelone(data->stack_a, &del_content);
	data->stack_a = aux;
	aux = ft_lstnew(content);
	if (!aux)
		return ;
	ft_lstadd_back(&data->stack_a, aux);
	content = data->stack_b->content;
	aux = data->stack_b->next;
	ft_lstdelone(data->stack_b, &del_content);
	data->stack_b = aux;
	aux = ft_lstnew(content);
	if (!aux)
		return ;
	ft_lstadd_back(&data->stack_b, aux);
	ft_printf("rr\n");
}

void	rra(t_data *data)
{
	void	*content;
	t_list	*aux;
	t_list	*new;

	content = ft_lstlast(data->stack_a)->content;
	ft_lstdelone(ft_lstlast(data->stack_a), &del_content);
	aux = data->stack_a;
	while (aux->next->next)
		aux = aux->next;
	aux->next = NULL;
	new = ft_lstnew(content);
	if (!new)
		return ;
	ft_lstadd_front(&data->stack_a, new);
	ft_printf("rra\n");
}

void	rrb(t_data *data)
{
	void	*content;
	t_list	*aux;
	t_list	*new;

	content = ft_lstlast(data->stack_b)->content;
	ft_lstdelone(ft_lstlast(data->stack_b), &del_content);
	aux = data->stack_b;
	while (aux->next->next)
		aux = aux->next;
	aux->next = NULL;
	new = ft_lstnew(content);
	if (!new)
		return ;
	ft_lstadd_front(&data->stack_b, new);
	ft_printf("rrb\n");
}
