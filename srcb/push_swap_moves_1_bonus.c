/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves_1_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:54:59 by anttorre          #+#    #+#             */
/*   Updated: 2023/08/16 18:30:14 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ra(t_data *data, int flag)
{
	t_list	*aux;
	t_list	*last;

	aux = data->stack_a;
	last = ft_lstlast(data->stack_a);
	data->stack_a = aux->next;
	aux->next = NULL;
	last->next = aux;
	if (flag == 1)
		ft_printf("ra\n");
}

void	rb(t_data *data, int flag)
{
	t_list	*aux;
	t_list	*last;

	if (ft_lstsize(data->stack_b) < 2)
		return ;
	aux = data->stack_b;
	last = ft_lstlast(data->stack_b);
	data->stack_b = aux->next;
	aux->next = NULL;
	last->next = aux;
	if (flag == 1)
		ft_printf("rb\n");
}

void	rr(t_data *data, int flag)
{
	if ((ft_lstsize(data->stack_a) < 2) || (ft_lstsize(data->stack_b) < 2))
		return ;
	ra(data, 0);
	rb(data, 0);
	if (flag == 1)
		ft_printf("rr\n");
}

void	rra(t_data *data, int flag)
{
	t_list	*aux;
	t_list	*last;

	aux = data->stack_a;
	last = ft_lstlast(data->stack_a);
	while (aux)
	{
		if (aux->next->next == NULL)
		{
			aux->next = NULL;
			break ;
		}
		aux = aux->next;
	}
	last->next = data->stack_a;
	data->stack_a = last;
	if (flag == 1)
		ft_printf("rra\n");
}

void	rrb(t_data *data, int flag)
{
	t_list	*aux;
	t_list	*last;

	if (ft_lstsize(data->stack_b) < 2)
		return ;
	aux = data->stack_b;
	last = ft_lstlast(data->stack_b);
	while (aux)
	{
		if (aux->next->next == NULL)
		{
			aux->next = NULL;
			break ;
		}
		aux = aux->next;
	}
	last->next = data->stack_b;
	data->stack_b = last;
	if (flag == 1)
		ft_printf("rrb\n");
}
