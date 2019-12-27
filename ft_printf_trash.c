/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_trash.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: seruiz <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/18 16:33:31 by seruiz       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/27 11:18:35 by seruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_itoa_base_p(unsigned long int number, char *base, t_list *t_struct)
{
	int					len;
	int					count;
	unsigned long int	buff;
	char				*result;

	if (number == 0 && t_struct->prec == -1)
	{
		t_struct->res += write(1, "0x", 2);
		return (1);
	}
	len = ft_strlen(base);
	buff = number;
	count = 1;
	while (buff > len - 1)
	{
		buff = buff / len;
		count++;
	}
	if ((result = calcul_base(number, base, len, count)) == NULL)
		return (-1);
	ft_launch_fct_int(result, t_struct, ft_strlen(result));
	return (1);
}

int		ft_itoa_base(long number, char *base, t_list *t_struct)
{
	int		len;
	int		count;
	long	buff;
	char	*result;

	if (number < 0)
	{
		t_struct->isneg = 1;
		number = number * -1;
	}
	if (number == 0 && t_struct->prec == -1 && t_struct->width == 0)
		return (1);
	len = ft_strlen(base);
	buff = number;
	count = 1;
	while (buff > (long)len - 1)
	{
		buff = buff / len;
		count++;
	}
	if ((result = calcul_base(number, base, len, count)) == NULL)
		return (-1);
	ft_launch_fct_int(result, t_struct, ft_strlen(result));
	return (1);
}

void	*ft_calloc(size_t count, size_t size)
{
	char			*mem_calloc;
	unsigned int	i;

	i = 0;
	if ((mem_calloc = malloc(count * size)) == 0)
		return (0);
	while (i < (count * size))
	{
		mem_calloc[i] = 0;
		i++;
	}
	return ((void *)mem_calloc);
}

int		ft_fill_prec(t_list *t_struct, const char *str,
		va_list *arg_list, int i)
{
	int btn;

	btn = 0;
	if (str[i] == '.')
	{
		btn = 1;
		i++;
		if (str[i] != '*')
		{
			t_struct->prec = ft_atoi(&str[i]);
			while (48 <= str[i] && str[i] <= 57)
				i++;
		}
		else if (str[i] == '*')
		{
			i++;
			t_struct->prec = va_arg(*arg_list, int);
			if (t_struct->prec < 0 && str[i] == 's')
				t_struct->prec = -2;
		}
		else
			t_struct->prec = -1;
	}
	t_struct->spec = str[i];
	if (btn == 1 && t_struct->prec == 0)
		t_struct->prec = -1;
	return (i);
}

int		ft_fill_struct(t_list *t_struct, const char *str, va_list *arg_list)
{
	int i;

	i = 0;
	if (str[i] == '-' || str[i] == '0')
		t_struct->flag = str[i];
	while (str[i] == '-' || str[i] == '0')
		i++;
	if (str[i] != '*' && (t_struct->width = ft_atoi(&str[i])) >= 0)
		while (48 <= str[i] && str[i] <= 57)
			i++;
	else if (str[i] == '*')
	{
		i++;
		t_struct->width = va_arg(*arg_list, int);
		if (t_struct->width < 0)
		{
			t_struct->width = t_struct->width * -1;
			t_struct->flag = '-';
		}
	}
	return (ft_fill_prec(t_struct, str, arg_list, i));
}
