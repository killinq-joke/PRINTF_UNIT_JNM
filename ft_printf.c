/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trofidal <trofidal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 08:20:39 by trofidal          #+#    #+#             */
/*   Updated: 2021/03/06 14:13:16 by trofidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_get_convert(char *str, char *convert)
{
	int i;

	i = 1;
	if (!(convert = ft_calloc(sizeof(convert), 3)))
		return (NULL);
	convert[0] = '%';
	while (str[i])
	{
		if (ft_is_convert(str[i]) == 1)
		{
			convert[1] = str[i];
			return (convert);
		}
		i++;
	}
	return (convert);
}
/*
static int		ft_increment(char *flags, char *convert)
{
	int i;

	i = ft_strlen(flags) + ft_strlen(convert);
	return (i);
}*/

void			ft_free_static(char *flags, char *convert, char *content, char *final)
{/*
	if (ft_strlen(content) > 0)
		free(flags);
		
	if (ft_strlen(flags) > 0)
		free(flags);*/
	if (ft_strlen(convert) > 0)
		free(flags);/*
	if (ft_strlen(final) > 0)
		free(flags);*/
}

int     ft_printf(const char *str, ...)
{
    int i;
    va_list args;
    static char *final;
    static char *flags;
	static char *convert;
    static char *content;
    
    i = 0;
    va_start(args, str);
    while (str[i])
    {
        if (str[i] == '%')
        {
            //flags = ft_get_flags(str + i);
			convert = ft_get_convert((char *)str + i, convert);
			//printf("%s\n", flags);
		}
		//free(convert);
		/*else
			final[i] = str[i];*/
		//printf("%d\n", ft_increment(flags, convert));
		i++;
    }
    return (i);
}

int main()
{
	ft_printf("%s%s%s", "je suis un str");
}