#pragma once
#include <SFML/Graphics.hpp>

class Player
{
private:

	sf::Texture texture;   //texture is array of pixels
public:
	sf::Sprite  sprite;     //spirte holds texture

public:
	void Initialize();           //<- called once per App start
	void Load();                 //<- called once per App start
	void Update();               //<- called once per frame
	void Draw();                 //<- called once per frame 
};

