#ifndef TP_PROJECT_ARTIST_H
#define TP_PROJECT_ARTIST_H

#include "SFML/Graphics.hpp"
#include "Object.h"
#include <list>

enum ObjectType;

class Artist;

class ArtistDestroyer {
private:
    Artist *p_instance;
    void initialize(Artist *);
    friend class Artist;
    ArtistDestroyer() = default;
    ArtistDestroyer &operator=(const ArtistDestroyer &) = delete;
public:
    ArtistDestroyer(const ArtistDestroyer &) = delete;
    ~ArtistDestroyer();
};

class Artist {
private:
    std::vector<sizes> textureSizes;
    std::vector<sf::Texture> textures;
    std::vector<sf::Sprite> sprites;
    static Artist *p_instance;
    static ArtistDestroyer destroyer;
    Artist();
    Artist(const Artist &);
    Artist &operator=(const Artist &);
    ~Artist() = default;
    friend class ArtistDestroyer;
public:
    static Artist &getInstance();
    void draw(const Object &, sf::RenderWindow &window);
    void draw(const std::list<Object *> &, sf::RenderWindow &window);
};


#endif //TP_PROJECT_ARTIST_H
