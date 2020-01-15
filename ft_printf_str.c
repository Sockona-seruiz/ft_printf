/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_str.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: seruiz <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/10 15:19:19 by seruiz       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/06 13:51:21 by seruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_flag_str(t_list *t_struct, int len)
{
	int		i;
	int		j;
	char	c;
	char	*str;

	i = 0;
	j = 0;
	c = ' ';
	if (t_struct->flag == '0')
		c = '0';
	if (t_struct->prec != 0 && t_struct->prec < len)
		len = t_struct->prec;
	if ((i = t_struct->width - len) < 0)
		i = 0;
	if ((str = malloc(sizeof(char) * (i + 1))) == NULL)
		return (-1);
	str[i] = '\0';
	while (j < i)
	{
		str[j] = c;
		j++;
	}
	t_struct->res += write(1, str, i);
	free(str);
	return (1);
}

int		ft_neg_prec(t_list *t_struct)
{
	char	*str;
	int		i;

	i = 0;
	if (t_struct->spec == '%')
		t_struct->width--;
	if (t_struct->spec == '%' && t_struct->flag == '-')
		t_struct->res += write(1, "%", 1);
	if (t_struct->width > 0)
	{
		if ((str = malloc(sizeof(char) * (t_struct->width + 1))) == NULL)
			return (-1);
		str[t_struct->width] = '\0';
		while (i < t_struct->width)
		{
			str[i] = ' ';
			i++;
		}
		t_struct->res += write(1, str, i);
		free(str);
		t_struct->width = 0;
	}
	if (t_struct->spec == '%' && t_struct->flag != '-')
		t_struct->res += write(1, "%", 1);
	return (1);
}

int		ft_print_str(char *str, t_list *t_struct, int len)
{
	int result;

	str = (str == NULL && t_struct->spec == 's') ? "(null)" : str;
	len = (len == -1) ? ft_strlen(str) : len;
	if (t_struct->prec == 0 || t_struct->prec == -2)
		t_struct->prec = len;
	else if (t_struct->prec == -1)
		return (ft_neg_prec(t_struct));
	if (t_struct->flag != '-')
		if ((result = ft_flag_str(t_struct, len)) == -1)
			return (-1);
	if (t_struct->prec > 0 && t_struct->prec < len)
	{
		t_struct->res += write(1, str, t_struct->prec);
		if (t_struct->flag == '-')
			result = ft_flag_str(t_struct, len);
		return (result);
	}
	t_struct->res += write(1, str, len);
	if (t_struct->flag == '-')
		return (ft_flag_str(t_struct, len));
	return (1);
}

int		ft_launch_char(va_list *arg_list, t_list *t_struct)
{
	char *str;

	if ((str = malloc(sizeof(char) * 2)) == 0)
		return (-1);
	str[1] = '\0';
	if (t_struct->spec == 'c')
		str[0] = (char)va_arg(*arg_list, int);
	else
		str[0] = '%';
	ft_print_str(str, t_struct, 1);
	free(str);
	return (1);
}
