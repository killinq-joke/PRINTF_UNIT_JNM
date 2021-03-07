/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_content.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trofidal <trofidal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 16:23:15 by trofidal          #+#    #+#             */
/*   Updated: 2021/03/07 17:00:15 by trofidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *ft_get_content(char *flags, char *convert, va_list args)
{
    char *ret;
    char **parsed_flags;
 
    parsed_flags = ft_flags_parser(flags);
 
    if (ft_strcmp(convert, "%d") == 0 || ft_strcmp(convert, "%i") == 0)
        ret = ft_get_int(flags, args, parsed_flags);
    else if (ft_strcmp(convert, "%s") == 0)
        ret = ft_get_str(flags, args);
    else if (ft_strcmp(convert, "%c") == 0)
        ret = ft_get_char(flags, args);
	else if (ft_strcmp(convert, "%f") == 0)
		ret = ft_get_float(flags, args);
    else if (ft_strcmp(convert, "%p") == 0 || ft_strcmp(convert, "%x") == 0)
        ret = ft_get_ptr(flags, args, 1); /* 0 = ABCDEF, 1 = abcdef, 2*/
    else if (ft_strcmp(convert, "%X") == 0)
        ret = ft_get_ptr(flags, args, 0); /* 0 = ABCDEF, 1 = abcdef, 2*/
    else if (ft_strcmp(convert, "%u") == 0)
        ret = ft_get_u(flags, args);
    int i = 0;
    while (parsed_flags[i] != 0)
    {
        free(parsed_flags[i]);
        i++;
    }
    free(parsed_flags[i]);
    free (parsed_flags);
    return (ret);
}

/*
* x / p = 0123456789abcdef - type = 1
* X = 0123456789ABCDEF - type = 1
*/