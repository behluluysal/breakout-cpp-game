#include "Pencere.hpp"
Pencere::Pencere() {

}


void Pencere::olustur(int gen, int yuk, sf::String baslik)
{
	m_sfmlPencere.create(sf::VideoMode(gen, yuk), baslik);
}

bool Pencere::kapandimi()
{
	return !m_sfmlPencere.isOpen();
}

void Pencere::olayKontrol()
{
    sf::Event olay;
    while (m_sfmlPencere.pollEvent(olay))
    {
        if (olay.type == sf::Event::Closed)
            m_sfmlPencere.close();

    }
}

void Pencere::cizimeBasla()
{
    m_sfmlPencere.clear();
}

void Pencere::cizimiBitir()
{
    m_sfmlPencere.display();
}

void Pencere::ciz(sf::Drawable& sekil)
{
    m_sfmlPencere.draw(sekil);
}
