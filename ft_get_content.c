/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_content.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trofidal <trofidal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 16:23:15 by trofidal          #+#    #+#             */
/*   Updated: 2021/03/08 19:39:51 by trofidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *ft_get_content(char *flags, char *convert, va_list args, int a)
{
    char *ret;
    char **parsed_flags;
 
    parsed_flags = ft_flags_parser(flags);
    if (ft_strcmp(convert, "%d") == 0 || ft_strcmp(convert, "%i") == 0)
        ret = ft_get_int(flags, args, parsed_flags, NULL);
    else if (ft_strcmp(convert, "%s") == 0)
        ret = ft_get_str(flags, args);
    else if (ft_strcmp(convert, "%c") == 0)
        ret = ft_get_char(flags, args);
	else if (ft_strcmp(convert, "%f") == 0)
		ret = ft_get_float(flags, args);
    else if (ft_strcmp(convert, "%p") == 0)
        ret = ft_get_ptr(flags, args, 1);
    else if (ft_strcmp(convert, "%X") == 0)
    {
        ret = ft_get_ptr(flags, args, 0);
        ft_strlen(flags) > 0 ? ret = ft_get_int(flags, args, parsed_flags, ret) : 0; 
    }    
    else if (ft_strcmp(convert, "%x") == 0)
    {
        ret = ft_get_ptr(flags, args, 2); 
        printf("flag %s\n", ret);
        ft_strlen(flags) > 0 ? ret = ft_get_int(flags, args, parsed_flags, ret) : 0; 
    }    
    else if (ft_strcmp(convert, "%u") == 0)
    {
        ret = ft_get_u(flags, args);
        ft_strlen(flags) > 0 ? ret = ft_get_int(flags, args, parsed_flags, ret) : 0; 
    }
    else if (ft_strcmp(convert, "%e") == 0)
        ret = ft_get_e(flags, args); 
    else if (ft_strcmp(convert, "%n") == 0)
        ret = ft_get_n(flags, args, a);
    else if (ft_strcmp(convert, "%g") == 0)
        ret = ft_get_g(flags, args);
    else if (ft_charcmp(convert[0], '%') == 0)
        ret = ft_get_percent(flags);
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