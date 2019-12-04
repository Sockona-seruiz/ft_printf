/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: seruiz <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/03 15:38:16 by seruiz       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/04 17:48:12 by seruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef INDEX_SIZE
# define INDEX_SIZE 10
#endif

typedef struct	s_list
{
	char 		flag;
	int			width;
	int			prec;
	char		spec;
}				t_list;
int				ft_printf(const char *str, ...);
int				ft_print_str(char *str, t_list *t_struct);
int				ft_itoa(long int n, t_list *t_struct);
