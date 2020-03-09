/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruiz <seruiz@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 10:27:09 by seruiz            #+#    #+#             */
/*   Updated: 2020/03/06 10:26:59 by seruiz           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_flag(t_list *p_struct, int len, char flag, char *number)
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
	p_struct->res += write(1, str, len);
	free(str);
	return (1);
}

int		ft_flag_after(t_list *p_struct, int len, int prec, char *str)
{
	int res;

	if (prec > len)
		res = p_struct->width - prec;
	else
		res = p_struct->width - len;
	if (p_struct->isneg == -1)
		res--;
	else if (p_struct->isneg == 1)
	{
		p_struct->res += write(1, "-", 1);
		res--;
	}
	if (p_struct->spec == 'p')
	{
		res = res - 2;
		p_struct->res += write(1, "0x", 2);
	}
	if (len == 1 && str[0] == '0' && p_struct->prec == -1)
		p_struct->res += write(1, " ", 1);
	else
		p_struct->res += write(1, str, len);
	return (ft_print_flag(p_struct, res, ' ', str));
}

int		ft_prec(t_list *p_struct, int len, char *number)
{
	int prec;

	prec = p_struct->prec;
	if (p_struct->isneg == 1)
	{
		p_struct->res += write(1, "-", 1);
		p_struct->isneg = -1;
	}
	p_struct->prec = 0;
	return (ft_print_flag(p_struct, prec - len, '0', number));
}

int		ft_flag_before(t_list *p_struct, int len, char *number)
{
	if ((p_struct->prec == 0 || p_struct->prec == -2) && p_struct->flag == '0')
	{
		p_struct->prec = p_struct->width;
		if (p_struct->isneg == 1)
			p_struct->prec--;
		return (ft_prec(p_struct, len, number));
	}
	if (p_struct->isneg == 1)
		p_struct->width--;
	if (p_struct->spec == 'p')
		p_struct->width = p_struct->width - 2;
	if (len > p_struct->prec)
		return (ft_print_flag(p_struct, p_struct->width - len, ' ', number));
	else
		return (ft_print_flag(p_struct,
					p_struct->width - p_struct->prec, ' ', number));
}

int		ft_launch_fct_int(char *number, t_list *p_struct, int len)
{
	int	prec;

	prec = p_struct->prec;
	if (p_struct->flag != '-' && p_struct->width > len)
		if ((ft_flag_before(p_struct, len, number)) == -1)
			return (-1);
	if (p_struct->prec != 0 && p_struct->prec != -1)
		if ((ft_prec(p_struct, len, number)) == -1)
			return (-1);
	if (p_struct->flag == '-')
		if ((ft_flag_after(p_struct, len, prec, number)) == -1)
			return (-1);
	if (p_struct->flag != '-')
	{
		if (p_struct->isneg == 1)
			p_struct->res += write(1, "-", 1);
		if (p_struct->spec == 'p')
			p_struct->res += write(1, "0x", 2);
		if (len == 1 && number[0] == '0' && p_struct->prec == -1)
			p_struct->res += write(1, " ", 1);
		else
			p_struct->res += write(1, number, len);
	}
	free(number);
	return (1);
}
