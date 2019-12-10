/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: seruiz <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 17:14:09 by seruiz       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/10 19:06:20 by seruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_intlen(long int n)
{
	int i;

	if (n == 0)
		return (1);
	i = 0;
	if (n < 0)
	{
		i++;
		n = n * -1;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int		ft_print_space_int(t_list *t_struct, int len, char *result)
{
	int		i;
	int		width;
	char	c;

	c = ' ';
	width = t_struct->width;
	if (t_struct->prec == 0 && t_struct->flag == '0')
		c = '0';
	i = 0;
	if (result[0] == '-' && len == t_struct->prec)
		width--;
	while (width > t_struct->prec && width > len)
	{
		i++;
		write(1, &c, 1);
		width--;
	}
	return (i);
}

int		ft_print_space_int_back(t_list *t_struct, int printedlen)
{
	int i;
	int width;

	i = 0;
	width = t_struct->width - printedlen;
	while (width > 0)
	{
		write(1, " ", 1);
		width--;
		i++;
	}
	return (i);
}

int		ft_launch_fct_int(t_list *t_struct, int len, char *result)
{
	int i;

	i = 0;
	if (t_struct->flag != '-')
		i = ft_print_space_int(t_struct, len, result);
	i = i + ft_print_int(result, t_struct);
	if (t_struct->flag == '-')
		i = i + ft_print_space_int_back(t_struct, i);
	free(result);
	return (i);
}

int		ft_itoa(long int n, t_list *t_struct)
{
	char *result;
	int len;

	len = ft_intlen(n);
	if ((result = malloc(sizeof(char) * (len + 1))) == 0)
		return (0);
	result[len] = '\0';
	if (n < 0)
	{
		result[0] = '-';
		n = n * -1;
	}
	while (n > 0)
	{
		result[len - 1] = (n % 10) + 48;
		n = n / 10;
		len--;
	}
	return (ft_launch_fct_int(t_struct, ft_strlen(result), result));
}
