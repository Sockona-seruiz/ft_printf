/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruiz <seruiz@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 10:27:41 by seruiz            #+#    #+#             */
/*   Updated: 2020/03/06 10:26:59 by seruiz           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_list
{
	char		flag;
	int			width;
	int			prec;
	char		spec;
	int			res;
	int			isneg;
}				t_list;
typedef struct	s_listint
{
	int			i;
	int			btn;
}				t_listint;
int				ft_printf(const char *str,
				...) __attribute__((format(printf,1,2)));
size_t			ft_strlen(char *str);
int				ft_launch_char(va_list *arg_list, t_list *p_struct);
int				ft_atoi(const char *str);
int				ft_fill_prec(t_list *p_struct, const char *s,
				va_list *arg_list, t_listint *lst);
int				ft_fill_p_struct(t_list *p_struct, const char *str,
				va_list *arg_list);
int				ft_print_int(char *str, t_list *p_struct, int i);
int				ft_print_str(char *str, t_list *p_struct, int len);
int				ft_itoa(long int n, t_list *p_struct);
char			*calcul_base(unsigned long int number, char *base,
				int len, int count);
int				ft_launch_fct_int(char *number, t_list *p_struct, int len);
int				ft_print_base(long number, char *base, t_list *p_struct);
int				ft_print_base_p(unsigned long int number, char *base,
				t_list *p_struct);
#endif
