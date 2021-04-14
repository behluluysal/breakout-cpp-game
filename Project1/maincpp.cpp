#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <time.h>
float _width = 498.75f; //end 472.5 ekran boyu
float _height = 708.75f; //end 682,5 ekran boyu
float wallX = 26.25f;
float wallY = 0;
float racketX = 203;
const float racketY = 656;

float ballX = (((465*0.2f) - (371 * 0.05f))/2)+203;
float ballY = 655- (371 * 0.05f);
float cerceveSuresi = 1.0f / 60.0f;

float wallW = 175 * 0.15f; 

sf::Sprite solDuvar[27];
sf::Sprite sagDuvar[27];
sf::Sprite ustDuvar[17];
sf::Sprite altDuvar[17];

sf::Sprite line1[6];

sf::Texture wallTextures[4];
sf::Texture racketTextures[5];
sf::Texture ballTextures[6];


void cerceveOlustur();
int main()
{
    srand(time(0));
    wallTextures[0].loadFromFile("resimler/Walls/brick.png", { 43, 43, 175, 175 });
    wallTextures[1].loadFromFile("resimler/Walls/brick_blue.png", { 43, 43, 175, 175 });
    wallTextures[2].loadFromFile("resimler/Walls/brick_pink_side.png", { 43, 43, 175, 175 });
    wallTextures[3].loadFromFile("resimler/Walls/brick_red.png", { 43, 43, 175, 175 });

    racketTextures[0].loadFromFile("resimler/Bats/bat_black.png", { 24, 178, 465, 104 });
    racketTextures[1].loadFromFile("resimler/Bats/bat_blue.png", { 24, 178, 465, 104 });
    racketTextures[2].loadFromFile("resimler/Bats/bat_orange.png", { 24, 178, 465, 104 });
    racketTextures[3].loadFromFile("resimler/Bats/bat_pink.png", { 24, 178, 465, 104 });
    racketTextures[4].loadFromFile("resimler/Bats/bat_yellow.png", { 24, 178, 465, 104 });

    ballTextures[0].loadFromFile("resimler/Balls/ball_blue.png", { 68, 68, 371, 371 });
    ballTextures[1].loadFromFile("resimler/Balls/ball_green.png", { 68, 68, 371, 371 });
    ballTextures[2].loadFromFile("resimler/Balls/ball_orange.png", { 68, 68, 371, 371 });
    ballTextures[3].loadFromFile("resimler/Balls/ball_red.png", { 68, 68, 371, 371 });
    ballTextures[4].loadFromFile("resimler/Balls/ball_silver.png", { 68, 68, 371, 371 });
    ballTextures[5].loadFromFile("resimler/Balls/ball_yellow.png", { 68, 68, 371, 371 });
   
    sf::RenderWindow window(sf::VideoMode(_width, _height), "SFML works!");

    sf::Clock saat;
    sf::Time gecenSure;
    bool start = false;

   


    sf::Sprite sprite;//racket
    sprite.setTexture(racketTextures[rand()%5]);
    sprite.setScale(0.2f, 0.2f);

    sf::Sprite ball;
    ball.setTexture(ballTextures[rand() % 6]);
    ball.setScale(0.05f, 0.05f);
    
    cerceveOlustur();
    wallX = 36;
    wallY = 50;
    /*
    for (int i = 0; i < 6; ++i)
    {
        line1[i].setTexture(texture);
        line1[i].setScale(0.3f, 0.3f);
        line1[i].setPosition(wallX, 50);
        wallX += round((232 * 0.3f)+1);

    }*/
    while (window.isOpen())
    {
        sf::Event olay;
      
       


        while (window.pollEvent(olay))
        {
            if (olay.type == sf::Event::Closed)
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                start = true;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                if (racketX < 373)
                    racketX += 4;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                if (racketX > 34)
                    racketX -= 4;
            }
        }

        
        gecenSure += saat.restart();

        if (gecenSure.asSeconds() >= cerceveSuresi)
        {
            
            
            sprite.setPosition(racketX, racketY);
            ball.setPosition(ballX, ballY);

            window.clear(sf::Color::White);

            window.draw(sprite);
            window.draw(ball);
            for (int i = 0; i < 27; ++i)
            {
                window.draw(solDuvar[i]);
                window.draw(sagDuvar[i]);
                if (i < 17)
                {
                    window.draw(ustDuvar[i]);
                    window.draw(altDuvar[i]);
                }
                
            }
            /*
            for (int i = 0; i < 6; ++i)
            {
                window.draw(line1[i]);
            }*/
            
            window.display();
            gecenSure -= gecenSure;
        }


    }
    return 0;
}


void cerceveOlustur() {
    

    for (int i = 0; i < 27; ++i)
    {
        solDuvar[i].setTexture(wallTextures[rand() % 4]);
        solDuvar[i].setScale({ 0.15f,0.15f });
        solDuvar[i].setPosition(0, wallY);
        sagDuvar[i].setTexture(wallTextures[rand() % 4]);
        sagDuvar[i].setScale({ 0.15f,0.15f });
        sagDuvar[i].setPosition(472.5, wallY);
        wallY += wallW;
    }
    for (int i = 0; i < 17; ++i)
    {
        ustDuvar[i].setTexture(wallTextures[rand() % 4]);
        ustDuvar[i].setScale({ 0.15f,0.15f });
        ustDuvar[i].setPosition(wallX, 0);
        altDuvar[i].setTexture(wallTextures[rand() % 4]);
        altDuvar[i].setScale({ 0.15f,0.15f });
        altDuvar[i].setPosition(wallX, 682.5);
        wallX += wallW;
    }
}