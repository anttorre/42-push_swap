/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 11:50:06 by anttorre          #+#    #+#             */
/*   Updated: 2023/08/10 15:08:40 by anttorre         ###   ########.fr       */
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
	char		**arr;
	int			i;
	int			j;
	int			lst_size;
	t_list		*stack_a;
	t_list		*stack_b;
}				t_data;

int				check_args(char **argv, t_data *data, int argc);
int				check_args1(char **argv, t_data *data);
void			ft_free_full_arr(char **arr);
long long int	ft_atol(const char *str);
int				init_stack_a(t_data *data);
void			del_content(int content);
void			sa(t_data *data, int flag);
void			sb(t_data *data, int flag);
void			ss(t_data *data);
void			pb(t_data *data);
void			pa(t_data *data);
void			ra(t_data *data, int flag);
void			rb(t_data *data, int flag);
void			rr(t_data *data);
void			rra(t_data *data, int flag);
void			rrb(t_data *data, int flag);
void			rrr(t_data *data);
void			put_index(t_data *data);
int				check_order(t_data *data);
void			sort_all(t_data *data);
void			sort_3(t_data *data);
void			set_pos(t_data *data);

#endif