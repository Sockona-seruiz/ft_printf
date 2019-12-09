/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: seruiz <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 11:25:05 by seruiz       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 19:15:59 by seruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	/*
	ft_printf("ceci est un %-10.2s, on affiche %00021.69c et %.*d\n%*.*s\n\n", "test", 'i', 20, 28958895, 6, 4, "ALEDPUTAIN");
	ft_printf("ceci est un %-10.2s, on affiche %00021.69c et %.*d\n%*.*s\n\n", "test", 'i', 20, -28958895, 6, 4, "ALEDPUTAIN");
	printf("ceci est un %-10.2s, on affiche %00021.69c et %.*d\n%*.*s\n\n", "test", 'i', 20, -28958895, 6, 4, "ALEDPUTAIN");
	printf("ceci est un %-10.2s, on affiche %00021.69c et %.*d\n%*.*s\n\n", "test", 'i', 20, 28958895, 6, 4, "ALEDPUTAIN");
	*/
	ft_printf("|%-28.20d|\n", 28958895);
	printf("|%-28.20d|\n", 28958895);
	printf("\n");
	printf("|%-15.20d|\n", 28958895);
	ft_printf("|%-15.20d|\n", 28958895);
	printf("\n");
	printf("%-28.20d\n", 28958895);
	ft_printf("%-28.20d\n", 28958895);
	printf("\n");
	printf("%-28.20u\n", 28958895);
	ft_printf("%-28.20u\n", 28958895);
	/*
	ft_printf("%.20d\n", -28958895);
	printf("%.20d\n\n", -28958895);
	ft_printf("%.4d\n", 28958895);
	printf("%.4d\n", 28958895);
	ft_printf("%.4d\n", -28958895);
	printf("%.4d\n", -28958895);
	*/
}
