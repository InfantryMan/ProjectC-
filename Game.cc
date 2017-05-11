#include "Game.h"
#include <iostream>
#include "Globals.h"
#include <sstream>


FooDraw::FooDraw() {

}

FooDraw::~FooDraw() {}

void FooDraw::setWindow (sf::RenderWindow *window) {
	this->window = window;
	std::cout << "SET\n";
}

void FooDraw::DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) {
	sf::ConvexShape polygon;
	polygon.setPointCount(vertexCount);
	for (int32 i=0; i<vertexCount; i++) {
		b2Vec2 vertex = vertices[i];
		polygon.setPoint(i, sf::Vector2f(vertex.x*RATIO, vertex.y*RATIO));
	}
	//polygon.SetOutlineWidth(1.0f);
	//polygon.EnableFill(false);
	this->window->draw(polygon);
	std::cout << "DrawPolygon";

}


void FooDraw::DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) {
	sf::ConvexShape polygon;
	polygon.setPointCount(vertexCount);
	for (int32 i=0; i<vertexCount; i++) {
		b2Vec2 vertex = vertices[i];
		polygon.setPoint(i, sf::Vector2f(vertex.x*RATIO, vertex.y*RATIO));
	}

	//polygon.SetOutlineWidth(1.0f);
	//polygon.EnableFill(false);
	this->window->draw(polygon);
	//std::cout << "DrawPolygon";

}

sf::Color FooDraw::B2SFColor(const b2Color &color, int alpha) {
	sf::Color result((sf::Uint8)(color.r*255), (sf::Uint8)(color.g*255), (sf::Uint8)(color.b*255), (sf::Uint8) alpha);
	return result;
}

void Game::setWall(float x, float y, float w, float h, bool sensor, int number){
	b2BodyDef bodyDef;
	bodyDef.position.Set(0, 0);
	m_groundBody = m_world->CreateBody(&bodyDef);

	b2PolygonShape polygonShape;
	b2FixtureDef fixtureDef;
  	fixtureDef.shape = &polygonShape;
   	fixtureDef.isSensor = sensor;

   	polygonShape.SetAsBox( w/2/RATIO, h/2/RATIO, b2Vec2((x+w/2)/RATIO, (y+h/2)/RATIO), 0);

   	if (number == -1) 
   		m_groundBody->CreateFixture(&fixtureDef);
   	else {
   		b2Fixture* groundAreaFixture = m_groundBody->CreateFixture(&fixtureDef);
    	groundAreaFixture->SetUserData( new GroundAreaFUD( 0.5f, false,number ) );
   	}
	
}

