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
	if (!(convert = ft_calloc(sizeof(convert), 1)))
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

static char		*ft_get_flags(char *str, char *flags)
{
	int i;
	int j;
	int len;

	len = 0;
	j = 0;
	i = 0; 
	while (str[i] == '%')
		i++;
	while (str[i + len])
		len++;
	if (!(flags = ft_calloc(sizeof(flags), len++)))
		return (NULL);
	while (ft_is_convert(str[i]) == 0)
	{
		flags[j] = str[i];
		j++;
		i++;
	}
	flags[j] = '\0';
	return (flags);
}

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
            flags = ft_get_flags((char *)str + i, flags);
			convert = ft_get_convert((char *)str + i, convert);
			printf("%s\n", flags);
			printf("%s\n", convert);
		}
		
		/*else
			final[i] = str[i];*/
		//printf("%d\n", ft_increment(flags, convert));
		i+= ft_strlen(flags) + ft_strlen(convert);
		//printf("len %d\n", )
		if (str[i + 1] != '\0')
		{
			free (convert);
			free (flags);
		}
		
		
		
    }
	
    return (i);
}

int main()
{
	ft_printf("%1s%58s%15s", "je suis un str");
}