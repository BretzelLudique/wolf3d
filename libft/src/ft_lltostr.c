/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltostr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:25:01 by awafflar          #+#    #+#             */
/*   Updated: 2019/10/23 18:25:53 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_lltostr(long long n)
{
	static char		buff[21];
	char			*ret;

	ret = buff + 20;
	*ret = '\0';
	if (n == 0)
		*--ret = '0';
	else if (n < 0)
	{
		while (n)
		{
			*--ret = (char)('0' - (n % 10));
			n /= 10;
		}
		*--ret = '-';
	}
	else
		while (n)
		{
			*--ret = (char)('0' + n % 10);
			n /= 10;
		}
	return (ret);
}
