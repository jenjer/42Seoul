/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:43:18 by youngski          #+#    #+#             */
/*   Updated: 2022/09/07 13:44:22 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

int	ft_strlen_(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	double_check(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (base[i + 1] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0' && base[j] != base[i])
		{
			j++;
		}
		if (base[i] == base[j])
			return (0);
		i++;
	}
	return (1);
}

void	print_things(long long nbr, char *base)
{
	int	i;

	i = 0;
	if (nbr < 0)
		print_things(-nbr, base);
	while (base[i] != '\0')
		i++;
	if (nbr >= i)
	{
		print_things(nbr / i, base);
		print_things(nbr % i, base);
	}
	else if (nbr > -1)
	{
		write (1, &base[nbr], 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	i;

	i = 0;
	if (ft_strlen_(base) < 2)
		return ;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return ;
		i++;
	}
	if (double_check(base) == 0)
		return ;
	if (nbr < 0)
	{
		write (1, "-", 1);
	}
	print_things((long long)nbr, base);
}
char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char *ret;
	int	befor_ret;
	int i;
	int j;
	j = 0;
	i = 0;
	
	if (base_check(base_from,i,j) == 0 || base_check(base_to, i ,j))
		return (NULL);
	befor_ret = ft_atoi_base(nbr, base_from);
	while (base_to[i])
		ret[i] = base_to[i++];
	
	ft_putnbr_base(befor_ret, ret);
	return ret;
}
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
		char* ex04;
	ex04 = ft_convert_base("  \t---10", "0123456789", "01");
	assert(strcmp(ex04, "-1010") == 0);

	ex04 = ft_convert_base("  \t---10", "0123456789", "-01");
	assert(ex04 == NULL);
	
	ex04 = ft_convert_base(NULL, "aba", NULL);
	assert(ex04 == NULL);


}