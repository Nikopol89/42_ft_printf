/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 16:05:20 by jmartini          #+#    #+#             */
/*   Updated: 2021/03/23 16:05:23 by jmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_reset_flags(t_struct *fl)
{
	fl->pad = 0;
	fl->zero = 0;
	fl->width = -1;
	fl->prc = -1;
}

static char		*ft_check_flags(char *str, t_struct *fl, va_list args)
{
	while (*str == '0' || *str == '-')
	{
		if (*str == '0' && !fl->pad)
			str = ft_flag_zero(str, fl, args);
		if (*str == '-')
			str = ft_flag_pad(str, fl);
		if (*str == '0' && fl->pad)
			str++;
	}
	if (ft_isdigit(*str))
		str = ft_flag_width(str, fl);
	if (*str == '*')
		str = ft_flag_arg(str, fl, args);
	if (*str == '.')
		str = ft_flag_prc(str, fl, args);
	return (str);
}

static void		ft_check_conv(char *str, t_struct *fl, va_list args)
{
	if (*str == 'c')
		ft_conv_c(fl, args);
	if (*str == 's')
		ft_conv_s(fl, args);
	if (*str == 'p')
		ft_conv_p(fl, args);
	if (*str == 'd' || *str == 'i')
		ft_conv_d(fl, args);
	if (*str == 'u')
		ft_conv_u(fl, args);
	if (*str == 'x')
		ft_conv_x(fl, args);
	if (*str == 'X')
		ft_conv_upx(fl, args);
	if (*str == '%')
		ft_conv_perc(fl);
	if (*str == 'n')
		ft_conv_n(fl, args);
}

int				ft_printf(const char *str, ...)
{
	va_list		args;
	t_struct	fl;

	fl.cnt = 0;
	ft_reset_flags(&fl);
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			str = ft_check_flags((char *)str, &fl, args);
			ft_check_conv((char *)str, &fl, args);
		}
		else
		{
			ft_putchar(*str);
			fl.cnt++;
		}
		ft_reset_flags(&fl);
		str++;
	}
	va_end(args);
	return (fl.cnt);
}
