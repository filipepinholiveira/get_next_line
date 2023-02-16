/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:38:11 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/02/16 17:12:59 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str_final;
	int		i;
	int		j;

	j = 0;
	i = -1;
	if (!s1)
	{
		s1 = (char *) malloc (1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str_final = (char *)malloc(ft_strlen((char *)s1)
			+ ft_strlen((char *)s2) + 1 * sizeof(char));
	if (!str_final)
		return (NULL);
	if (s1)
		while (s1[++i] != '\0')
			str_final[i] = s1[i];
	while (s2[j] != '\0')
		str_final[i++] = s2[j++];
	str_final[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free (s1);
	return (str_final);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}
