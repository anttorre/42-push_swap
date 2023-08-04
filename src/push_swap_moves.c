/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:04:21 by anttorre          #+#    #+#             */
/*   Updated: 2023/08/04 15:42:32 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *data)
{
	int		size;
	void	*aux;

	size = ft_lstsize(data->stack_a);
	if (size > 1)
	{
		aux = data->stack_a->content;
		data->stack_a->content = data->stack_a->next->content;
		data->stack_a->next->content = aux;
	}
	ft_printf("sa\n");
}

void	sb(t_data *data)
{
	int		size;
	void	*aux;

	size = ft_lstsize(data->stack_b);
	if (size > 1)
	{
		aux = data->stack_b->content;
		data->stack_b->content = data->stack_b->next->content;
		data->stack_b->next->content = aux;
	}
	ft_printf("sb\n");
}

void	ss(t_data *data)
{
	int		size;
	void	*aux;

	size = ft_lstsize(data->stack_a);
	if (size > 1)
	{
		aux = data->stack_a->content;
		data->stack_a->content = data->stack_a->next->content;
		data->stack_a->next->content = aux;
	}
	size = ft_lstsize(data->stack_b);
	if (size > 1)
	{
		aux = data->stack_b->content;
		data->stack_b->content = data->stack_b->next->content;
		data->stack_b->next->content = aux;
	}
	ft_printf("ss\n");
}

void	pb(t_data *data)
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
	ft_lstadd_front(&data->stack_b, aux);
	ft_printf("pb\n");
}


void	pa(t_data *data)
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
	ft_lstadd_front(&data->stack_a, aux);
	ft_printf("pa\n");
}
