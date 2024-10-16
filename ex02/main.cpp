/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:39:38 by lgasc             #+#    #+#             */
/*   Updated: 2024/10/16 16:18:34 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void) {
	ClapTrap	a ("Khutt");
	ClapTrap 	b ("K'lipp");
	ClapTrap	c (b);

	c.attack("innocents");
	c.takeDamage(8);
	a = c;
	a.beRepaired(6);


	FragTrap	m ("Zohner");
	FragTrap	n ("Zlyde");
	FragTrap	o (m);

	m.attack("targets");
	n.highFivesGuys();
	m.takeDamage(54);
	n = m;
	n.beRepaired(17);
}
