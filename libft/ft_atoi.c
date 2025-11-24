/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:37:07 by yyaniv            #+#    #+#             */
/*   Updated: 2025/11/18 11:37:07 by yyaniv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_result(int n, int sign)
{
	if (sign == 0)
		return (n);
	else
		return (n * sign);
}

int	ft_atoi(const char *nptr)
{
	int				sign;
	int				result;
	unsigned int	index;

	index = 0;
	sign = 0;
	result = 0;
	while ((nptr[index] > 8 && nptr[index] <= 13) || nptr[index] == 32)
		index++;
	while ((nptr[index] == 43 || nptr[index] == 45) && (sign == 0))
	{
		if (nptr[index] == 45)
			sign = -1;
		else if (nptr[index] == 43)
			sign = 1;
		index++;
	}
	while (nptr[index] >= 48 && nptr[index] <= 57)
	{
		result = result * 10 + (nptr[index] - '0');
		index++;
	}
	return (ft_result(result, sign));
}
