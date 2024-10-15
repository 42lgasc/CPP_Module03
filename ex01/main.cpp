/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:39:38 by lgasc             #+#    #+#             */
/*   Updated: 2024/10/15 19:49:35 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void) {
	ClapTrap	a ("Khutt");
	ClapTrap 	b ("K'lipp");
	ClapTrap	c (b);

	c.attack("innocents");
	c.takeDamage(8);
	a = c;
	a.beRepaired(6);


	ScavTrap	m ("Worzh");
	ScavTrap	n ("Wan Durr");
	ScavTrap	o (m);

	m.attack("creatures");
	n.guardGate();
	m.takeDamage(37);
	n = m;
	n.beRepaired(28);
}
