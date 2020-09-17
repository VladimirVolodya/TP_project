#ifndef TP_PROJECT_ARTIST_H
#define TP_PROJECT_ARTIST_H

#include "SFML/Graphics.hpp"
#include "BaseObject/Object.h"
#include "Bullet/Bullet.h"
#include "Player/Player.h"

enum ObjectType;

class Artist;

class Artist {
private:
    sf::Texture wasted_texture;
    sf::Texture background_texture;
    sf::Sprite wasted;
    sf::Sprite background;
    std::vector<sizes> textureSizes;
    std::vector<sf::Texture> textures;
    std::vector<sf::Sprite> sprites;
    static Artist *p_instance;
    static Player *p_player;
    Artist();
    Artist(const Artist &);
    Artist &operator=(const Artist &);
    bool game_over;
    friend class Player;
    void gameOver();
    void finalDraw(sf::RenderWindow &window);
public:
    static Artist *getInstance();
    static void tieWithPlayer(Player *);
    void draw(const Object &, sf::RenderWindow &window);
    void draw(const std::list<std::shared_ptr<Object>> &, sf::RenderWindow &window);
    void draw(const std::list<std::shared_ptr<Bullet>> &, sf::RenderWindow &window);
    void drawBackground(sf::RenderWindow &window);
    ~Artist();
};


#endif //TP_PROJECT_ARTIST_H
