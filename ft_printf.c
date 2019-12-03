/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: seruiz <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 11:06:38 by seruiz       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/03 11:43:54 by seruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
//#include <libft.a>

typedef	struct	s_list
{
	char		flag;
	int			width;
	int			prec;
	char		spec;
}				t_list;

size_t ft_strlen(char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_print_char(va_list *arg_list)
{
	char c;

	c = va_arg(*arg_list, int);
	write(1, &c, 1);
}


void	ft_print_int_2(int nb)
{
	int i;
	int tab[10];

	i = 0;
	while (nb >= 10)
	{
		tab[i] = nb % 10 + '0';
		nb = nb / 10;
		i++;
	}
	tab[i] = nb + '0';
	while (i >= 0)
	{
		write(1, &tab[i], 1);
		i--;
	}
}

void	ft_print_int(va_list *arg_list)
{
	int nb;

	nb = va_arg(*arg_list, int);

	if (nb < 0)
	{
		if (nb == -2147483648)
		{
			write(1, "-2147483648", 11);
			return ;
		}
		write(1, "-", 1);
		nb = nb * -1;
	}
	ft_print_int_2(nb);
}

void	ft_print_str(va_list *arg_list)
{
	char *str;

	str = va_arg(*arg_list, char *);
	write(1, str, ft_strlen(str));
}

int		ft_find_index(char c)
{
	int i;
	char Index[10];

	Index[0] = 's';
	Index[1] = 'c';
	Index[2] = 'd';
	Index[3] = 'p';
	Index[4] = 'i';
	Index[5] = 'u';
	Index[6] = 'x';
	Index[7] = 'X';
	Index[8] = '%';
	Index[9] = 0;

	i = 0;
	while (Index[i])
	{
		if (Index[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int ft_atoi(char *str)
{
	int i;
	int result;
	int sign;

	sign = 1;
	result = 0;
	i = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (48 <= str[i] && str[i] <= 57)
	{
		result = (str[i] - 48) + (result * 10);
		i++;
	}
	free(str);
	return (result * sign);
}

void	ft_fill_width(t_list *t_struct, char *str, int j)
{
	char *result;

	if ((result = malloc(sizeof(char) * (j + 1))) == 0)
		return ;
	j = 0;
	while (48 <= str[j] && str[j] <= 57)
	{
		result[j] = str[j];
		j++;
	}
	t_struct->width = ft_atoi(result);
}

void	ft_fill_struct(t_list *t_struct, char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (str[i] == '-' || str[i] == '0')
	{
		t_struct->flag = str[i];
		i++;
	}
	while (48 <= str[i + j] && str[i + j] <= 57)
		j++;
	if (j > 0)
		ft_fill_width(t_struct, &str[i], j);
}

void	ft_printf(char *str, ...)
{
	void (*Functions[3])(va_list *);
	va_list arg_list;
	t_list	*t_struct;
	int i;
	int idx;

	if ((t_struct = malloc(sizeof(t_list))) == 0)
		return ;
	Functions[0] = ft_print_str;
	Functions[1] = ft_print_char;
	Functions[2] = ft_print_int;
	i = 0;
	idx = 0;
	va_start(arg_list, str);
	while (str[i])
	{
		if (i != 0 && str[i - 1] == '%')
		{
			ft_fill_struct(t_struct, &str[i]);
			/*idx = ft_find_index(str[i]);
			if (idx != -1)
				(*Functions[idx])(&arg_list);*/
			printf("struct flag :%c\nstruct width :%d\n", t_struct->flag, t_struct->width);
		}
		else if (str[i] != '%')
			write(1, &str[i], 1);
		i++;
	}
}

int main(int ac, char **argv)
{
	ft_printf("ceci est un %-596s, on affiche %c et %d\n%s", "test", 'i', 42, "ALED");
}
