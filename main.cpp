#include "map.h"
#include <SFML/Graphics.hpp>
#include "logic.h"
#pragma warning(disable:4996)
using namespace sf;
int main()
{
    Color wColor = Color(0, 64, 128);


    bool gameover = 0;
    std::string Winner = "";

    Image mapImage;
    mapImage.loadFromFile("images/map.png");

    Texture mapTexture;
    mapTexture.loadFromImage(mapImage); 



    Sprite mapSprite;
    mapSprite.setTexture(mapTexture);

   // Window window;
    RenderWindow window(VideoMode(1000, 800), "Test");
    View view;
    view.reset(FloatRect(0, 0, 1000, 800));
    view.setCenter(500, 400);


    while (window.isOpen())
    {
        Vector2i mousePos = Mouse::getPosition(window);
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
            if (event.type == Event::MouseButtonPressed) {
                if (!gameover && event.key.code == Mouse::Left)
                {
                    if (Map[(mousePos.y - 220) / 100][(mousePos.x - 330) / 100] == '-' && mousePos.y >220 && mousePos.x > 330)
                    {
                        Map[(mousePos.y - 220) / 100][(mousePos.x - 330) / 100] = 'X';
                        logic();
                        gameover = isover(Winner);
                    }
                }
                else if (!gameover && event.key.code == Mouse::Right)
                {
                    if (Map[(mousePos.y - 220) / 100][(mousePos.x - 330) / 100] != '-' && mousePos.y > 220 && mousePos.x > 330)
                        Map[(mousePos.y - 220) / 100][(mousePos.x - 330) / 100] = '-';
                }
                else if (gameover && event.key.code == Mouse::Left)
                {
                    if (mousePos.x >= 200 && mousePos.x <= 830 && mousePos.y >= 650 && mousePos.y <= 750)
                    {
                        for (int i = 0; i < height; i++)
                            for (int j = 0; j < width; j++)
                                Map[i][j] = '-';
                        gameover = 0;
                        wColor = Color(0, 64, 128);
                    }
                }
            }
            window.setView(view);
            window.clear(wColor);
            drawmap(window, mapSprite);
            if (gameover)
            {
               if(Winner == "Computer") wColor = Color::Black;
               else wColor = Color(34, 177, 76);
                Image tryImage;
                tryImage.loadFromFile("images/tryagain.png");

                Texture tryTexture;
                tryTexture.loadFromImage(tryImage);


                Sprite trySprite;
                trySprite.setTexture(tryTexture);
                trySprite.setTextureRect(IntRect(0, 0, 630, 100));
                trySprite.setPosition(200, 650);


                Font font;
                font.loadFromFile("CyrilicOld.ttf");

                Text finalText(Winner + " won!", font, 50);
                Text tryAgain("Wanna try again?", font, 60);

                tryAgain.setColor(Color::White);
                tryAgain.setPosition(300, 650);

                finalText.setColor(Color::White);
                finalText.setPosition(350, 0);


                window.draw(trySprite);
                window.draw(finalText);
                window.draw(tryAgain);

            }
        window.display();
    }
}
