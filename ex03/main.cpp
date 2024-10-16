/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:39:38 by lgasc             #+#    #+#             */
/*   Updated: 2024/10/16 20:14:15 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void) {
	ClapTrap	a ("Khutt");
	ClapTrap 	b ("K'lipp");
	ClapTrap	c (b);

	c.attack("innocents");
	c.takeDamage(8);
	a = c;
	a.beRepaired(6);


	ScavTrap	g ("Worzh");
	ScavTrap	h ("Wan Durr");
	ScavTrap	i (g);

	g.attack("creatures");
	h.guardGate();
	g.takeDamage(37);
	h = g;
	h.beRepaired(28);


	FragTrap	m ("Zohner");
	FragTrap	n ("Zlyde");
	FragTrap	o (m);

	m.attack("targets");
	n.highFivesGuys();
	m.takeDamage(54);
	n = m;
	n.beRepaired(17);


	DiamondTrap	s ("Dhu Reean");
	DiamondTrap	t ("Da'ndely-Hon");
	DiamondTrap	u (s);

	s.attack("hearts");
	t.guardGate();
	u.highFivesGuys();
	s.takeDamage(63);
	t = u = s;
	t.beRepaired(25);
}
