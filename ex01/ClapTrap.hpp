/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:15:25 by lgasc             #+#    #+#             */
/*   Updated: 2024/10/15 18:58:46 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

# include <string>

class ClapTrap {
	static const unsigned
		c_hit_points = 10,	c_energy_points = 10,	c_attack_damage = 0;

protected:
	std::string	name;
	unsigned	hit_points,	energy_points,	attack_damage;

	ClapTrap	(void);
public:
	ClapTrap	(const ClapTrap &);
	ClapTrap	& operator = (const ClapTrap &);
	~ ClapTrap	(void);

	ClapTrap	(const std::string & name);

	void	attack(const std::string & target);
	void	takeDamage(unsigned amount);
	void	beRepaired(unsigned amount);
};
#endif
