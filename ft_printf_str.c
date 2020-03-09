/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruiz <seruiz@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 10:27:54 by seruiz            #+#    #+#             */
/*   Updated: 2020/03/06 10:26:59 by seruiz           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_flag_str(t_list *p_struct, int len)
{
	int		i;
	int		j;
	char	c;
	char	*str;

	i = 0;
	j = 0;
	c = ' ';
	if (p_struct->flag == '0')
		c = '0';
	if (p_struct->prec != 0 && p_struct->prec < len)
		len = p_struct->prec;
	if ((i = p_struct->width - len) < 0)
		i = 0;
	if ((str = malloc(sizeof(char) * (i + 1))) == NULL)
		return (-1);
	str[i] = '\0';
	while (j < i)
	{
		str[j] = c;
		j++;
	}
	p_struct->res += write(1, str, i);
	free(str);
	return (1);
}

int		ft_neg_prec(t_list *p_struct)
{
	char	*str;
	int		i;

	i = 0;
	if (p_struct->spec == '%')
		p_struct->width--;
	if (p_struct->spec == '%' && p_struct->flag == '-')
		p_struct->res += write(1, "%", 1);
	if (p_struct->width > 0)
	{
		if ((str = malloc(sizeof(char) * (p_struct->width + 1))) == NULL)
			return (-1);
		str[p_struct->width] = '\0';
		while (i < p_struct->width)
		{
			str[i] = ' ';
			i++;
		}
		p_struct->res += write(1, str, i);
		free(str);
		p_struct->width = 0;
	}
	if (p_struct->spec == '%' && p_struct->flag != '-')
		p_struct->res += write(1, "%", 1);
	return (1);
}

int		ft_print_str(char *str, t_list *p_struct, int len)
{
	int result;

	if (p_struct->prec == -3 && p_struct->spec == 's' && p_struct->width == 0)
		return (1);
	else if (p_struct->prec == -3 && p_struct->spec == 's')
		p_struct->prec = -1;
	str = (str == NULL && p_struct->spec == 's') ? "(null)" : str;
	len = (len == -1) ? ft_strlen(str) : len;
	if (p_struct->prec == 0 || p_struct->prec == -2)
		p_struct->prec = len;
	else if (p_struct->prec == -1)
		return (ft_neg_prec(p_struct));
	if (p_struct->flag != '-')
		if ((result = ft_flag_str(p_struct, len)) == -1)
			return (-1);
	if (p_struct->prec > 0 && p_struct->prec < len)
	{
		p_struct->res += write(1, str, p_struct->prec);
		if (p_struct->flag == '-')
			result = ft_flag_str(p_struct, len);
		return (result);
	}
	p_struct->res += write(1, str, len);
	return (p_struct->flag == '-' ? ft_flag_str(p_struct, len) : 1);
}

int		ft_launch_char(va_list *arg_list, t_list *p_struct)
{
	char *str;

	if ((str = malloc(sizeof(char) * 2)) == 0)
		return (-1);
	str[1] = '\0';
	if (p_struct->spec == 'c')
		str[0] = (char)va_arg(*arg_list, int);
	else
		str[0] = '%';
	if (p_struct->prec == -1)
	{
		p_struct->res += write(1, str, 1);
		return (1);
	}
	ft_print_str(str, p_struct, 1);
	free(str);
	return (1);
}
