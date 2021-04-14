#pragma once
#include <SFML/Graphics.hpp>
class Pencere
{
public:
	Pencere();
	void olustur(int gen, int yuk, sf::String baslik);
	bool kapandimi();
	void olayKontrol();
	void cizimeBasla();
	void cizimiBitir();
	void ciz(sf::Drawable& sekil);
private:
	sf::RenderWindow m_sfmlPencere;
};

