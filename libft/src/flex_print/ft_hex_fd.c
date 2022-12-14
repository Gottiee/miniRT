/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:59:12 by gmansuy           #+#    #+#             */
/*   Updated: 2022/11/25 18:59:14 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*pf_itoa_base(int fd, unsigned long long int n, char *base)
{
	unsigned long long int	base_len;
	int						n_len;
	char					*str;

	base_len = pf_strlen(base);
	n_len = pf_nblen(n, base_len);
	str = malloc((n_len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[n_len] = 0;
	while (n_len - 1 >= 0)
	{
		str[n_len - 1] = base[n % base_len];
		n /= base_len;
		n_len--;
	}
	write(fd, str, pf_strlen(str));
	return (str);
}

int	pf_putnbr_hex(int fd, va_list ap, int i)
{
	unsigned int	n;
	int				n_len;
	char			*base;
	char			*str;

	n_len = 0;
	n = va_arg(ap, unsigned int);
	if (n == 0 && i > 10)
		return (0);
	if (i % 10 == 6)
		base = "0123456789abcdef";
	if (n != 0 && i == 16)
		n_len += write (1, "x", 1);
	if (i % 10 == 7)
		base = "0123456789ABCDEF";
	if (n != 0 && i == 17)
		n_len += write (1, "X", 1);
	str = pf_itoa_base(fd, n, base);
	n_len += pf_strlen(str);
	free(str);
	return (n_len);
}

int	pf_point(int fd, va_list ap, int i)
{
	unsigned long long int	n;
	int						n_len;
	char					*str;

	if (i == 2)
		n = va_arg(ap, unsigned long long int);
	if (n == 0)
		return (write(fd, "(nil)", 5));
	write(fd, "0x", 2);
	str = pf_itoa_base(fd, n, "0123456789abcdef");
	n_len = pf_strlen(str);
	free(str);
	return (2 + n_len);
}
