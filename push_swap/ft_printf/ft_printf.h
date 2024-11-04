/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hylim <hylim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:26:09 by hylim             #+#    #+#             */
/*   Updated: 2024/10/28 17:55:48 by hylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

int	print_c(va_list *ap);
int	print_s(va_list *ap);
int	print_p(va_list *ap);
int	print_i_and_d(va_list *ap);
int	print_u(va_list *ap);
int	print_x(va_list *ap);
int	print_bigx(va_list *ap);
int	print_percent(va_list *ap);
int	ft_printf(const char *format, ...);

#endif