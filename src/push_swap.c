/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 11:47:15 by anttorre          #+#    #+#             */
/*   Updated: 2023/08/08 15:20:17 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

void	imprimir_lista_enlazada(t_data *data)
{
	t_list	*nodo_a;
	t_list	*nodo_b;

	nodo_a = data->stack_a;
	nodo_b = data->stack_b;
	int i = 0;
	while (nodo_a != NULL || nodo_b != NULL)
	{
		++i;
		if (nodo_b == NULL)
			ft_printf("NODO: %d\nValue:      %d             \nIndex:      %d             \nPos:        %d             \nTarget_pos: %d             \nCost_a:     %d             \nCost_b:     %d             \n               \n", i, nodo_a->value, nodo_a->index, nodo_a->pos, nodo_a->target_pos, nodo_a->cost_a, nodo_a->cost_b);
		else if (nodo_a == NULL)
			ft_printf("NODO: %d\nValue:                   %d\nIndex:                   %d\nPos:                     %d\nTarget_pos:              %d\nCost_a:                  %d\nCost_b:                  %d\n               \n",i, nodo_b->value, nodo_b->index, nodo_b->pos, nodo_b->target_pos, nodo_b->cost_a, nodo_b->cost_b);
		else
			ft_printf("NODO: %d\nValue:      %d            %d\nIndex:      %d            %d\nPos:        %d            %d\nTarget_pos: %d            %d\nCost_a:     %d            %d\nCost_b:     %d            %d\n               \n",i ,nodo_a->value, nodo_b->value, nodo_a->index, nodo_b->index, nodo_a->pos, nodo_b->pos, nodo_a->target_pos, nodo_b->target_pos, nodo_a->cost_a, nodo_b->cost_a, nodo_a->cost_b, nodo_b->cost_b);
		if (nodo_a != NULL)
			nodo_a = nodo_a->next;
		if (nodo_b != NULL)
			nodo_b = nodo_b->next;
	}
	ft_printf("            -            -\n");
	ft_printf("            a            b\n\n");
}

void	ft_leaks(void)
{
	system("leaks -q push_swap");
}

void	initialize_data(t_data *data)
{
	data->arr = NULL;
	data->i = 0;
	data->j = 0;
	data->lst_size = 0;
	data->stack_a = NULL;
	data->stack_b = NULL;
}

int	main1(t_data *data)
{
	if (init_stack_a(data) == EXIT_FAILURE)
		return (ft_free_full_arr(data->arr),
			ft_lstclear(&data->stack_a, &del_content)
			, ft_printf("Error\n"), EXIT_FAILURE);
	data->lst_size = ft_lstsize(data->stack_a);
	put_index(data);
	/* if (check_order(data) == EXIT_FAILURE)
	{
		if (data->lst_size == 2)
			sa(data);
		else if (data->lst_size == 3)
			sort_3(data);
		else
			sort_all(data);
	} */
	//ra(data, 1);
	pb(data);
	pb(data);
	pb(data);
	pa(data);
	imprimir_lista_enlazada(data);
	return (EXIT_SUCCESS);
}

int	main(int argc, char *argv[])
{
	t_data	*data;

	//atexit(ft_leaks);
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (EXIT_FAILURE);
	initialize_data(data);
	if (argc > 2)
	{
		if (check_args(argv, data, argc) == EXIT_FAILURE)
			return (free(data), EXIT_FAILURE);
	}
	else if (argc == 2)
	{
		if (check_args1(argv, data) == EXIT_FAILURE)
			return (free(data), EXIT_FAILURE);
	}
	else
		return (free(data), EXIT_FAILURE);
	if (main1(data) == EXIT_FAILURE)
		return (free(data), EXIT_FAILURE);
	return (ft_free_full_arr(data->arr),
		ft_lstclear(&data->stack_a, &del_content),
		ft_lstclear(&data->stack_b, &del_content), free(data), EXIT_SUCCESS);
}
