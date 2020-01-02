/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_base.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: seruiz <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/02 14:46:06 by seruiz       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/02 14:47:49 by seruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_flag(t_list *t_struct, int len, char flag, char *number)
{
	char	*str;
	int		i;

	i = 0;
	if (len < 0)
		return (1);
	if ((str = malloc(sizeof(char) * (len + 1))) == NULL)
	{
		free(number);
		return (-1);
	}
	str[len] = '\0';
	while (i < len)
	{
		str[i] = flag;
		i++;
	}
	t_struct->res += write(1, str, len);
	free(str);
	return (1);
}

int		ft_flag_after(t_list *t_struct, int len, int prec, char *str)
{
	int res;

	if (prec > len)
		res = t_struct->width - prec;
	else
		res = t_struct->width - len;
	if (t_struct->isneg == -1)
		res--;
	else if (t_struct->isneg == 1)
	{
		t_struct->res += write(1, "-", 1);
		res--;
	}
	if (t_struct->spec == 'p')
	{
		res = res - 2;
		t_struct->res += write(1, "0x", 2);
	}
	if (len == 1 && str[0] == '0' && t_struct->prec == -1)
		t_struct->res += write(1, " ", 1);
	else
		t_struct->res += write(1, str, len);
	return (ft_print_flag(t_struct, res, ' ', str));
}

int		ft_prec(t_list *t_struct, int len, char *number)
{
	int prec;

	prec = t_struct->prec;
	if (t_struct->isneg == 1)
	{
		t_struct->res += write(1, "-", 1);
		t_struct->isneg = -1;
	}
	t_struct->prec = 0;
	return (ft_print_flag(t_struct, prec - len, '0', number));
}

int		ft_flag_before(t_list *t_struct, int len, char *number)
{
	if (t_struct->prec == 0 && t_struct->flag == '0')
	{
		t_struct->prec = t_struct->width;
		if (t_struct->isneg == 1)
			t_struct->prec--;
		return (ft_prec(t_struct, len, number));
	}
	if (t_struct->isneg == 1)
		t_struct->width--;
	if (t_struct->spec == 'p')
		t_struct->width = t_struct->width - 2;
	if (len > t_struct->prec)
		return (ft_print_flag(t_struct, t_struct->width - len, ' ', number));
	else
		return (ft_print_flag(t_struct,
					t_struct->width - t_struct->prec, ' ', number));
}

int		ft_launch_fct_int(char *number, t_list *t_struct, int len)
{
	int	prec;

	prec = t_struct->prec;
	if (t_struct->flag != '-' && t_struct->width > len)
		if ((ft_flag_before(t_struct, len, number)) == -1)
			return (-1);
	if (t_struct->prec != 0 && t_struct->prec != -1)
		if ((ft_prec(t_struct, len, number)) == -1)
			return (-1);
	if (t_struct->flag == '-')
		if ((ft_flag_after(t_struct, len, prec, number)) == -1)
			return (-1);
	if (t_struct->flag != '-')
	{
		if (t_struct->isneg == 1)
			t_struct->res += write(1, "-", 1);
		if (t_struct->spec == 'p')
			t_struct->res += write(1, "0x", 2);
		if (len == 1 && number[0] == '0' && t_struct->prec == -1)
			t_struct->res += write(1, " ", 1);
		else
			t_struct->res += write(1, number, len);
	}
	free(number);
	return (1);
}
