/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hylim <hylim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:37:07 by hylim             #+#    #+#             */
/*   Updated: 2024/10/24 21:01:00 by hylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	convert_hex(va_list *ap, char *base)
{
	unsigned int	a;
	unsigned int	tmp;
	int				i;
	char			pt[11];

	i = 0;
	a = va_arg(*ap, unsigned int);
	tmp = a;
	while (i++ < 11)
	{
		if (tmp < 16)
			break ;
		tmp /= 16;
	}
	pt[i] = '\0';
	while (--i >= 0)
	{
		pt[i] = base[a % 16];
		a /= 16;
	}
	return (write(1, pt, ft_strlen(pt)));
}

int	print_x(va_list *ap)
{
	return (convert_hex(ap, "0123456789abcdef"));
}

int	print_bigx(va_list *ap)
{
	return (convert_hex(ap, "0123456789ABCDEF"));
}
