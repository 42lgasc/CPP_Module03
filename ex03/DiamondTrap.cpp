/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:18:53 by lgasc             #+#    #+#             */
/*   Updated: 2024/10/16 21:09:34 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

#include <iostream> // cout, endl

#define COLOR "\x1B[36;1m"
#define FAINT "\x1B[36;2m"
#define RESET "\x1B[0m"


// Constants

const std::string
DiamondTrap::c_name = "Dawnuht",	DiamondTrap::c_suffix = "_clap_name";


// Canonical Four

DiamondTrap::DiamondTrap	(void)
		: ClapTrap (c_name + c_suffix), ScavTrap (c_name + c_suffix),
		FragTrap (c_name + c_suffix), name (c_name) {
	std::cout << FAINT " \\ DiamondTrap default-construction..." RESET
		<< std::endl;
	hit_points		= c_hit_points;
	energy_points	= c_energy_points;
	attack_damage	= c_attack_damage;
}
DiamondTrap::DiamondTrap	(const DiamondTrap & s)
		: ClapTrap (s), ScavTrap (s), FragTrap (s), name (s.name) {
	std::cout << FAINT " \\ DiamondTrap copy-construction from " << s.name
		<< "..." RESET << std::endl;
}
DiamondTrap	& DiamondTrap::operator = (const DiamondTrap & s) {
	std::cout << FAINT "/ DiamondTrap " << name << " copy-assignment from "
		<< s.name << "..." RESET << std::endl;
	ClapTrap::operator = (s);
	return *this;
}
DiamondTrap::~ DiamondTrap	(void) {
	std::cout << FAINT " / DiamondTrap " << name << " destruction..." RESET
		<< std::endl;
}


// other Constructors

DiamondTrap::DiamondTrap	(const std::string & new_name)
		: ClapTrap (new_name + c_suffix), ScavTrap (new_name + c_suffix),
		FragTrap (new_name + c_suffix), name (new_name) {
	std::cout << FAINT " \\ DiamondTrap construction with name " << new_name
		<< "..." RESET << std::endl;
	hit_points		= c_hit_points;
	energy_points	= c_energy_points;
	attack_damage	= c_attack_damage;
}


// Methods

void	DiamondTrap::attack(const std::string & target) {
	if (hit_points <= 0 or energy_points <= 0) return ;
	std::cout << COLOR " / DiamondTrap " << name << " attacks " << target
		<< ", causing " << attack_damage << " point"
		<< & "s" [attack_damage <= 1] << " of damage!\n" RESET;
	ScavTrap::attack(target);
}
void	DiamondTrap::takeDamage(const unsigned amount) {
	std::cout << COLOR " / DiamondTrap " << name << " receives " << amount
		<< " point" << & "s" [amount <= 1] << " of damage!\n" RESET;
	FragTrap::takeDamage(amount);
}
void	DiamondTrap::beRepaired(const unsigned amount) {
	if (hit_points <= 0 or energy_points <= 0) return ;
	std::cout << COLOR " / DiamondTrap " << name << " recovers " << amount
		<< " hit point" << & "s" [amount <= 1] << "!\n" RESET;
	ScavTrap::beRepaired(amount);
}

void	DiamondTrap::guardGate(void) const {
	std::cout << COLOR "/ DiamondTrap " << name
		<< " is now in Gate Keeper mode!\n" RESET;
	ScavTrap::guardGate();
}

void	DiamondTrap::highFivesGuys(void) const {
	std::cout << COLOR "/ DiamondTrap " << name
		<< " wants an High Five!\n" RESET;
	FragTrap::highFivesGuys();
}
