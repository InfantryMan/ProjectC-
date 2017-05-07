#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include <Box2D/Box2D.h>

class Game {
  	private:
  		b2Body*  m_groundBody;
	  	b2World* m_world;

	    sf::RenderWindow* m_window;
	    sf::Texture m_tBackGround;
	    sf::Sprite m_sBackGround;

	    Player player;
	    //Square square(m_world);
	    void setWalls();

  	public:
    	Game(sf::RenderWindow* window);
    	~Game();
    	void step();
    	b2World* getWorld();
    	Player getPlayer();
};

#endif