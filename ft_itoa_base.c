/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa_base.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: seruiz <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/16 12:27:12 by seruiz       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/18 17:05:53 by seruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_after(t_list *t_struct, int len, int prec, char *str)
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
	t_struct->res += write(1, str, len);
	while (res > 0)
	{
		t_struct->res += write(1, " ", 1);
		res--;
	}
}

void	ft_prec(t_list *t_struct, int len)
{
	if (t_struct->isneg == 1)
	{
		t_struct->res += write(1, "-", 1);
		t_struct->isneg = -1;
	}
	while (t_struct->prec > len)
	{
		t_struct->res += write(1, "0", 1);
		t_struct->prec--;
	}
	t_struct->prec = 0;
}

void	ft_flag_before(t_list *t_struct, int len)
{
	if (t_struct->prec == 0 && t_struct->flag == '0')
	{
		t_struct->prec = t_struct->width;
		if (t_struct->isneg == 1)
			t_struct->prec--;
		ft_prec(t_struct, len);
		return ;
	}
	if (t_struct->isneg == 1)
		t_struct->width--;
	if (t_struct->spec == 'p')
		t_struct->width = t_struct->width - 2;
	while (t_struct->width > len && t_struct->width > t_struct->prec)
	{
		t_struct->res += write(1, " ", 1);
		t_struct->width--;
	}
}

void	ft_launch_fct_int(char *number, t_list *t_struct, int len)
{
	int prec;

	prec = t_struct->prec;
	if (t_struct->flag != '-' && t_struct->width > len)
		ft_flag_before(t_struct, len);
	if (t_struct->prec != 0)
		ft_prec(t_struct, len);
	if (t_struct->flag == '-')
		ft_flag_after(t_struct, len, prec, number);
	else
	{
		if (t_struct->isneg == 1)
			t_struct->res += write(1, "-", 1);
		if (t_struct->spec == 'p')
			t_struct->res += write(1, "0x", 2);
		t_struct->res += write(1, number, len);
	}
}

char	*calcul_base(unsigned long int number, char *base, int len, int count)
{
	char *result;

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
