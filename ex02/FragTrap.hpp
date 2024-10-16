/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:11:06 by lgasc             #+#    #+#             */
/*   Updated: 2024/10/16 16:16:41 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	static const unsigned
		c_hit_points = 100,	c_energy_points = 100,	c_attack_damage = 30;

	FragTrap	(void);
public:
	FragTrap	(const FragTrap &);
	FragTrap	& operator = (const FragTrap &);
	~ FragTrap	(void);

	FragTrap	(const std::string & name);

	void	attack(const std::string & target);
	void	takeDamage(unsigned amount);
	void	beRepaired(unsigned amount);
	void	highFivesGuys(void) const;
};
#endif
