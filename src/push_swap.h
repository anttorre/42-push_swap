/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 11:50:06 by anttorre          #+#    #+#             */
/*   Updated: 2023/08/03 16:02:50 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/ft_printf.h"
# include "../libft/get_next_line_bonus.h"
# include "../libft/libft.h"
# define MIN_INT -2147483648
# define MAX_INT 2147483647

typedef struct s_data
{
	char	**arr;
	int		i;
	int		j;
	t_list	*stack_a;
	t_list	*stack_b;
}			t_data;

int			check_args(char **argv, t_data *data, int argc);
int			check_args1(char **argv, t_data *data);
void		ft_free_full_arr(char **arr);
int			init_stack_a(t_data *data);
void		del_content(void *content);

#endif