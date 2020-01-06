/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_prec_width_itoa.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: seruiz <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/02 14:46:16 by seruiz       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/02 16:00:46 by seruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** (. || .0) => prec = -1
** prec < 0  => prec = -2
*/

char	*calcul_base(unsigned long int number, char *base, int len, int count)
{
	char	*result;

	if ((result = malloc(sizeof(char) * (count + 1))) == 0)
		return (NULL);
	result[count] = 0;
	count--;
	while (number > (unsigned long int)len - 1)
	{
		result[count] = base[number % len];
		count--;
		number = number / len;
	}
	result[count--] = base[number];
	return (result);
}

int		ft_print_base_p(unsigned long int number, char *base, t_list *t_struct)
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
	while (buff > (unsigned long int)(len - 1))
	{
		buff = buff / len;
		count++;
	}
	if ((result = calcul_base(number, base, len, count)) == NULL)
		return (-1);
	return (ft_launch_fct_int(result, t_struct, ft_strlen(result)));
}

int		ft_print_base(long number, char *base, t_list *t_struct)
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
	if (number == 0 && t_struct->prec == -1 &&
			t_struct->width == 0 && t_struct->prec != -2)
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
	return (ft_launch_fct_int(result, t_struct, ft_strlen(result)));
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
			if (t_struct->prec < 0)
				t_struct->prec = -2;
		}
	}
	t_struct->spec = s[lst->i];
	if (lst->btn == 1 && t_struct->prec == 0)
		t_struct->prec = -1;
	return (lst->i);
}

int		ft_fill_struct(t_list *t_struct, const char *str, va_list *arg_list)
{
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
