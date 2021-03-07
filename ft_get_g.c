/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_g.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trofidal <trofidal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 01:11:47 by trofidal          #+#    #+#             */
/*   Updated: 2021/03/07 13:30:46 by trofidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_g(char *flags, va_list args)
{
	
}

/*	1 = 				1.000000e+00
*	12 =				1.200000e+00
*	123 =				1.230000e+02
*	1234 =				1.234000e+03
*	12345 =				1.234500e+04
*	123456 =			1.234560e+05
*	1234567 =			1.234567e+06
*	12345678 =			1.234568e+07
*	123456789 =			1.234568e+08
*/

unsigned long long int		ft_get_pow(double nbr)
{
	int i;
	int minus;
	char *str;

	str = ft_putnbr_float(nbr);
	i = ft_strlen(str);
	minus = i - 4;
	i = ft_recursive_power(10, (i - minus));
	free (str);
	return (i);
}

char	*ft_to_big_brain(double nbr)
{
    unsigned long long int start;
    unsigned long long int end;
	unsigned long long int pow;
	unsigned long long int len;
    char *final;
    char *str;

	len = 1;
	pow = ft_get_pow(nbr);
    if (nbr < 0)
        start = -nbr * (pow * 10);
    else
        start = nbr * (pow * 10);
	str = ft_itoa(start);
	len = ft_recursive_power(10, ft_strlen(str) - 5);
	free (str);
    end = start % (pow * len);
    start /= pow * len;
    str = ft_itoa((int)start);
    final = ft_calloc(sizeof(final), (6 + ft_strlen(str)));
    final = ft_strcpy(final, str);
    free (str);
    final[ft_strlen(final)] = '.';
    str = ft_itoa((int)end);
    ft_strcat(final, str);
    free (str);
    return (final);
}

char	*ft_to_science(double n)
{
	char *str;
	char *number;
	char *e;
	unsigned long long nb;
	int i;

	i = 0;
	if (!(str = ft_calloc(sizeof(str), 12)))
		return (NULL);
	str = ft_putnbr_float(n);
	while (str[i] != '.')
		i++;
	free (str);
	str = ft_to_big_brain(n);
	if (!(number = ft_calloc(sizeof(str), 5)))
		return (NULL);
	number[0] = '+';
	number[1] = 'e';
	if (i > 9)
		e = ft_itoa(i);
	else
	{
		number[2] = '0';
		number[3] = '0' + i - 1;
	}
	number[4] = '\0';
	if (i > 9)
	{
		number = ft_strcat(number, e);
		free (e);
	}
	i = ft_strlen(str);
	if (i > 8)
		str[8] = '\0';
	if (ft_strlen(str) != 8)
	{
		str[i] = '0';
		i++;
	}
	str = ft_strcat(str, number);
	free (number);
	return (str);
}

int main()
{
	double a;
	a = 39.19565;
	printf("%f en scientifique = %s\n", a ,ft_to_science(a));
	a = 144.15;
	printf("%f en scientifique = %s\n", a ,ft_to_science(a));
	a = 98.3;
	printf("%f en scientifique = %s\n", a ,ft_to_science(a));
	a = 125543.10036;
	printf("%f en scientifique = %s\n", a ,ft_to_science(a));
	a = 98.3;
	printf("%f en scientifique = %s\n", a ,ft_to_science(a));
	a = 7534.6658484;
	printf("%f en scientifique = %s\n", a ,ft_to_science(a));
}