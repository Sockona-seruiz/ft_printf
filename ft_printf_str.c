/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_str.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: seruiz <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/10 15:19:19 by seruiz       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/20 13:36:43 by seruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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
		t_struct->res += write(1, &c, 1);
		i++;
	}
	return (i);
}

int		ft_print_str(char *str, t_list *t_struct)
{
	int	len;
	int result;

	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	if (t_struct->prec == 0)
		t_struct->prec = len;
	else if (t_struct->prec == -1 && t_struct->width != 0 && t_struct->spec == 's')
	{
		while (t_struct->width > 0)
		{
			t_struct->width--;
			t_struct->res += write(1, " ", 1);
		}
		return (1);
	}
	if (t_struct->flag != '-')
		result = ft_flag_str(t_struct, len);
	if (t_struct->prec != 0 && t_struct->prec < len)
	{
		t_struct->res += write(1, str, t_struct->prec);
		if (t_struct->flag == '-')
			result = ft_flag_str(t_struct, len);
		return (t_struct->prec + result);
	}
	t_struct->res += write(1, str, len);
	if (t_struct->flag == '-')
		result = ft_flag_str(t_struct, len);
	return (1);
}

int		ft_launch_perc(t_list *t_struct)
{
	char *str;

	if ((str = malloc(sizeof(char) * 2)) == 0)
		return (-1);
	str[1] = '\0';
	str[0] = '%';
	ft_print_str(str, t_struct);
	free(str);
	return (1);
}

int		ft_launch_char(va_list *arg_list, t_list *t_struct)
{
	char *str;

	if ((str = malloc(sizeof(char) * 2)) == 0)
		return (-1);
	str[1] = '\0';
	if ((str[0] = (char)va_arg(*arg_list, int)) == 0)
	{
		t_struct->res++;
		t_struct->width--;
	}
	ft_print_str(str, t_struct);
	free(str);
	return (1);
}
