/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hylim <hylim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 22:24:40 by hylim             #+#    #+#             */
/*   Updated: 2024/10/24 21:00:59 by hylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_f(int (*f[256])(va_list *ap), char *val_f)
{
	ft_memset(f, 0, 256);
	f['c'] = print_c;
	f['s'] = print_s;
	f['p'] = print_p;
	f['d'] = print_i_and_d;
	f['i'] = print_i_and_d;
	f['u'] = print_u;
	f['x'] = print_x;
	f['X'] = print_bigx;
	f['%'] = print_percent;
	val_f['c'] = 1;
	val_f['s'] = 1;
	val_f['p'] = 1;
	val_f['d'] = 1;
	val_f['i'] = 1;
	val_f['u'] = 1;
	val_f['x'] = 1;
	val_f['X'] = 1;
	val_f['%'] = 1;
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	size_t		re_cnt;
	int			(*f[256])(va_list *ap);
	char		val_f[256];
	long long	cnt;

	ft_memset(val_f, 0, 256);
	ft_f(f, val_f);
	va_start(ap, format);
	re_cnt = 0;
	while (*format)
	{
		if ((unsigned char)(*format) == '%'
			&& val_f[(unsigned char)(*(++format))])
			cnt = f[(unsigned char)(*format++)](&ap);
		else
			cnt = write(1, format++, 1);
		if (cnt < 0 || re_cnt > 2147483647)
			break ;
		re_cnt += cnt;
	}
	va_end(ap);
	if (cnt < 0 || re_cnt > 2147483647)
		return (-1);
	return ((int)re_cnt);
}

/* 
#include <stdio.h>

int	main(void)
{
	char			*str2;
	char			*str;
	int				num;
	unsigned int	un;
	int				mn;
	int				n;

	str2 = NULL;
	str = "Hello, World!";
	un = 4294967295;
	mn = -2147483648;
	n = 2147483647;
	write(1, "ft_printf : ", 12);
	num = ft_printf("%%%%%%");
	ft_printf("\nft_printf num : %d\n\n", num);
	num = ft_printf("s(null) : %s\n", str2);
	ft_printf("ft_printf num : %d\n\n", num);
	num = ft_printf("p(null) : %p\n", NULL);
	ft_printf("ft_printf num : %d\n\n", num);
	num = ft_printf("c : %c\n", '2');
	ft_printf("ft_printf num : %d\n\n", num);
	num = ft_printf("s(str) :%s\n", str);
	ft_printf("ft_printf num : %d\n\n", num);
	num = ft_printf("p(str) : %p\n", str);
	ft_printf("ft_printf num : %d\n\n", num);
	num = ft_printf("d : %d\n", n);
	ft_printf("ft_printf num : %d\n\n", num);
	num = ft_printf("-d : %d\n", mn);
	ft_printf("ft_printf num : %d\n\n", num);
	num = ft_printf("i : %i\n", mn);
	ft_printf("ft_printf num : %d\n\n", num);
	num = ft_printf("u : %u\n", un);
	ft_printf("ft_printf num : %d\n\n", num);
	num = ft_printf("x : %x\n", 19);
	ft_printf("ft_printf num : %d\n\n", num);
	num = ft_printf("X : %X\n", 19);
	ft_printf("ft_printf num : %d\n\n", num);
	ft_printf("---------------------------------------------------");
	printf("\n\nprintf : ");
	num = printf("%%%%%%");
	printf("\nprintf num : %d\n\n", num);
	num = printf("s(null) : %s\n", str2);
	printf("printf num : %d\n\n", num);
	num = printf("p(null) : %p\n", NULL);
	printf("printf num : %d\n\n", num);
	num = printf("c : %c\n", '2');
	printf("printf num : %d\n\n", num);
	num = printf("s(str) :%s\n", str);
	printf("printf num : %d\n\n", num);
	num = printf("p(str) : %p\n", str);
	printf("printf num : %d\n\n", num);
	num = printf("d : %d\n", n);
	printf("printf num : %d\n\n", num);
	num = printf("-d : %d\n", mn);
	printf("printf num : %d\n\n", num);
	num = printf("i : %i\n", mn);
	printf("printf num : %d\n\n", num);
	num = printf("u : %u\n", un);
	printf("printf num : %d\n\n", num);
	num = printf("x : %x\n", 19);
	printf("printf num : %d\n\n", num);
	num = printf("X : %X\n", 19);
	printf("printf num : %d\n\n", num);
	printf("---------------------------------------------------\n");
	return (0);
}
 */