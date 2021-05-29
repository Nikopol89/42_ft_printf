/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_03.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 16:05:50 by jmartini          #+#    #+#             */
/*   Updated: 2021/03/23 16:05:52 by jmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conv_x(t_struct *fl, va_list args)
{
	int						len;
	int						nlen;
	unsigned long int		n;

	n = va_arg(args, unsigned int);
	nlen = ft_nbrlen_hex(n);
	len = nlen;
	if (fl->zero && fl->prc < 0 && fl->width < 0)
		fl->prc = fl->zero;
	if (fl->zero > fl->width)
		fl->width = fl->zero;
	if (!ft_exist_write(n, len, fl))
		return ;
	if ((fl->prc -= nlen) > 0)
		len = fl->prc + nlen;
	if (!fl->pad)
		ft_width_write(fl, len);
	ft_precision_write(fl);
	ft_putnbr_hex(n);
	fl->cnt += nlen;
	if (fl->pad)
		ft_width_write(fl, len);
}

void	ft_conv_upx(t_struct *fl, va_list args)
{
	int						len;
	int						nlen;
	unsigned long int		n;

	n = va_arg(args, unsigned int);
	nlen = ft_nbrlen_hex(n);
	len = nlen;
	if (fl->zero && fl->prc < 0 && fl->width < 0)
		fl->prc = fl->zero;
	if (fl->zero > fl->width)
		fl->width = fl->zero;
	if (!ft_exist_write(n, len, fl))
		return ;
	if ((fl->prc -= nlen) > 0)
		len = fl->prc + nlen;
	if (!fl->pad)
		ft_width_write(fl, len);
	ft_precision_write(fl);
	ft_putnbr_hex_up(n);
	fl->cnt += nlen;
	if (fl->pad)
		ft_width_write(fl, len);
}

void	ft_conv_n(t_struct *fl, va_list args)
{
	int	*n;

	n = va_arg(args, int *);
	*n = fl->cnt;
}
