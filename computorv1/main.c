/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <brel-baz@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 18:13:06 by brel-baz          #+#    #+#             */
/*   Updated: 2017/03/21 18:13:12 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*split_space(char *str)
{
	int i;
	int j;
	int len;
	int space;
	char *tab;

	i = 0;
	j = 0;
	space = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			space++;
		i++;
	}
	len = ft_strlen(str) - space;
	tab = malloc(len);
	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
		{
			tab[j] = str[i];
			j++;
		}
		i++;
	}
	tab[j] = '\0';
	return(tab);
}

char	get_degree(char *str)
{
	int i;
	char degree;

	i = 0;
	degree = 0;
	while (str[i])
	{
		if (str[i] == '^')
		{
			if (str[i + 1] > degree)
				degree = str[i + 1];
		}
		i++;
	}
	return (degree);
}

int 	tablen(char *str)
{
	int i;
	int j;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
	 j = 0;
	else
		j = 1;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-' || str[i] == '=')
			j++;
		i++;
	}
	return (j);
}

char	**parse(char *str)
{
	int i;
	int j;
	int k;
	char *str2;
	char **tab;

	i = 0;
	j = 0;
	str2 = split_space(str);
	tab = malloc(tablen(str));
	while (j < tablen(str))
	{
		tab[j] = ft_strnew(1096);
		k = 0;
		tab[j][k] = str2[i];
		k++;
		i++;
		while (str2[i] != '+' && str2[i] != '-' && str2[i] != '=' && str2[i])
		{
			tab[j][k] = str2[i];
			i++;
			k++;
		}
		j++;
	}
	return (tab);
}

double	convert(char *str)
{
	int i;
	char *str2;
	double convert;

	i = 0;
	str2 = ft_strnew(1096);
	while (str[i] != '*' && str[i])
	{
		str2[i] = str[i];
		i++;
	}
	convert = atof(str2);
	return (convert);
}

double sqrt_double(double d) 
{
  double a;
  double b;
  double m;
  double x;
  if(d == 0.0) 
  {
     return 0.0;
  } 
  else 
  {
     m = 1.0;
     x = d;
     while(x >= 2.0) 
     {
        x = 0.25 * x;
        m = 2.0 * m;
     }
     while( x < 0.5) 
     {
        x = 4.0 * x;
        m = 0.5 * m;
     }
     a = x;
     b = 1.0 - x;
     do 
     {
        a = a * (1.0 + 0.5 * b);
        b = 0.25 * (3.0 + b) * b * b;
     } 
     while(b >= 1.0E-15);
        return a * m;
  }
}

int		main(int argc, char **argv)
{

	char **tab;
	char **left;
	char **right;
	int i;
	double a;
	double b;
	double c;
	double d;
	double x;
	double x1;
	double x2;
	double delta;

	i = 0;
	a = 0;
	b = 0;
	c = 0;
	d = 0;
	if (argc == 2)
	{
		if (get_degree(argv[1]) > '2')
		{
			printf("Polynomial degree: %c\n", get_degree(argv[1]));
			printf("The polynomial degree is stricly greater than 2, I can't solve.\n");
			return (0);
		}
		tab = ft_strsplit(argv[1], '=');
		if (tablen(tab[0]) > 1)
			left = parse(tab[0]);
		if (tablen(tab[1]) > 1)
			right = parse(tab[1]);
		if (tablen(tab[0]) > 1)
		{
			while (i < tablen(tab[0]))
			{
				if (get_degree(left[i]) == '0')
					c = c + convert(left[i]);
				else if (get_degree(left[i]) == '1')
					b = b + convert(left[i]);
				else if (get_degree(left[i]) == '2')
					a = a + convert(left[i]);
				i++;
			}
		}
		else
		{
			if (get_degree(tab[0]) == '0')
				c = c + convert(tab[0]);
			else if (get_degree(tab[0]) == '1')
				b = b + convert(tab[0]);
			else if (get_degree(tab[0]) == '2')
				a = a + convert(tab[0]);
		}	
		i = 0;
		if (tablen(tab[1]) > 1)
		{
			while (i < tablen(tab[1]))
			{
				if (get_degree(right[i]) == '0')
					c = c + (convert(right[i]) * -1);
				else if (get_degree(right[i]) == '1')
					b = b + (convert(right[i]) * -1);
				else if (get_degree(right[i]) == '2')
					a = a + (convert(right[i]) * -1);
				i++;
			}
		}
		else
		{
			while (i < tablen(tab[1]))
			{
				if (get_degree(tab[1]) == '0')
					c = c + (convert(tab[1]) * -1);
				else if (get_degree(tab[1]) == '1')
					b = b + (convert(tab[1]) * -1);
				else if (get_degree(tab[1]) == '2')
					a = a + (convert(tab[1]) * -1);
				i++;
			}			
		}
	
		if (get_degree(argv[1]) == '0')
		{
			printf("Polynomial degree : 0\n");
			printf("All real numbers are solution\n");
			return (0);
		}
		if (get_degree(argv[1]) == '1' || a == 0)
		{
			printf("Reduced form : (%.1f * X^0) + (%.1f * X^1) = 0\n", c, b);
			printf("-%.2f / %.2f\n", c, b);
			printf("x = %f\n", (c * -1) / b);
			return (0);
		}
		if (get_degree(argv[1]) == '2')
		{
			printf("Reduced form : (%.1f * X^0) + (%.1f * X^1) + (%.1f * X^2) = 0\n", c, b, a);
			printf("Polynomial degree: 2\n");
			delta = (b * b) - (4 * a * c);
			if (delta > 0)
			{
				printf("(-%.2f -\u221a%.2f) / (2 * %.2f)\n", b, delta, a);
				printf("(-%.2f +\u221a%.2f) / (2 * %.2f)\n", b, delta, a);
				x1 = (-b - sqrt_double(delta)) / (2 * a);
				x2 = (-b + sqrt_double(delta)) / (2 * a);
				printf("Discriminant is strictly positive (%.2f), the two solutions are:\n", delta);
				printf("x1 = %f\n", x1);
				printf("x2 = %f\n", x2);
			}
			else if (delta == 0)
			{
				x = -b / 2 * a;
				printf("Discriminant is equal 0 , the only solution is:\n");
				printf("-%.2f / 2 * %.2f\n", b, a);
				printf("x = %f", x);
			}
			else if (delta < 0)
			{
				printf("Discriminant is strictly negative (%.2f), the two complex solutions are:\n", delta);
				printf("x1 = %f - %f * i\n", -b / (2 * a), sqrt_double(-delta) / (2 * a));
				printf("x1 = %f + %f * i\n", -b / (2 * a), sqrt_double(-delta) / (2 * a));
			}
			return (0);
		}
	}
	return (0);
}