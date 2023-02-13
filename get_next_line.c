/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:34:36 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/02/13 19:16:47 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ler_ficheiro_e_printar_str(int fd, char *str_toda)
{
	char	*str;
	int		char_lidos;

	str = malloc (BUFFER_SIZE + 1 * sizeof(char));
	if (!str)
		return (NULL);
	char_lidos = 1;
	while (!ft_strchr(str, '\n') && char_lidos != 0)
	{
		char_lidos = read(fd, str, BUFFER_SIZE);
		if (char_lidos == -1)
		{
			free (str);
			return (NULL);
		}
		str[char_lidos] = '\0';
		str_toda = ft_strjoin(str_toda, str);
	}
	free (str);
	return (str_toda);
}

char	*passar_total_para_parcial(char *str_toda)
{
	char	*str_parcial;
	size_t	i;

	i = 0;
	if (!str_toda[i])
		return (NULL);
	while (str_toda[i] && str_toda[i] != '\n')
		i++;
	str_parcial = (char *)malloc(i + 2 * sizeof(char));
	if (!str_parcial)
		return (NULL);
	i = 0;
	while (str_toda[i] && str_toda[i] != '\n')
	{
		str_parcial[i] = str_toda[i];
		i++;
	}
	if (str_toda[i] == '\n')
	{
		str_parcial[i] = str_toda[i];
		i++;
	}
	str_parcial[i] = '\0';
	return (str_parcial);
}

char	*printar_nova_linha(char *str_antiga)
{
	char	*str_nova;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str_antiga[i] && str_antiga[i] != '\n')
		i++;
	if (!str_antiga[i])
	{
		free (str_antiga);
		return (NULL);
	}
	str_nova = (char *) malloc (sizeof(char) * (ft_strlen(str_antiga) - i + 1));
	if (!str_nova)
		return (NULL);
	i++;
	while (str_antiga[i])
		str_nova[j++] = str_antiga[i++];
	str_nova[j] = '\0';
	free (str_antiga);
	return (str_nova);
}

char	*get_next_line(int fd)
{
	static char	*str_toda;
	char		*str_parcial;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str_toda = ler_ficheiro_e_printar_str(fd, str_toda);
	if (!str_toda)
		return (NULL);
	str_parcial = passar_total_para_parcial(str_toda);
	str_toda = printar_nova_linha(str_toda);
	return (str_parcial);
}

int main()
{
	int fd;
	size_t lines;

	fd = open ("test.txt", O_RDONLY);
	lines = 4;
	while (lines -- != 0)
	printf("%s", get_next_line(fd));
}
