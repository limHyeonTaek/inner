/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hylim <hylim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:20:46 by hylim             #+#    #+#             */
/*   Updated: 2024/10/24 17:59:31 by hylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_c(va_list *ap)
{
	char	a;

	a = va_arg(*ap, int);
	return (write(1, &a, 1));
}

int	print_s(va_list *ap)
{
	char	*a;

	a = va_arg(*ap, char *);
	if (!a)
		return (write(1, "(null)", 6));
	return (write(1, a, ft_strlen(a)));
}

int	print_p(va_list *ap)
{
	unsigned char		*a;
	int					i;
	unsigned long long	tmp;
	char				pt[17];

	a = va_arg(*ap, void *);
	if (!a)
		return (write(1, "(nil)", 5));
	tmp = (unsigned long long)a;
	i = 16;
	pt[i] = '\0';
	while (i--)
	{
		pt[i] = "0123456789abcdef"[tmp % 16];
		tmp /= 16;
	}
	while (pt[++i] == '0')
		i++;
	if (write(1, "0x", 2) < 0)
		return (-1);
	if (write(1, pt + i, 16 - i) < 0)
		return (-1);
	if (i == 16)
		return (2 + write(1, "0", 1));
	return (2 + 16 - i);
}

int	print_percent(va_list *ap)
{
	(void)ap;
	return (write(1, "%%", 1));
}
