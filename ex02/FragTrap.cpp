/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:18:53 by lgasc             #+#    #+#             */
/*   Updated: 2024/10/16 16:19:53 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

#include <iostream> // cout, endl

#define FAINT	"\x1B[2m"
#define REGULAR	"\x1B[22m"


// Canonical Four

FragTrap::FragTrap	(void) : ClapTrap () {
	std::cout << FAINT "FragTrap default-construction..." REGULAR << std::endl;
	name = "Wilde";
	hit_points		= c_hit_points;
	energy_points	= c_energy_points;
	attack_damage	= c_attack_damage;
}
FragTrap::FragTrap	(const FragTrap & s) : ClapTrap (s) {
	std::cout << FAINT "FragTrap copy-construction from " << s.name
		<< "..." REGULAR << std::endl;
}
FragTrap	& FragTrap::operator = (const FragTrap & s) {
	std::cout << FAINT "FragTrap " << name << " copy-assignment from " << s.name
		<< "..." REGULAR << std::endl;
	ClapTrap::operator = (s);
	return *this;
}
FragTrap::~ FragTrap	(void) {
	std::cout << FAINT "FragTrap " << name << " destruction..." REGULAR
		<< std::endl;
}


// other Constructors

FragTrap::FragTrap	(const std::string & name) : ClapTrap (name) {
	std::cout << FAINT "FragTrap construction with name " << name
		<< "..." REGULAR << std::endl;
	hit_points		= c_hit_points;
	energy_points	= c_energy_points;
	attack_damage	= c_attack_damage;
}


// Methods

void	FragTrap::attack(const std::string & target) {
	if (hit_points <= 0 or energy_points <= 0) return ;
	std::cout << "FragTrap " << name << " attacks " << target << ", causing "
		<< attack_damage << " point" << & "s" [attack_damage <= 1]
		<< " of damage!\n";
	ClapTrap::attack(target);
}
void	FragTrap::takeDamage(const unsigned amount) {
	std::cout << "FragTrap " << name << " receives " << amount << " point"
		<< & "s" [amount <= 1] << " of damage!\n";
	ClapTrap::takeDamage(amount);
}
void	FragTrap::beRepaired(const unsigned amount) {
	if (hit_points <= 0 or energy_points <= 0) return ;
	std::cout << "FragTrap " << name << " recovers " << amount << " hit point"
		<< & "s" [amount <= 1] << "!\n";
	ClapTrap::beRepaired(amount);
}

void	FragTrap::highFivesGuys(void) const
{ std::cout << "FragTrap " << name << " wants an High Five!\n"; }
