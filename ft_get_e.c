/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_e.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trofidal <trofidal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 01:44:01 by trofidal          #+#    #+#             */
/*   Updated: 2021/03/12 10:18:56 by trofidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long int	ft_get_pow(long double nbr, int *is_pos)
{
	long long int			i;
	long long int			count;
	long long int			result;

	result = 1;
	count = 0;
	nbr < 0 ? nbr *= -1 : nbr;
	i = nbr;
	while (i > 0)
	{
		*is_pos = 1;
		i /= 10;
		count++;
	}
	nbr < 1 ? count++ : count;
	while (nbr < 1)
	{
		nbr *= 10;
		count++;
	}
	while (--count > 0)
		result = result * 10;
	if (nbr < 1)
		result = result / 10;
	return (result);
}

static	char			*ft_get_last(long long int pow, int is_pos)
{
	int		i;
	char	*str;
	char	*itoa;

	if (!(str = ft_calloc(sizeof(str), 4)))
		return (NULL);
	str[0] = 'e';
	if (is_pos == 0)
		str[1] = '-';
	else
		str[1] = '+';
	str[2] = '0';
	if (str[1] == '-')
		itoa = ft_long_itoa(pow / 10);
	else
		itoa = ft_long_itoa(pow);
	i = (int)ft_strlen(itoa) - 1;
	if (str[1] == '-')
		i = (int)ft_strlen(itoa);
	free(itoa);
	itoa = ft_itoa(i);
	if (i > 9)
	{
		str[2] = '1';
		str[3] = itoa[1] + (i % 10);
		printf("%d\n", itoa[1]);
	}
	else
		str[3] = '0' + i;
	free(itoa);
	return (str);
}

static	double			ft_get_round(double nbr)
{
	int	count;
	int	is_neg;

	count = 0;
	is_neg = 0;
	if (nbr < 0)
	{
		is_neg = 1;
		nbr = -nbr;
	}
	while (nbr < 10000000 && ++count)
		nbr *= 10;
	if ((int)nbr % 10 >= 5)
	{
		nbr = (nbr / 10) + 1;
	}
	while (count > 0 && count--)
		nbr /= 10;
	is_neg == 1 ? nbr = -nbr : nbr;
	return (nbr);
}

char					*ft_get_it_done(double nbr)
{
	char			*end;
	char			*final;
	long long int	pow;
	int				is_pos;

	is_pos = 0;
	pow = ft_get_pow(nbr, &is_pos);
	end = ft_get_last(pow, is_pos);
	nbr = ft_get_round(nbr);
	if (is_pos == 1)
		nbr = nbr / pow;
	else
		nbr = nbr * pow;
	if (nbr < 1 && nbr > -1)
		final = ft_putnbr_float(nbr * 10);
	else
		final = ft_putnbr_float(nbr);
	final = ft_strcat(final, end);
	free(end);
	return (final);
}

char					*ft_get_e(char *flags, va_list args)
{
	char		*flt;
	double		va_arg;

	if (ft_strlen(flags) == 0)
	{
		va_arg = va_arg(args, double);
		flt = ft_get_it_done(va_arg);
		flt = ft_index(flt, flags);
		return (flt);
	}
	return (NULL);
}
