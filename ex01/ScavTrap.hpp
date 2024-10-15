/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:11:06 by lgasc             #+#    #+#             */
/*   Updated: 2024/10/15 20:16:29 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	static const unsigned
		c_hit_points = 100,	c_energy_points = 50,	c_attack_damage = 20;

	ScavTrap	(void);
public:
	ScavTrap	(const ScavTrap &);
	ScavTrap	& operator = (const ScavTrap &);
	~ ScavTrap	(void);

	ScavTrap	(const std::string & name);

	void	attack(const std::string & target);
	void	takeDamage(unsigned amount);
	void	beRepaired(unsigned amount);
	void	guardGate(void) const;
};
#endif
