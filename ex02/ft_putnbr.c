/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <thomasdelan2@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:43:03 by truello           #+#    #+#             */
/*   Updated: 2023/08/31 15:59:22 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	to_write;

	if (nb < 0)
	{
		if (nb == -2147483648)
		{
			write(1, "-2147483648", 11);
			return ;
		}
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb >= 0 && nb <= 9)
	{
		to_write = '0' + nb;
		write(1, &to_write, 1);
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}
//int	main(void)
//{
//	ft_putnbr(42);
//	write(1, "\n", 1);
//	ft_putnbr(5439842);
//	write(1, "\n", 1);
//	ft_putnbr(0);
//	write(1, "\n", 1);
//	ft_putnbr(-1);
//	write(1, "\n", 1);
//	ft_putnbr(-2147483648);
//	write(1, "\n", 1);
//	return (0);
//}
