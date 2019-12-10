/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_str.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: seruiz <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/10 15:19:19 by seruiz       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/10 16:14:58 by seruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_flag_str(t_list *t_struct, int len)
{
	int		i;
	char	c;

	i = 0;
	c = ' ';
	if (t_struct->flag == '0')
		c = '0';
	if (t_struct->prec != 0 && t_struct->prec < len)
		len = t_struct->prec;
	while (i < (t_struct->width - len))
	{
		write(1, &c, 1);
		i++;
	}
	return (i);
}

int		ft_print_str(char *str, t_list *t_struct)
{
	int	len;
	int result;

	len = ft_strlen(str);
	if (t_struct->flag != '-')
		result = ft_flag_str(t_struct, len);
	if (t_struct->prec != 0 && t_struct->prec < len)
	{
		write(1, str, t_struct->prec);
		if (t_struct->flag == '-')
			result = ft_flag_str(t_struct, len);
		return (t_struct->prec + result);
	}
	write(1, str, len);
	if (t_struct->flag == '-')
		result = ft_flag_str(t_struct, len);
	return (len + result);
}
