/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruiz <seruiz@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 10:27:23 by seruiz            #+#    #+#             */
/*   Updated: 2020/03/06 10:26:59 by seruiz           ###   ########lyon.fr   */
/*                                                                            */
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

int		ft_launch_fct(char c, va_list *arg_list, t_list *p_struct)
{
	if (c == 's')
		return (ft_print_str(va_arg(*arg_list, char *), p_struct, -1));
	else if (c == 'c' || c == '%')
		return (ft_launch_char(arg_list, p_struct));
	else if (c == 'd' || c == 'i')
		return (ft_print_base(va_arg(*arg_list, int), "0123456789", p_struct));
	else if (c == 'u')
		return (ft_print_base(va_arg(*arg_list, unsigned int),
				"0123456789", p_struct));
	else if (c == 'x')
		return (ft_print_base(va_arg(*arg_list, unsigned int),
				"0123456789abcdef", p_struct));
	else if (c == 'p')
	{
		return (ft_print_base_p(va_arg(*arg_list, unsigned long int),
				"0123456789abcdef", p_struct));
	}
	else if (c == 'X')
	{
		return (ft_print_base(va_arg(*arg_list, unsigned int),
				"0123456789ABCDEF", p_struct));
	}
	return (-1);
}

int		ft_atoi(const char *str)
{
	int		i;
	int		result;

	result = 0;
	i = 0;
	if (47 <= str[i] && str[i] <= 57)
	{
		while (47 <= str[i] && str[i] <= 57)
		{
			result = (str[i] - 48) + (result * 10);
			i++;
		}
	}
	return (result);
}

int		ft_printf_2(t_list *p_struct, const char *str, va_list *arg_list, int i)
{
	int res;

	res = 0;
	while (str[i])
	{
		if (i != 0 && str[i - 1] == '%' && p_struct->spec != '%')
		{
			i = i + ft_fill_p_struct(p_struct, &str[i], arg_list);
			if (ft_launch_fct(p_struct->spec, arg_list, p_struct) == -1)
				return (-1);
			if (p_struct->spec == '%' && str[i + 1] == '%')
			{
				p_struct->spec = (char)NULL;
				i++;
			}
		}
		else if (str[i] != '%')
		{
			p_struct->spec = ' ';
			p_struct->res += write(1, &str[i], 1);
		}
		(*p_struct) = (t_list){ .spec = p_struct->spec, .res = p_struct->res};
		i++;
	}
	return (p_struct->res);
}

int		ft_printf(const char *str, ...)
{
	va_list		arg_list;
	t_list		p_struct;
	int			res;
	int			i;

	i = 0;
	(p_struct) = (t_list){0};
	va_start(arg_list, str);
	res = ft_printf_2(&p_struct, str, &arg_list, i);
	va_end(arg_list);
	return (res);
}
