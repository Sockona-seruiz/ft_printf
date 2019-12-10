/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main_math.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: seruiz <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/10 10:17:20 by seruiz       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/10 16:04:35 by seruiz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int main(void)
{
	char *s = "Bonjour, je suis malade";
	unsigned int u = 453123156;
	int d = -1365623632;
	printf("\n---------------Decimaux---------------\n\n");
	printf("true : ");
	printf("#%d#", d);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%d#", d);
	printf("\n\n");
	printf("true : ");
	printf("#%20d#", d);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%20d#", d);
	printf("\n\n");
	printf("true : ");
	printf("#%011d#", d);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%011d#", d);
	printf("\n\n");
	printf("true : ");
	printf("#%4d#", d);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%4d#", d);
	printf("\n\n");
	printf("true : "); //Ne fonctionne pas si la precision vaut la len du nombre
	printf("#%.11d#", d);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%.11d#", d);
	printf("\n\n");
	printf("true : ");
	printf("#%.4d#", d);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%.4d#", d);
	printf("\n\n");
	printf("true : ");
	printf("#%20.4d#", d);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%20.4d#", d);
	printf("\n\n");
	printf("\n---------------Unsigned---------------\n\n");
	printf("true : ");
	printf("#%u#", u);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%u#", u);
	printf("\n\n");
	printf("true : ");
	printf("#%20u#", u);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%20u#", u);
	printf("\n\n");
	printf("true : ");
	printf("#%011u#", u);//
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%011u#", u);
	printf("\n\n");
	printf("true : ");
	printf("#%4u#", u);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%4u#", u);
	printf("\n\n");
	printf("true : "); //Ne fonctionne pas si la precision vaut la len du nombre
	printf("#%.15u#", u);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%.15u#", u);
	printf("\n\n");
	printf("true : ");
	printf("#%.4u#", u);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%.4u#", u);
	printf("\n\n");
	printf("true : ");
	printf("#%20.4u#", u);
	printf("\n");
	ft_printf("ft_  : ");
	ft_printf("#%20.4u#", u);
	printf("\n\n");
	printf("---------------Chaine--De--Caractere---------------\n\n");
	printf("1 true : ");
	printf("#%s#", s);
	printf("\n");
	ft_printf("1 ft_  : ");                     //1
	ft_printf("#%s#", s);
	printf("\n\n");
	printf("2 true : ");
	printf("#%30s#", s);
	printf("\n");                             //2
	ft_printf("2 ft_  : ");
	ft_printf("#%30s#", s);
	printf("\n\n");
	printf("3 true : ");
	printf("#%.4s#", s);
	printf("\n");                             //3
	ft_printf("3 ft_  : ");
	ft_printf("#%.4s#", s);
	printf("\n\n");
	printf("4 true : ");
	printf("#%.30s#", s);
	printf("\n");                             //4
	ft_printf("4 ft_  : ");
	ft_printf("#%.30s#", s);
	printf("\n\n");
	printf("5 true : ");
	printf("#%30.4s#", s);
	printf("\n");                             //5
	ft_printf("5 ft_  : ");
	ft_printf("#%30.4s#", s);
	printf("\n\n");
	printf("6 true : ");
	printf("#%-s#", s);
	printf("\n");                              //6
	ft_printf("6 ft_  : ");
	ft_printf("#%-s#", s);
	printf("\n\n");
	printf("7 true : ");
	printf("#%-30s#", s);
	printf("\n");                              //7
	ft_printf("7 ft_  : ");
	ft_printf("#%-30s#", s);
	printf("\n\n");
	printf("8 true : ");
	printf("#%-.4s#", s);
	printf("\n");                              //8
	ft_printf("8 ft_  : ");
	ft_printf("#%-.4s#", s);
	printf("\n\n");
	printf("9 true : ");
	printf("#%-.30s#", s);
	printf("\n");                              //9
	ft_printf("9 ft_  : ");
	ft_printf("#%-.30s#", s);    
	printf("\n\n");
	printf("10 true : ");
	printf("#%0100.500s#", s);
	printf("\n");                              //9
	ft_printf("10 ft_  : ");
	ft_printf("#%0100.500s#", s);
	return (0);
}
