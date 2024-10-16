/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:11:06 by lgasc             #+#    #+#             */
/*   Updated: 2024/10/16 19:51:34 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap {
protected:
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