void Game::setWalls() {

   	setWall(88,  232, 32, 1368, false);
   	setWall(204, 298, 33, 1261, false);
 
   	setWall(192, 154, 461, 13, false);
   	setWall(253, 259, 370, 16, false);
 
   	setWall(629, 288, 12, 965, false);
   	setWall(735, 248, 11, 968, false);

   	setWall(738, 1343, 193, 16,  false);
   	setWall(768, 1235, 134, 13,  false);

   	setWall(902,  841,  18, 399, false);
   	setWall(1014, 726, 215,  18, false);

   	setWall(1005, 869,  30, 394, false);
   	setWall(1055, 833, 145,  15, false);

   	setWall(1323, 846, 31, 680, false);
   	setWall(1232, 875,  6, 609, false);

   	setWall(198, 1700, 949, 27, false);
   	setWall(257, 1569, 859, 35, false);

   	setWall(107, 878, 108, 45, true, 0); //старт
   	//чекпоинты
   	setWall(107,  878, 108,  45, true, 0); 
   	setWall(510,  160,  45, 100, true, 1); 
   	setWall(640,  745,  96,  46, true, 2); 
   	setWall(806, 1246,  45,  98, true, 3); 
   	setWall(677, 1598,  45, 105, true, 4); 

   	//диагональные стены
   	b2BodyDef bodyDef;
	bodyDef.position.Set(0, 0);
	m_groundBody = m_world->CreateBody(&bodyDef );

	b2PolygonShape polygonShape;
	b2FixtureDef fixtureDef;
  	fixtureDef.shape = &polygonShape;
   	fixtureDef.isSensor = false;

   	polygonShape.SetAsBox( DIST(88,232,192,154)/2/RATIO, 5/RATIO,  b2Vec2((MID(88,192)+20)/RATIO, MID(232,154)/RATIO), -45*DEGTORAD);
	m_groundBody->CreateFixture(&fixtureDef);

	polygonShape.SetAsBox( DIST(204,298,253,259)/2/RATIO, 5/RATIO,  b2Vec2((MID(204,253)+10)/RATIO, (MID(298,259)+5)/RATIO), -45*DEGTORAD);
	m_groundBody->CreateFixture(&fixtureDef);

	polygonShape.SetAsBox( DIST(653,141,735,248)/2/RATIO, 5/RATIO,  b2Vec2((MID(653,735))/RATIO, (MID(141,248)+5)/RATIO), 45*DEGTORAD);
	m_groundBody->CreateFixture(&fixtureDef);

	polygonShape.SetAsBox( DIST(623,259,629,288)/2/RATIO, 5/RATIO,  b2Vec2((MID(623,629)+2)/RATIO, (MID(259,288)+5)/RATIO), 45*DEGTORAD);
	m_groundBody->CreateFixture(&fixtureDef);

	polygonShape.SetAsBox( DIST(629,1253,738,1343)/2/RATIO, 5/RATIO,  b2Vec2((MID(629,738)+2)/RATIO, (MID(1253,1343)+5)/RATIO), 45*DEGTORAD);
	m_groundBody->CreateFixture(&fixtureDef);

	polygonShape.SetAsBox( DIST(735,1216,768,1235)/2/RATIO, 5/RATIO,  b2Vec2((MID(735,768)+2)/RATIO, (MID(1216,1235)+5)/RATIO), 45*DEGTORAD);
	m_groundBody->CreateFixture(&fixtureDef);

	polygonShape.SetAsBox( DIST(931,1343,1005,1235)/2/RATIO, 5/RATIO,  b2Vec2((MID(931,1005)+10)/RATIO, (MID(1343,1235)+10)/RATIO), -45*DEGTORAD);
	m_groundBody->CreateFixture(&fixtureDef);

	polygonShape.SetAsBox( DIST(902,841,1014,726)/2/RATIO, 5/RATIO,  b2Vec2((MID(902,1014)+10)/RATIO, (MID(841,726)+10)/RATIO), -45*DEGTORAD);
	m_groundBody->CreateFixture(&fixtureDef);

	polygonShape.SetAsBox( DIST(1005,869,1055,833)/2/RATIO, 5/RATIO,  b2Vec2((MID(1005,1055)+5)/RATIO, (MID(869,833)+8)/RATIO), -45*DEGTORAD);
	m_groundBody->CreateFixture(&fixtureDef);

	polygonShape.SetAsBox( DIST(1200,833,1232,875)/2/RATIO, 5/RATIO,  b2Vec2((MID(1200,1232))/RATIO, (MID(833,875)+8)/RATIO), 45*DEGTORAD);
	m_groundBody->CreateFixture(&fixtureDef);

	polygonShape.SetAsBox( DIST(1229,726,1323,846)/2/RATIO, 5/RATIO,  b2Vec2((MID(1229,1323))/RATIO, (MID(726,846)+8)/RATIO), 45*DEGTORAD);
	m_groundBody->CreateFixture(&fixtureDef);

	polygonShape.SetAsBox( (DIST(1116,1569, 1232,1484)+16)/2/RATIO, 5/RATIO,  b2Vec2((MID(1116,1232))/RATIO, (MID(1569,1484)+10)/RATIO), -45*DEGTORAD);
	m_groundBody->CreateFixture(&fixtureDef);

	polygonShape.SetAsBox( (DIST(1147,1700, 1323,1526)+16)/2/RATIO, 5/RATIO,  b2Vec2((MID(1147,1323))/RATIO, (MID(1700,1526)+8)/RATIO), -45*DEGTORAD);
	m_groundBody->CreateFixture(&fixtureDef);

	polygonShape.SetAsBox( (DIST(88,1600, 198,1700))/2/RATIO, 5/RATIO,  b2Vec2((MID(88,198)+15)/RATIO, (MID(1600,1700)+8)/RATIO), 52*DEGTORAD);
	m_groundBody->CreateFixture(&fixtureDef);

	polygonShape.SetAsBox( (DIST(204,1559,257,1569)+6)/2/RATIO, 5/RATIO,  b2Vec2((MID(204,257)+2)/RATIO, (MID(1559,1569)+16)/RATIO), 38*DEGTORAD);
	m_groundBody->CreateFixture(&fixtureDef);
   //	setWall(88,170,130,2,-45*DEGTORAD);
   //	setWall(257,1569,859,35);



	/*polygonShape.SetAsBox( 5.0f/RATIO, 150.0f/RATIO, b2Vec2(130.0f/RATIO,400.0f/RATIO), 0 );
	m_groundBody->CreateFixture(&fixtureDef);

	polygonShape.SetAsBox( 2000/RATIO, 10.0f/RATIO, b2Vec2(350.0f/RATIO,600.0f/RATIO), 0 );
	m_groundBody->CreateFixture(&fixtureDef);

	polygonShape.SetAsBox( 2000/RATIO, 100.0f/RATIO );
	m_groundBody->CreateFixture(&fixtureDef);*/
}

