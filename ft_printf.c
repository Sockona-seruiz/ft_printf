/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: seruiz <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 11:06:38 by seruiz       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/27 12:37:36 by seruiz      ###    #+. /#+    ###.fr     */
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

int		ft_launch_fct(char c, va_list *arg_list, t_list *t_struct)
{
	if (c == 's')
		return (ft_print_str(va_arg(*arg_list, char *), t_struct));
	else if (c == 'c')
		return (ft_launch_char(arg_list, t_struct));
	else if (c == 'd' || c == 'i')
		return (ft_itoa_base(va_arg(*arg_list, int), "0123456789", t_struct));
	else if (c == 'u')
		return (ft_itoa_base(va_arg(*arg_list, long int),
				"0123456789", t_struct));
	else if (c == '%')
		return (ft_launch_perc(t_struct));
	else if (c == 'x')
		return (ft_itoa_base(va_arg(*arg_list, long int),
				"0123456789abcdef", t_struct));
	else if (c == 'p')
		return (ft_itoa_base_p(va_arg(*arg_list, unsigned long int),
				"0123456789abcdef", t_struct));
	else if (c == 'X')
	{
		return (ft_itoa_base(va_arg(*arg_list, long int),
				"0123456789ABCDEF", t_struct));
	}
	return (-1);
}

int		ft_atoi(const char *str)
{
	int		i;
	int		result;
	char	spec;

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

int		ft_printf_2(t_list *t_struct, const char *str, va_list *arg_list)
{
	int i;
	int res;

	res = 0;
	i = 0;
	while (str[i])
	{
		if (i != 0 && str[i - 1] == '%' && t_struct->spec != '%')
		{
			i = i + ft_fill_struct(t_struct, &str[i], arg_list);
			if (ft_launch_fct(t_struct->spec, arg_list, t_struct) == -1)
				return (-1);
			if (t_struct->spec == '%' && str[i + 1] == '%')
			{
				t_struct->spec = (char)NULL;
				i++;
			}
		}
		else if (str[i] != '%')
			t_struct->res += write(1, &str[i], 1);
		t_struct->prec = 0;
		t_struct->isneg = 0;
		i++;
	}
	return (t_struct->res);
}

int		ft_printf(const char *str, ...)
{
	va_list		arg_list;
	t_list		*t_struct;
	int			i;
	int			res;

	if ((t_struct = ft_calloc(sizeof(t_list), 1)) == 0)
		return (-1);
	t_struct->res = 0;
	res = 0;
	i = 0;
	va_start(arg_list, str);
	if ((res = ft_printf_2(t_struct, str, &arg_list)) == -1)
	{
		free(t_struct);
		return (-1);
	}
	free(t_struct);
	return (res);
}
