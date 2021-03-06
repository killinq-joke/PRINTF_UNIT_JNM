/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trofidal <trofidal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 08:20:39 by trofidal          #+#    #+#             */
/*   Updated: 2021/03/06 18:00:48 by trofidal         ###   ########.fr       */
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

static char		*ft_get_flags(char *str, char *final_flags, va_list args)
{
	int i;
	int j;
	int len;
	char *flags;

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
	final_flags = ft_star_value(flags, args);
	free(flags);
	return (final_flags);
}

void	ft_free_main(char *temp, char *convert, char *flags, char *content)
{
	free (temp);
	free (convert);
	free (flags);
	free (content);
}

int     ft_printf(const char *str, ...)
{
    int i;
    va_list args;
    static char *final = NULL; 
    static char *flags; /* 5.4 */
	static char *convert;  /* %s %d */  
    static char *content; /* toto, 18 */
	char		*temp;
	char		*next_char;
    
    i = 0;
    va_start(args, str);
	if (!(final = (char *)ft_calloc(sizeof(final), 1)))
		return (0);
    while (str[i])
    {
        if (str[i] == '%')
        {
            flags = ft_get_flags((char *)str + i, flags, args);
			convert = ft_get_convert((char *)str + i, convert);
			content = ft_get_content(flags, convert, args);
			i+= ft_strlen(flags) + ft_strlen(convert);
			temp = final;
			final = ft_strjoin(temp, content);
			ft_free_main(temp, convert, flags, content);
		}
		else
		{
			temp = final;
			final = ft_stradd_char(temp, str[i]);
			free (temp);
			i++;
		}
    }
	ft_putstr_fd(final, 1);
	free (final);
	va_end(args);
    return (i);
}

int main()
{
	ft_printf("%darar%d", 12655647, 216599);
}