Game::Game(sf::RenderWindow* window): m_window(window) {
	m_world = new b2World(b2Vec2(0,0));
	m_world->SetGravity( b2Vec2(0,0) );

	font.loadFromFile("./Staff/VCR_OSD_MONO.ttf");
	text.setFont(font); 
	text.setString(" ");
	text.setCharacterSize(50);
	text.setColor(sf::Color::White);
    text.setStyle(sf::Text::Bold); 

	clock.restart();

	player.setCar(m_world);
	
	m_tBackGround.loadFromFile("./Staff/background.png");
	m_tBackGround.setSmooth(true);
	m_sBackGround.setTexture(m_tBackGround);
	//m_sBackGround.setTextureRect( IntRect())
	m_sBackGround.scale(1,1);
	m_controlState = 0;

   	//if (!buffer.loadFromFile("./Staff/lol.ogg"))
        ;//обработать

    sound.setBuffer(buffer);

    //if (!music.openFromFile("./Staff/skyrim.ogg"))
        ;//o,hf,fnfnm
    //    music.play();

    m_debugDraw.SetFlags(b2Draw::e_shapeBit);
    m_debugDraw.setWindow(m_window);
    m_world->SetDebugDraw(&m_debugDraw);
    setWalls();

}

void Game::keyPressed() {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        m_controlState |= LEFT;
    } else {
		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && (m_controlState & LEFT)) {
    		m_controlState &= ~LEFT; 
	 	}
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))  {
        m_controlState |= RIGHT;
    } else {
		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && (m_controlState & RIGHT))  {
    		m_controlState &= ~RIGHT;
		}
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))  { 
        m_controlState |= UP; 
        sound.play();
    } else {
		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && (m_controlState & UP))  { 
    		m_controlState &= ~UP; 
            //sound.stop();
		}
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))  { 
        m_controlState |= DOWN;
    } else {
		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && (m_controlState & DOWN))  { 
    		m_controlState &= ~DOWN; 
		}
    }    
}

b2World* Game::getWorld() {
	return m_world;
}

Player Game::getPlayer() {
	return player; 
}

void Game::checkBorders(float x, float y) {
	sf::View view(sf::FloatRect(0, 450, 1280, 720));
	m_window->setView(view);
	sf::Vector2f center = view.getCenter();
	text.setPosition(center.x + 150, center.y - 250);

	if (x*RATIO <=160 && y*RATIO <= 446) {
		view.move(0, -446);
		m_window->setView(view);
		text.move(0, -446);
		return;
	}

	if (x*RATIO >= 320 && y*RATIO <= 446) {
 		view.move(320-160,-446);
 		m_window->setView(view);
 		text.move(320-160,-446);
 		return;
 	}

 	if (y*RATIO >= 1550 && x*RATIO >= 320) {
		view.move(320-160, 654);
		m_window->setView(view);
		text.move(320-160, 654);
		return;
	}

	if (x*RATIO <= 160 && y*RATIO >= 1550 ) {
		view.move(0, 654);
		m_window->setView(view);
		text.move(0, 654);
		return;
	}

	if (y*RATIO <= 446) {
		view.move(x*RATIO-XPOS,-446);
		m_window->setView(view);
		text.move(x*RATIO-XPOS,-446);
		return;
	}


	if (x*RATIO >= 320 && y*RATIO<1550) {
		view.move(320-160,y*RATIO-YPOS);
		m_window->setView(view);
		text.move(320-160,y*RATIO-YPOS);
		return;
	}


	if (y*RATIO >= 1550) {
		view.move(x*RATIO-XPOS,654);
		m_window->setView(view);
		text.move(x*RATIO-XPOS,654);
		return;
	}

	if (x*RATIO <= 160) {
		view.move(0, y*RATIO-YPOS);
		m_window->setView(view);
		text.move(0, y*RATIO-YPOS);
		
		return;
	}

	view.move(x*RATIO-XPOS,y*RATIO-YPOS);
	text.move(x*RATIO-XPOS,y*RATIO-YPOS);
	m_window->setView(view);
}

void Game::step() {
	sf::Time elapsed1 = clock.getElapsedTime();
	std::ostringstream playerTime, bestScore;  

    playerTime << elapsed1.asSeconds();  
    bestScore  << player.getBestScore();
    text.setString("Time: " + playerTime.str() + '\n' + "Best score: " + bestScore.str());


	Car* Car = player.getCar();
	
	sf::Sprite sCar = Car->getSprite();
	sCar.setOrigin(CAR_WIDTH/2, CAR_HEIGHT/2);
	
	b2Vec2 vec = Car->getBody()->GetPosition();
	float angle = Car->getBody()->GetAngle();

 	checkBorders(vec.x, vec.y); //проверяет на выход за границы карты (белые полосы по краям убирает)

	m_window->draw(m_sBackGround);
	m_world->DrawDebugData();

	keyPressed();
	Car->update(m_controlState);

	sCar.setRotation(angle*RADTODEG);
	sCar.setPosition(vec.x*RATIO, vec.y*RATIO);
	

	m_window->draw(sCar);
	std::vector<Tire*> tires = Car->getTires();
	for(int i = 0; i < tires.size(); i++) {
		sf::Sprite sTire = tires[i]->getSprite();
		sTire.setOrigin(TIRE_WIDTH/2, TIRE_HEIGHT/2);
		vec = tires[i]->getBody()->GetPosition();
		angle = tires[i]->getBody()->GetAngle();
		sTire.setRotation(angle*RADTODEG);
		sTire.setPosition(vec.x*RATIO,vec.y*RATIO);
		m_window->draw(sTire);
	}
	m_window->draw(text);
}
