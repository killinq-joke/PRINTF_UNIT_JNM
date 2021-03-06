/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trofidal <trofidal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 08:19:02 by trofidal          #+#    #+#             */
/*   Updated: 2021/03/11 06:44:42 by trofidal         ###   ########.fr       */
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
char    *ft_get_content(char *flags, char *convert, va_list args, int a);
char	*ft_get_int(char *flags, va_list args, char **parsed_flags, char *ret);
char    *ft_get_str(char *flags, va_list args); /* RETURN A CHAR * VALUE OF VA_ARG */
char    *ft_get_char(char *flags, va_list args);
char	*ft_get_float(char *flags, va_list args);
char	*ft_get_ptr(char *flags, va_list args, int type);
char	*ft_get_u(char *flags, va_list args);
char	*ft_get_e(char *flags, va_list args);
char	*ft_get_g(char *flags, va_list args);
char	*ft_get_n(char *flags, va_list args, int a);
char    *ft_get_percent(char *flags);
char	**ft_flags_parser(char *flags);
char	*ft_get_it_done(double nbr);
char    *ft_index(char *end, char *flags);
/*
**SIZE_T FUNCTIONS
*/
/*
**INT FUNCTIONS
*/
int     ft_printf(const char *str, ...);
int     ft_is_convert(char str);
int		ft_point_fetcher(char *flags);
int     ft_get_second_value(char *flags);
int     ft_get_first_value(char *flags);
int      ft_get_first_value(char *flags);
int      ft_get_second_value(char *flags);
/*
**T_LIST
*/

#endif
