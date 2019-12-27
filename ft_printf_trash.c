/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_trash.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: seruiz <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/18 16:33:31 by seruiz       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/27 12:57:26 by seruiz      ###    #+. /#+    ###.fr     */
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

int		ft_fill_prec(t_list *t_struct, const char *s,
		va_list *arg_list, t_listint *lst)
{
	if (s[lst->i] == '.')
	{
		lst->btn = 1;
		lst->i++;
		if (s[lst->i] != '*')
		{
			t_struct->prec = ft_atoi(&s[lst->i]);
			while (48 <= s[lst->i] && s[lst->i] <= 57)
				lst->i++;
		}
		else if (s[lst->i] == '*')
		{
			lst->i++;
			t_struct->prec = va_arg(*arg_list, int);
			if (t_struct->prec < 0 && (s[lst->i] == 's' || s[lst->i] == '%'))
				t_struct->prec = -2;
		}
		else
			t_struct->prec = -1;
	}
	t_struct->spec = s[lst->i];
	if (lst->btn == 1 && t_struct->prec == 0)
		t_struct->prec = -1;
	return (lst->i);
}

int		ft_fill_struct(t_list *t_struct, const char *str, va_list *arg_list)
{
	int			i;
	t_listint	lst;

	lst.btn = 0;
	lst.i = 0;
	if (str[lst.i] == '-' || str[lst.i] == '0')
		t_struct->flag = str[lst.i];
	while (str[lst.i] == '-' || str[lst.i] == '0')
		lst.i++;
	if (str[lst.i] != '*' && (t_struct->width = ft_atoi(&str[lst.i])) >= 0)
		while (48 <= str[lst.i] && str[lst.i] <= 57)
			lst.i++;
	else if (str[lst.i] == '*')
	{
		lst.i++;
		t_struct->width = va_arg(*arg_list, int);
		if (t_struct->width < 0)
		{
			t_struct->width = t_struct->width * -1;
			t_struct->flag = '-';
		}
	}
	return (ft_fill_prec(t_struct, str, arg_list, &lst));
}
