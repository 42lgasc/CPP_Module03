/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:18:53 by lgasc             #+#    #+#             */
/*   Updated: 2024/10/16 21:06:57 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

#include <iostream> // cout, endl

#define COLOR "\x1B[31;1m"
#define FAINT "\x1B[31;2m"
#define RESET "\x1B[0m"


// Canonical Four

FragTrap::FragTrap	(void) : ClapTrap () {
	std::cout << FAINT "\\ FragTrap default-construction..." RESET << std::endl;
	name = "Wilde";
	hit_points		= c_hit_points;
	energy_points	= c_energy_points;
	attack_damage	= c_attack_damage;
}
FragTrap::FragTrap	(const FragTrap & s) : ClapTrap (s) {
	std::cout << FAINT "\\ FragTrap copy-construction from " << s.name
		<< "..." RESET << std::endl;
}
FragTrap	& FragTrap::operator = (const FragTrap & s) {
	std::cout << FAINT "/ FragTrap " << name << " copy-assignment from "
		<< s.name << "..." RESET << std::endl;
	ClapTrap::operator = (s);
	return *this;
}
FragTrap::~ FragTrap	(void) {
	std::cout << FAINT "/ FragTrap " << name << " destruction..." RESET
		<< std::endl;
}


// other Constructors

FragTrap::FragTrap	(const std::string & new_name) : ClapTrap (new_name) {
	std::cout << FAINT "\\ FragTrap construction with name " << new_name
		<< "..." RESET << std::endl;
	hit_points		= c_hit_points;
	energy_points	= c_energy_points;
	attack_damage	= c_attack_damage;
}


// Methods

void	FragTrap::attack(const std::string & target) {
	if (hit_points <= 0 or energy_points <= 0) return ;
	std::cout << COLOR "/ FragTrap " << name << " attacks " << target
		<< ", causing " << attack_damage << " point"
		<< & "s" [attack_damage <= 1] << " of damage!\n" RESET;
	ClapTrap::attack(target);
}
void	FragTrap::takeDamage(const unsigned amount) {
	std::cout << COLOR "/ FragTrap " << name << " receives " << amount
		<< " point" << & "s" [amount <= 1] << " of damage!\n" RESET;
	ClapTrap::takeDamage(amount);
}
void	FragTrap::beRepaired(const unsigned amount) {
	if (hit_points <= 0 or energy_points <= 0) return ;
	std::cout << COLOR "/ FragTrap " << name << " recovers " << amount
		<< " hit point" << & "s" [amount <= 1] << "!\n" RESET;
	ClapTrap::beRepaired(amount);
}

void	FragTrap::highFivesGuys(void) const
{ std::cout << COLOR "FragTrap " << name << " wants an High Five!\n" RESET; }
