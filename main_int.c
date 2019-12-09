/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main_magik.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: seruiz <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/09 17:55:48 by seruiz       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 19:11:27 by seruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
	printf ("\n ------------------- TEST %%d -----------------\n");
	printf("%%d normal : |%d|", 1254);
	printf("\n");
	ft_printf("%%d normal : |%d|", 1254);
	printf("\n\n");
	printf("%%d avec le flag 0  : |%0d|", 1254);
	printf("\n");
	ft_printf("%%d avec le flag 0  : |%0d|", 1254);
	printf("\n\n");
	printf("%%d avec le flags - : |%-d|", 1254);
	printf("\n");
	ft_printf("%%d avec le flags - : |%-d|", 1254);
	printf("\n\n");
	printf("%%d avec 2 de width : |%2d|", 1254);
	printf("\n");
	ft_printf("%%d avec 2 de width : |%2d|", 1254);
	printf("\n\n");
	printf("%%d avec 12 de width : |%12d|", 1254);
	printf("\n");
	ft_printf("%%d avec 12 de width : |%12d|", 1254);
	printf("\n\n");
	printf("%%d avec 12 de prec : |%.12d|", 1254);
	printf("\n");
	ft_printf("%%d avec 12 de prec : |%.12d|", 1254);
	printf("\n\n");
	printf("%%d avec 12 de prec et 6 de width : |%6.12d|", 1254);
	printf("\n");
	ft_printf("%%d avec 12 de prec et 6 de width : |%6.12d|", 1254);
	printf("\n\n");
	printf("%%d avec 12 de prec et flag - : |%-.12d|", 1254);
	printf("\n");
	ft_printf("%%d avec 12 de prec et flag - : |%-.12d|", 1254);
	printf("\n\n");
	printf("%%d avec 12 de prec et 20 de width : |%20.12d|", 1254);
	printf("\n");
	ft_printf("%%d avec 12 de prec et 20 de width : |%20.12d|", 1254);
	printf("\n\n");
	printf("%%d avec 12 de width et flag - : |%-12d|", 1254);
	printf("\n");
	ft_printf("%%d avec 12 de width et flag - : |%-12d|", 1254);
	printf("\n\n");
	printf("%%d avec un point 0 : |%.0d|", 1254);
	printf("\n");
	ft_printf("%%d avec un point 0 : |%.0d|", 1254);
	printf("\n\n");
	printf("%%d avec une prec sup : |%.13d|", 1254);
	printf("\n");
	ft_printf("%%d avec une prec sup : |%.13d|", 1254);
	printf("\n\n");
	printf("%%d avec une prec egale : |%.5d|", 1254);
	printf("\n");
	ft_printf("%%d avec une prec egale : |%.5d|", 1254);
	printf("\n\n");
	printf("%%d avec une prec inf : |%.2d|", 1254);
	printf("\n");
	ft_printf("%%d avec une prec inf : |%.2d|", 1254);
	printf("\n\n");
	printf("%%d avec un point : |%.d|", 1254);
	printf("\n");
	ft_printf("%%d avec un point : |%.d|", 1254);
	printf("\n\n");
	printf("%%d avec 8 prec et 1 width: |%1.8d|", 1254);
	printf("\n");
	ft_printf("%%d avec 8 prec et 1 width: |%1.8d|", 1254);	
	printf("\n\n");
	printf("%%d avec 3 prec et 12 width : |%12.3d|", 1254);	
	printf("\n");
	ft_printf("%%d avec 3 prec et 12 width : |%12.3d|", 1254);	
	printf("\n\n");
	printf("%%d avec flag - 3 prec et 12 width : |%-12.3d|", 1254);	
	printf("\n");
	ft_printf("%%d avec flag - 3 prec et 12 width : |%-12.3d|", 1254);	
	printf("\n\n");
	printf("%%d avec 2 de prec : |%.2d|", 1254);
	printf("\n");
	ft_printf("%%d avec 2 de prec : |%.2d|", 1254);
	printf("\n\n");
	printf("%%d avec 20 de prec et 12 de width: |%12.20d|", 1254);
	printf("\n");
	ft_printf("%%d avec 20 de prec et 12 de width: |%12.20d|", 1254);
	printf("\n\n");
	printf("%%d avec 20 de prec et 12 de width et -: |%-12.20d|", 1254);
	printf("\n");
	ft_printf("%%d avec 20 de prec et 12 de width et -: |%-12.20d|", 1254);
	printf("\n\n");
	printf("\n\n\nMATTER\n\n");
	printf("%%d avec 10 de prec : |%.10d|", 1254);
	ft_printf("\n");
	ft_printf("%%d avec 10 de prec : |%.10d|", 1254);
	printf("\n\n");
	printf("%%d avec 2 de prec 20 de width : |%20.2d|", 1254);
	printf("\n");
	ft_printf("%%d avec 2 de prec 20 de width : |%20.2d|", 1254);
	printf("\n\n");
	printf("%%d avec 10 de prec 20 de width et - : |%-20.10d|", 1254);
	printf("\n");
	ft_printf("%%d avec 10 de prec 20 de width et - : |%-20.10d|", 1254);
	printf("\n\n");
	printf("%%d avec 2 de prec 20 de width et - : |%-20.2d|", 1254);
	printf("\n");
	ft_printf("%%d avec 2 de prec 20 de width et - : |%-20.2d|", 1254);
	printf("\n\n");
	printf("%%d 20 de width : |%20d|", 1254);
	printf("\n");
	ft_printf("%%d 20 de width : |%20d|", 1254);
	printf("\n\n");
	printf("%%d avec 10 de prec 20 de width et flag - : |%-20.10d|", 1254);
	printf("\n");
	ft_printf("%%d avec 10 de prec 20 de width et flag - : |%-20.10d|", 1254);
	printf("\n NEG \n");
	printf("%%d avec 10 de prec : |%.10d|", -1254);
	printf("\n");
	ft_printf("%%d avec 10 de prec : |%.10d|", -1254);
	printf("\n\n");
	printf("%%d avec 2 de prec 20 de width : |%20.2d|", -1254);
	printf("\n");
	ft_printf("%%d avec 2 de prec 20 de width : |%20.2d|", -1254);
	printf("\n\n");
	printf("%%d avec 10 de prec 20 de width et - : |%-20.10d|", -1254);
	printf("\n");
	ft_printf("%%d avec 10 de prec 20 de width et - : |%-20.10d|", -1254);
	printf("\n\n");
	printf("%%d avec 2 de prec 20 de width et - : |%-20.2d|", -1254);
	printf("\n");
	ft_printf("%%d avec 2 de prec 20 de width et - : |%-20.2d|", -1254);
	printf("\n\n");
	printf("%%d 20 de width : |%20d|", -1254);
	printf("\n");
	ft_printf("%%d 20 de width : |%20d|", -1254);
	printf("\n\n");
	printf("%%d avec 10 de prec 20 de width et flag - : |%-20.10d|", -1254);
	printf("\n");
	ft_printf("%%d avec 10 de prec 20 de width et flag - : |%-20.10d|", -1254);
	printf("\n\n");
	/*
	printf("%%d avec -15 de width en wildcard et 12 de prec : |%****d|", -1, 5,.1 ,2, 15555);
	printf("\n");
	ft_printf("%%d avec -15 de width en wildcard et 12 de prec : |%****d|", -1, 5,.1 ,2, 15555);
	*/
}
