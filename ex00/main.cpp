/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:39:38 by lgasc             #+#    #+#             */
/*   Updated: 2024/10/15 18:03:12 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void) {
	ClapTrap	a ("Khutt");
	ClapTrap 	b ("K'lipp");
	ClapTrap	c (b);

	c.attack("innocents");
	c.takeDamage(8);
	a = c;
	a.beRepaired(6);
}
