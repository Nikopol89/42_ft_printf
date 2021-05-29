/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_01.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 16:05:39 by jmartini          #+#    #+#             */
/*   Updated: 2021/03/23 16:05:41 by jmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_conv_c(t_struct *fl, va_list args)
{
	int			len;

	len = 1;
	fl->cnt += len;
	if (!fl->pad)
		ft_width_write(fl, len);
	ft_zero_write(fl, len);
	ft_putchar(va_arg(args, int));
	if (fl->pad)
		ft_width_write(fl, len);
}

void		ft_conv_s(t_struct *fl, va_list args)
{
	int			len;
	char		*tmp;

	if (!(tmp = va_arg(args, char *)))
		tmp = "(null)";
	if (fl->prc > -1 && fl->prc < (int)ft_strlen(tmp))
		len = fl->prc;
	else
		len = ft_strlen(tmp);
	if (!fl->pad)
		ft_width_write(fl, len);
	ft_putstrlen(tmp, len);
	fl->cnt += len;
	if (fl->pad)
		ft_width_write(fl, len);
}

void		ft_conv_p(t_struct *fl, va_list args)
{
	int						len;
	unsigned long long int	n;

	n = va_arg(args, unsigned long long int);
	len = ft_nbrlen_hex_addr(n) + 2;
	if (!fl->pad)
		ft_width_write(fl, len);
	ft_putstr("0x");
	ft_putnbr_hex_addr(n);
	fl->cnt += len;
	if (fl->pad)
		ft_width_write(fl, len);
}

void		ft_conv_perc(t_struct *fl)
{
	int			len;

	len = 1;
	fl->cnt += len;
	if (!fl->pad)
		ft_width_write(fl, len);
	ft_zero_write(fl, len);
	ft_putchar('%');
	if (fl->pad)
		ft_width_write(fl, len);
}
