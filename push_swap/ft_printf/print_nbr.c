/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hylim <hylim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:36:42 by hylim             #+#    #+#             */
/*   Updated: 2024/10/24 18:00:21 by hylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_nbr(long long a)
{
	int			i;
	long long	tmp;
	char		pt[11];

	i = 0;
	tmp = a;
	while (i++ < 11)
	{
		if (tmp < 10)
			break ;
		tmp /= 10;
	}
	pt[i] = '\0';
	while (--i >= 0)
	{
		pt[i] = "0123456789"[a % 10];
		a /= 10;
	}
	return (write(1, pt, ft_strlen(pt)));
}

int	print_i_and_d(va_list *ap)
{
	long long	a;
	int			sign;

	a = va_arg(*ap, int);
	sign = 0;
	if (a < 0)
	{
		sign = 1;
		a *= -1;
		write(1, "-", 1);
	}
	return (print_nbr(a) + sign);
}

int	print_u(va_list *ap)
{
	unsigned int	a;

	a = va_arg(*ap, unsigned int);
	return (print_nbr((long long)a));
}
