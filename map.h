#include <SFML/Graphics.hpp>
using namespace sf;
const int height = 3;
const int width = 3;
sf::String Map[height] =
{
	"---",
	"---",
	"---",
};




void drawmap(sf::RenderTarget& window, Sprite& mapSprite)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (Map[i][j] == '-') mapSprite.setTextureRect(IntRect(200, 0, 100, 100));
            if (Map[i][j] == 'X') mapSprite.setTextureRect(IntRect(0, 0, 100, 100));
            if (Map[i][j] == 'O') mapSprite.setTextureRect(IntRect(100, 0, 100, 100));
            mapSprite.setPosition(j * 100 + 330, i * 100 + 220);
            window.draw(mapSprite);
        }
    }
}


