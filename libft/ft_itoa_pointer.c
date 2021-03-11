/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trofidal <trofidal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 15:57:26 by trofidal          #+#    #+#             */
/*   Updated: 2021/03/11 11:28:31 by trofidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_min(long long int i)
{
	long long int y;
	long long int a;

	a = 0;
	y = i - a;
	while (y > 8 && a > -15)
	{
		y = i + a;
		a--;
	}
	return (a);
}

static long long int	ft_lencheck(long long int n, char *base)
{
	long long int	nb;
	long long int	len;

	len = 0;
	nb = n;
	if (nb == 0)
		return (1);
	if (nb < 0)
		len++;
	while (nb != 0)
	{
		nb = nb / ft_strlen(base);
		len++;
	}
	return (len);
}

static char	*ft_iteration(char *str, long long int neg, long long int i, char *base)
{
	int y;

	y = ft_get_min(i);
	i += 2;
	while (i >= 2)
	{ 
		str[i + y] = base[neg % ft_strlen(base)]; 
		neg = neg / ft_strlen(base);
		i--; 
	}
	str[0] = '0';
	str[1] = 'x';  
	return (str);
} 

char		*ft_itoa_pointer(long long int n, char *base)
{
	long long int		i;
	long long int			nb;
	long long int	neg;
	char			*str;
	
	nb = (long long int)n;
	i = ft_lencheck(nb, base) - 1;
	if (!(str = ft_calloc(sizeof(str), i + 1)))
		return (NULL);
	if (nb == 0)
	{
		str[0] = '0';
		return (str);
	}
	neg = nb;
	if (n < 0)
	{
		str[0] = '-';
		nb = -nb;
		neg = 4294967296 - nb;
	}
	str = ft_iteration(str, neg, i, base); 
	return (str);
}