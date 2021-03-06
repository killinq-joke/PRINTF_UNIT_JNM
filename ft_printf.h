/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trofidal <trofidal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 08:19:02 by trofidal          #+#    #+#             */
/*   Updated: 2021/03/06 21:13:44 by trofidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PRINTF_H
# define PRINTF_H

# include "libft/libft.h"
# define BUFF_SIZE 32



/*
**VOID FUNCTIONS
*/

/*
**CHAR FUNCTIONS
*/ 
char	*ft_star_value(char *str, va_list args);
char	*ft_get_content(char *flags, char *convert, va_list args);
char	*ft_get_int(char *flags, va_list args);
char    *ft_get_str(char *flags, va_list args); /* RETURN A CHAR * VALUE OF VA_ARG */
/*
**SIZE_T FUNCTIONS
*/

/*
**INT FUNCTIONS
*/
int     ft_printf(const char *str, ...);
int     ft_is_convert(char str);

/*
**T_LIST
*/

#endif
