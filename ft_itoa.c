/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: seruiz <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 17:14:09 by seruiz       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/04 17:47:09 by seruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_intlen(long int n)
{
	int i;

	if (n == 0)
		return (1);
	i = 0;
	if (n < 0)
	{
		i++;
		n = n * -1;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int		ft_itoa(long int n, t_list *t_struct)
{
	char *result;
	int len;
	int i;

	len = ft_intlen(n);
	if ((result = malloc(sizeof(char) * (len + 1))) == 0)
		return (0);
	result[len] = '\0';
	if (n < 0)
	{
		result[0] = '-';
		n = n * -1;
	}
	while (n > 0)
	{
		result[len - 1] = (n % 10) + 48;
		n = n / 10;
		len--;
	}
	i = ft_print_str(result, t_struct);
	free(result);
	return (i);
	//return (result);
}
