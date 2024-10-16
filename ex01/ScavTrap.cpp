/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:18:53 by lgasc             #+#    #+#             */
/*   Updated: 2024/10/16 21:07:02 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#include <iostream> // cout, endl

#define COLOR "\x1B[33;1m"
#define FAINT "\x1B[33;2m"
#define RESET "\x1B[0m"


// Canonical Four

ScavTrap::ScavTrap	(void) : ClapTrap () {
	std::cout << FAINT "\\ ScavTrap default-construction..." RESET << std::endl;
	name = "Wilde";
	hit_points		= c_hit_points;
	energy_points	= c_energy_points;
	attack_damage	= c_attack_damage;
}
ScavTrap::ScavTrap	(const ScavTrap & s) : ClapTrap (s) {
	std::cout << FAINT "\\ ScavTrap copy-construction from " << s.name
		<< "..." RESET << std::endl;
}
ScavTrap	& ScavTrap::operator = (const ScavTrap & s) {
	std::cout << FAINT "/ ScavTrap " << name << " copy-assignment from "
		<< s.name << "..." RESET << std::endl;
	ClapTrap::operator = (s);
	return *this;
}
ScavTrap::~ ScavTrap	(void) {
	std::cout << FAINT "/ ScavTrap " << name << " destruction..." RESET
		<< std::endl;
}


// other Constructors

ScavTrap::ScavTrap	(const std::string & new_name) : ClapTrap (new_name) {
	std::cout << FAINT "\\ ScavTrap construction with name " << new_name
		<< "..." RESET << std::endl;
	hit_points		= c_hit_points;
	energy_points	= c_energy_points;
	attack_damage	= c_attack_damage;
}


// Methods

void	ScavTrap::attack(const std::string & target) {
	if (hit_points <= 0 or energy_points <= 0) return ;
	std::cout << COLOR "/ ScavTrap " << name << " attacks " << target
		<< ", causing " << attack_damage << " point"
		<< & "s" [attack_damage <= 1] << " of damage!\n" RESET;
	ClapTrap::attack(target);
}
void	ScavTrap::takeDamage(const unsigned amount) {
	std::cout << COLOR "/ ScavTrap " << name << " receives " << amount
		<< " point" << & "s" [amount <= 1] << " of damage!\n" RESET;
	ClapTrap::takeDamage(amount);
}
void	ScavTrap::beRepaired(const unsigned amount) {
	if (hit_points <= 0 or energy_points <= 0) return ;
	std::cout << COLOR "/ ScavTrap " << name << " recovers " << amount
		<< " hit point" << & "s" [amount <= 1] << "!\n" RESET;
	ClapTrap::beRepaired(amount);
}

void	ScavTrap::guardGate(void) const {
	std::cout << COLOR "ScavTrap " << name
		<< " is now in Gate Keeper mode!\n" RESET;
}
