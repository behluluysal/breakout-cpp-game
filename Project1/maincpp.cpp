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
float ballArtisX = 3, ballArtisY = 3;
float lastX = 0;
float cerceveSuresi = 1.0f / 60.0f;

float wallW = 175 * 0.15f; 

sf::Sprite sprite;//racket

sf::Sprite solDuvar[27];
sf::Sprite sagDuvar[27];
sf::Sprite ustDuvar[17];
sf::Sprite altDuvar[17];

struct Brick {
    sf::Sprite item;
    int index;
    bool broken;
    bool destroyed;
};

struct Brick bricks[4][6];

sf::Texture wallTextures[4];
sf::Texture racketTextures[5];
sf::Texture ballTextures[6];
sf::Texture brickTextures[5];
sf::Texture brickBrokenTextures[5];

sf::Sprite ball;


void cerceveOlustur();
void bricksOlustur();
void ballControl();

bool start = false;
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

    brickTextures[0].loadFromFile("resimler/Bricks/brick_blue_small.png", { 140, 177, 233, 104 });
    brickTextures[1].loadFromFile("resimler/Bricks/brick_green_small.png", { 140, 177, 233, 104 });
    brickTextures[2].loadFromFile("resimler/Bricks/brick_pink_small.png", { 140, 177, 233, 104 });
    brickTextures[3].loadFromFile("resimler/Bricks/brick_violet_small.png", { 140, 177, 233, 104 });
    brickTextures[4].loadFromFile("resimler/Bricks/brick_yellow_small.png", { 140, 177, 233, 104 });

    brickBrokenTextures[0].loadFromFile("resimler/Bricks/brick_blue_small_cracked.png", { 140, 177, 233, 104 });
    brickBrokenTextures[1].loadFromFile("resimler/Bricks/brick_green_small_cracked.png", { 140, 177, 233, 104 });
    brickBrokenTextures[2].loadFromFile("resimler/Bricks/brick_pink_small_try.png", { 140, 177, 233, 104 });
    brickBrokenTextures[3].loadFromFile("resimler/Bricks/brick_violet_small_cracked.png", { 140, 177, 233, 104 });
    brickBrokenTextures[4].loadFromFile("resimler/Bricks/brick_yellow_small_cracked.png", { 140, 177, 233, 104 });
   
    sf::RenderWindow window(sf::VideoMode(_width, _height), "BREAKOUT");

    sf::Clock saat;
    sf::Clock saat2;
    sf::Time gecenSure;
    sf::Time dt;
   


    
    sprite.setTexture(racketTextures[rand()%5]);
    sprite.setScale(0.2f, 0.2f);

    
    ball.setTexture(ballTextures[rand() % 6]);
    ball.setScale(0.05f, 0.05f);
    
    cerceveOlustur();
    bricksOlustur();
    sprite.setPosition(racketX, racketY);
    ball.setPosition(ballX, ballY);

    while (window.isOpen())
    {
        sf::Event olay;
      
        

        while (window.pollEvent(olay))
        {

            if (olay.type == sf::Event::Closed)
                window.close();
            
        }

        
        gecenSure += saat.restart();
        dt = saat2.restart();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            start = true;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            dt = saat2.restart();
            if (racketX < 373)
            {
                racketX += (800.0f * dt.asSeconds());
                if (!start)
                    ballX += (800.0f * dt.asSeconds());
            }
                
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            dt = saat2.restart();
            if (racketX > 34)
            {
                racketX -= (800.0f * dt.asSeconds());
                if(!start)
                    ballX -= (800.0f * dt.asSeconds());
            }
               
        }

        if (gecenSure.asSeconds() >= cerceveSuresi)
        {
             sprite.setPosition(racketX, racketY);
             ball.setPosition(ballX, ballY);

            if (start) {
                sprite.setPosition(racketX, racketY);
                ballX += ballArtisX;
                ballY -= ballArtisY;
                ball.setPosition(ballX, ballY);
                ballControl();
            }
            

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
                if (i < 4) {
                    for (int j = 0; j < 6; ++j) {
                        if(!bricks[i][j].destroyed)
                            window.draw(bricks[i][j].item);
                    }
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

void bricksOlustur() {
    int brickX = 36, brickY = 50;
    for (int i = 0; i < 4; ++i)
    {
        brickX = 36;
        for (int j = 0; j < 6; ++j) {
            int random = rand() % 5;
            bricks[i][j].index = random;
            bricks[i][j].broken = false;
            bricks[i][j].destroyed = false;
            bricks[i][j].item.setTexture(brickTextures[random]);
            bricks[i][j].item.setScale(0.3f, 0.3f);
            bricks[i][j].item.setPosition(brickX, brickY);
            brickX += round((232 * 0.3f) + 1);
        }
        brickY += round((104 * 0.3f) + 1);
    }
}

void ballControl() {
    // Sað duvar kontrol
    if (ball.getPosition().x >= 472.5 - (371 * 0.05)) {
        ballArtisX *= -1;
        lastX = ball.getPosition().x;
    }
    // Sol duvar kontrol
    if (ball.getPosition().x <= 26.25) {
        ballArtisX *= -1;
        lastX = ball.getPosition().x;
    }
    // Üst duvar kontrol
    if (ball.getPosition().y <= 26.25) {
        ballArtisY *= -1;
        lastX = ball.getPosition().x;
    }
    // Alt duvar kontrol
    if (ball.getPosition().y >= 682 - ((371 * 0.05))) {
        start = false;
        ballArtisX = 0;
        ballArtisY = 0;
        lastX = ball.getPosition().x;
    }
    // Raket kontrol
    if (ball.getGlobalBounds().intersects(sprite.getGlobalBounds())) {
        // Raketin Solu
        if (ball.getPosition().x <= sprite.getPosition().x + (465 * 0.2 / 2)) {
            // Soldan geliyorsa
            if (lastX <= ball.getPosition().x) {
                ballArtisX *= -1;
                lastX = ball.getPosition().x;
            }
        }
        // Raketin Saðý
        if (ball.getPosition().x >= sprite.getPosition().x + (465 * 0.2 / 2)) {
            // Saðdan geliyorsa
            if (lastX >= ball.getPosition().x) {
                ballArtisX *= -1;
                lastX = ball.getPosition().x;
            }
        }
        ballArtisY *= -1;
    }

    // Brick kontrol
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 6; ++j) {
            if (!bricks[i][j].destroyed)
            if (ball.getGlobalBounds().intersects(bricks[i][j].item.getGlobalBounds())) {
                // Brick Solu
                if (ball.getPosition().x <= bricks[i][j].item.getPosition().x + (233 * 0.3 / 2)) {
                    // Soldan geliyorsa
                    if (lastX <= ball.getPosition().x) {
                        ballArtisX *= -1;
                    }
                }
                // Brick Saðý
                if (ball.getPosition().x >= bricks[i][j].item.getPosition().x + (233 * 0.3 / 2)) {
                    // Saðdan geliyorsa
                    if (lastX >= ball.getPosition().x) {
                        ballArtisX *= -1;
                    }
                }
                lastX = ball.getPosition().x;
                if (!bricks[i][j].broken) {
                    bricks[i][j].item.setTexture(brickBrokenTextures[bricks[i][j].index]);
                    bricks[i][j].broken = true;
                }
                else {
                    bricks[i][j].destroyed = true;
                }
                ballArtisY *= -1;
                return;
            }
        }
    }
}