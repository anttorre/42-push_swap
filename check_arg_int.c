/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:37:09 by anttorre          #+#    #+#             */
/*   Updated: 2023/07/24 17:04:54 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_args(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i] != NULL)
	{
		j = -1;
		while (argv[i][++j] != '\0')
		{
			if (j == 0 && argv[i][j] == '-')
				j++;
			if (!ft_isdigit(argv[i][j]))
				return (ft_printf("Error\n"), EXIT_FAILURE);
		}
	}
	ft_printf("todos son digitos");
	return (EXIT_SUCCESS);
}

int	check_args1(char **argv)
{
	char	**arr;
	int		i;
	int		j;

	if (argv[1] != NULL)
	{
		arr = ft_split(argv[1], ' ');
		if (!arr)
			return (EXIT_FAILURE);
		i = -1;
		while (arr[++i] != NULL)
		{
			j = -1;
			while (arr[i][++j] != '\0')
			{
				if (j == 0 && arr[i][j] == '-')
					j++;
				if (!ft_isdigit(arr[i][j]))
					return (ft_printf("Error\n"), EXIT_FAILURE);
			}
		}
	}
	ft_printf("todos son digitos");
	return (EXIT_SUCCESS);
}
