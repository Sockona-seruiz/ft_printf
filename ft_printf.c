/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: seruiz <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 11:06:38 by seruiz       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/04 17:48:43 by seruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/*
** Ne travailler qu'avec des des chaines de charactere!!
*/

#include "ft_printf.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*mem_calloc;
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

size_t ft_strlen(char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_print_char(va_list *arg_list)
{
	char c;

	c = va_arg(*arg_list, int);
	write(1, &c, 1);
	return (1);
}

int		ft_print_int(long int nb, int i)
{
	char c;
	char neg;

	i++;
	if (nb < 0)
	{
		neg = '-';
		write(1, &neg, 1);
		nb = nb * -1;
	}
	if (nb >= 10)
		i = ft_print_int(nb / 10, i);
	c = nb % 10 + 48;
	write(1, &c, 1);
	return (i);
}

int		ft_print_str(char *str, t_list *t_struct)
{
	int		i;

	i = ft_strlen(str);
	write(1, str, i);
	return (i);
}

int		ft_launch_fct(char c, va_list *arg_list, t_list *t_struct)
{
	int i;

	i = 0;
	if (c == 's')
		return (ft_print_str(va_arg(*arg_list, char *), t_struct));
	else if (c == 'c')
		return (ft_print_char(arg_list));
	else if (c == 'd')
		return (ft_itoa(va_arg(*arg_list, int), t_struct));
	return (-1);
}

int ft_atoi(const char *str)
{
	int i;
	int result;
	int sign;

	sign = 1;
	result = 0;
	i = 0;
	while (48 <= str[i] && str[i] <= 57)
	{
		result = (str[i] - 48) + (result * 10);
		i++;
	}
	return (result * sign);
}

void	ft_fill_struct(t_list *t_struct, const char *str, va_list *arg_list)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] == '-' || str[i] == '0')
		t_struct->flag = str[i++];
	if ((t_struct->width = ft_atoi(&str[i])) > 0)
		while (48 <= str[i] && str[i] <= 57)
			i++;
	else if (str[i] == '*')
	{
		i++;
		t_struct->width = va_arg(*arg_list, int);
	}
	i = i + j;
	j = 0;
	if (str[i] == '.')
	{
		i++;
		if ((t_struct->prec = ft_atoi(&str[i])) > 0)
			while (48 <= str[i] && str[i] <= 57)
				i++;
		else if (str[i] == '*')
		{
			i++;
			t_struct->prec = va_arg(*arg_list, int);
		}
	}
	i = i + j;
	t_struct->spec = str[i];
}

void	ft_clean_struct(t_list *t_struct)
{
	t_struct->flag = (char)NULL;
	t_struct->width = (int)NULL;
	t_struct->prec = (int)NULL;
	t_struct->spec = (char)NULL;
}

int		ft_printf(const char *str, ...)
{
	//void (*functions[INDEX_SIZE + 1])(va_list *);
	va_list arg_list;
	t_list	*t_struct;
	int i;
	int res;
	int idx;

	if ((t_struct = ft_calloc(sizeof(t_list), 1)) == 0)
		return (-1);
	//ft_clean_struct(t_struct);
	/*
	functions[0] = ft_print_str;
	functions[1] = ft_print_char;
	functions[2] = ft_print_int;*/
	i = 0;
	idx = 0;
	va_start(arg_list, str);
	while (str[i])
	{
		if (i != 0 && str[i - 1] == '%')
		{
			ft_fill_struct(t_struct, &str[i], &arg_list);
			res = res + ft_launch_fct(t_struct->spec, &arg_list, t_struct);
			/*
			if (idx != -1)
				(*Functions[idx])(&arg_list);*/
			printf("struct flag :%c\nstruct width :%d\nstruct prec :%d\nstruct spec :%c\n", t_struct->flag, t_struct->width, t_struct->prec, t_struct->spec);
			ft_clean_struct(t_struct);
		}
		else if (str[i] != '%')
			write(1, &str[i], 1);
		i++;
		res++;
	}
	free(t_struct);
	printf("printf result : %d\n", res);
	return (i);
}
