/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:11:06 by lgasc             #+#    #+#             */
/*   Updated: 2024/10/16 19:59:26 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMOND_TRAP_HPP
# define DIAMOND_TRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
	static const unsigned	c_hit_points	= FragTrap::c_hit_points,
							c_energy_points	= ScavTrap::c_energy_points,
							c_attack_damage	= FragTrap::c_attack_damage;
	static const std::string	c_name,	c_suffix;

	std::string	name;

	DiamondTrap	(void);
public:
	DiamondTrap	(const DiamondTrap &);
	DiamondTrap	& operator = (const DiamondTrap &);
	~ DiamondTrap	(void);

	DiamondTrap	(const std::string & name);

	void	attack(const std::string & target);
	void	takeDamage(unsigned amount);
	void	beRepaired(unsigned amount);
	void	guardGate(void) const;
	void	highFivesGuys(void) const;
};
#endif
