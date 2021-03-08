/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_e.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trofidal <trofidal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 01:44:01 by trofidal          #+#    #+#             */
/*   Updated: 2021/03/08 08:43:28 by trofidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long int	ft_get_pow(long double nbr)
{
	long long int i;
	long long int count;
	long long int result;

	result = 1;
	count = 0;
	i = nbr;
	while (i > 0)
	{
		i /= 10;
		count++;
	}
	while (--count > 0)
		result = result * 10;
	return (result);
}

static char		*ft_get_last(long long int pow)
{
	int i;
	char *str;
	char *itoa;

	i = 1;
	if (!(str = ft_calloc(sizeof(str), 4)))
		return (NULL);
	str[0] = 'e';
	str[1] = '+';
	str[2] = '0';
	itoa = ft_long_itoa(pow);
	while (itoa[i] == '0')
		i++;
	free(itoa);
	itoa = ft_itoa(i);
	if (i > 9)
	{
		str[2] = '1';
		str[3] = itoa[1] - 1;
	}
	else
		str[3] = '0' + i - 1;
	free (itoa);
	return (str);
}

static char			*ft_get_it_done(double nbr)
{
	char 	*end;
	char	*final;
	long long int 	pow;

	pow = ft_get_pow(nbr);
	end = ft_get_last(pow);
	final = ft_putnbr_float((nbr / pow) + 0.0000001);
	final = ft_strcat(final, end);
	free (end);
	return (final);
}

char	*ft_get_e(char *flags, va_list args)
{
	char *flt;
	double va_arg;

	if (ft_strlen(flags) == 0)
	{
		va_arg = va_arg(args, double);
		flt = ft_get_it_done(va_arg);
		return (flt);
	}
	return (NULL);
}