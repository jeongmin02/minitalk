/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerhee <jerhee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 19:14:53 by jerhee            #+#    #+#             */
/*   Updated: 2023/03/04 19:27:13 by jerhee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>

void	ft_putnbr_fd(int n, int fd);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);

#endif