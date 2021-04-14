#pragma once
#include "Pencere.hpp"
#include <SFML/Graphics.hpp>
class Oyun
{
public:
	Oyun();

	void girisKontrol();
	void sahneGuncelle(); 
	void sehneCiz();
	void saatiYenidenBaslat();
	void bittiMi();

private:
	Pencere		m_pencere;
	sf::Clock	m_saat;
	sf::Time	m_gecenSure;
	sf::CircleShape	m_daire;

	float	m_artis;
	float	m_konumX;
	float	m_cerceveSuresi;
};

