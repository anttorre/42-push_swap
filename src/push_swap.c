/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 11:47:15 by anttorre          #+#    #+#             */
/*   Updated: 2023/08/04 17:05:36 by anttorre         ###   ########.fr       */
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
	while (nodo_a != NULL || nodo_b != NULL)
	{
		if (nodo_b == NULL)
			ft_printf("%d               \n", nodo_a->content);
		else if (nodo_a == NULL)
			ft_printf("               %d\n", nodo_b->content);
		else
			ft_printf("%d              %d\n", nodo_a->content, nodo_b->content);
		nodo_a = nodo_a->next;
		if (nodo_b != NULL)
			nodo_b = nodo_b->next;
	}
	ft_printf("-              -\n");
	ft_printf("a              b\n\n");
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
	data->stack_a = NULL;
	data->stack_b = NULL;
}

int	main1(t_data *data)
{
	if (init_stack_a(data) == EXIT_FAILURE)
		return (ft_free_full_arr(data->arr),
			ft_lstclear(&data->stack_a, &del_content)
			, ft_printf("Error\n"), EXIT_FAILURE);
	imprimir_lista_enlazada(data);
	pb(data);
	pb(data);
	pb(data);
	ss(data);
	imprimir_lista_enlazada(data);
	//pa(data);
	rrr(data);
	rrr(data);
	imprimir_lista_enlazada(data);
	return (EXIT_SUCCESS);
}

int	main(int argc, char *argv[])
{
	t_data	*data;

	atexit(ft_leaks);
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
