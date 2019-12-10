/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: seruiz <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 11:25:05 by seruiz       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/10 18:35:47 by seruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int ret;

	ret = printf("|%-28.20d|\n", 28958895);
	printf("ret : %d\n", ret);
	ret = ft_printf("|%-28.20d|\n", 28958895);
	printf("ret : %d\n", ret);
	printf("\n");
	ret = printf("|%-15.20d|\n", 28958895);
	printf("ret : %d\n", ret);
	ret = ft_printf("|%-15.20d|\n", 28958895);
	printf("ret : %d\n", ret);
	printf("\n");
	ret = printf("|%-28.20d|\n", 28958895);
	printf("ret : %d\n", ret);
	ret = ft_printf("|%-28.20d|\n", 28958895);
	printf("ret : %d\n", ret);
	printf("\n");
	ret = printf("|%-28.20u|\n", 28958895);
	printf("ret : %d\n", ret);
	ret = ft_printf("|%-28.20u|\n", 28958895);
	printf("ret : %d\n", ret);
	printf("\n width =  prec = 8\n");
	ret = printf("|%.8d|\n", -28958895);
	printf("ret : %d\n", ret);
	ret = ft_printf("|%.8d|\n", -28958895);
	printf("ret : %d\n", ret);
	printf("\n width = 10 prec = 8 \n");
	ret = printf("|%10.8d|\n", -2895889);
	printf("ret : %d\n", ret);
	ret = ft_printf("|%10.8d|\n", -2895889);
	printf("ret : %d\n", ret);
	printf("\n width = 25 prec = 22\n");
	ret = printf("|%25.22d|\n", -2895889);
	printf("ret : %d\n", ret);
	ret = ft_printf("|%25.22d|\n", -2895889);
	printf("ret : %d\n", ret);
	printf("\n");
	ret = printf("|%35.22d|\n", -2895889);
	printf("ret : %d\n", ret);
	ret = ft_printf("|%35.22d|\n", -2895889);
	printf("ret : %d\n", ret);
	printf("\n");
	printf("|%.*15s|\n", -15, "bonjour");
	ft_printf("|%.*15s|\n", -15, "bonjour");
	printf("\n");
	printf("|%046d|\n", -2147483648);
	ft_printf("|%046d|\n", -2147483648);
	printf("\n");
	printf("|%046u|\n", 4294967295);
	ft_printf("|%046u|\n", 4294967295);

}
