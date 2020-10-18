/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltostr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 11:17:12 by awafflar          #+#    #+#             */
/*   Updated: 2019/10/31 11:17:17 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_ulltostr(unsigned long long n)
{
	static char		buff[21];
	char			*ret;

	ret = buff + 20;
	*ret = '\0';
	if (n == 0)
		*--ret = '0';
	while (n)
	{
		*--ret = (char)('0' + n % 10);
		n /= 10;
	}
	return (ret);
}
