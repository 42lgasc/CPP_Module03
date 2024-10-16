/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:25:56 by lgasc             #+#    #+#             */
/*   Updated: 2024/10/16 21:06:39 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include <iostream> // cout, endl

#define COLOR "\x1B[32;1m"
#define FAINT "\x1B[32;2m"
#define RESET "\x1B[0m"


// Canonical Four

ClapTrap::ClapTrap	(void) : name ("Klozh"), hit_points (c_hit_points),
		energy_points (c_energy_points), attack_damage (c_attack_damage)
{ std::cout << FAINT "ClapTrap default-construction" RESET << std::endl; }
ClapTrap::ClapTrap	(const ClapTrap & c)
	: name (c.name), hit_points (c.hit_points),
	energy_points (c.energy_points), attack_damage (c.attack_damage) {
	std::cout << FAINT "ClapTrap copy-construction from " << c.name
		<< "..." RESET << std::endl;
}
ClapTrap	& ClapTrap::operator = (const ClapTrap & c) {
	std::cout << FAINT "ClapTrap " << name << " copy-assignment from " << c.name
		<< "..." RESET << std::endl;
	name			= c.name;
	hit_points		= c.hit_points;
	energy_points	= c.energy_points;
	attack_damage	= c.attack_damage;
	return *this;
}
ClapTrap::~ ClapTrap	(void) {
	std::cout << FAINT "ClapTrap " << name << " destruction..." RESET
		<< std::endl;
}


// other Constructors

ClapTrap::ClapTrap	(const std::string & new_name)
		: name (new_name), hit_points (c_hit_points),
		energy_points (c_energy_points), attack_damage (c_attack_damage) {
	std::cout << FAINT "ClapTrap construction with name " << new_name
		<< "..." RESET << std::endl;
}


// Methods

void	ClapTrap::attack(const std::string & target) {
	if (hit_points <= 0 or energy_points <= 0) return ;
	std::cout << COLOR "ClapTrap " << name << " attacks " << target
		<< ", causing " << attack_damage << " point"
		<< & "s" [attack_damage <= 1] << " of damage!\n" RESET;
	-- energy_points;
}

void	ClapTrap::takeDamage(const unsigned amount) {
	std::cout << COLOR "ClapTrap " << name << " receives " << amount
		<< " point" << & "s" [amount <= 1] << " of damage!\n" RESET;
	if (amount >= hit_points) { hit_points = 0; return ; }
	hit_points -= amount;
}

void	ClapTrap::beRepaired(const unsigned amount) {
	if (hit_points <= 0 or energy_points <= 0) return ;
	std::cout << COLOR "ClapTrap " << name << " recovers " << amount
		<< " hit point" << & "s" [amount <= 1] << "!\n" RESET;
	-- energy_points;
	hit_points += amount;
}
