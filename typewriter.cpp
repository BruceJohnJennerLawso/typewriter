// typewriter.cpp //////////////////////////////////////////////////////////////
// An SFML program that runs in the background /////////////////////////////////
// playing audio feedback with each keypress ///////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//#include <std_files>
//#include "Headers.h"
//#include "Headers.hpp"
//#include "Source.cpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

int main()
{	sf::SoundBuffer doubleBeepBuffer;
	sf::SoundBuffer singleBeepBuffer;
	sf::SoundBuffer singleLowBeepBuffer;
	sf::SoundBuffer singleHighBeepBuffer;
	sf::SoundBuffer singleFuzzyBeepBuffer;
	sf::SoundBuffer singleSoftBeepBuffer;
	//if (!buffer.loadFromFile("./typewriter_click.ogg"))

	if (!doubleBeepBuffer.loadFromFile("./keystrokeSounds/doubleBeep.wav"))
	{	return -1;
	}
	else if (!singleBeepBuffer.loadFromFile("./keystrokeSounds/singleBeep.wav"))
	{	return -1;
	}
	else if (!singleLowBeepBuffer.loadFromFile("./keystrokeSounds/singleLowFlatBeep.ogg"))
	{	return -1;
	}
	else if (!singleHighBeepBuffer.loadFromFile("./keystrokeSounds/singleHighLongBeep.ogg"))
	{	return -1;
	}
	else if (!singleFuzzyBeepBuffer.loadFromFile("./keystrokeSounds/singleFuzzyMidBeep.wav"))
	{	return -1;
	}
	else if (!singleSoftBeepBuffer.loadFromFile("./keystrokeSounds/singleMidSoftBeep.wav"))
	{	return -1;
	}	
	else
	{	sf::Sound vowelSound;
		vowelSound.setBuffer(singleLowBeepBuffer);
		
		sf::Sound hardsSound;
		hardsSound.setBuffer(singleBeepBuffer);
		
		sf::Sound softsSound;
		softsSound.setBuffer(singleSoftBeepBuffer);
		
		sf::Sound weirdsSound;
		weirdsSound.setBuffer(singleFuzzyBeepBuffer);
		//weirdsSound.setPitch(0.25);
		
		sf::RenderWindow window(sf::VideoMode(300, 20), "typewriter 1.0");
		window.setFramerateLimit(20);
		while (window.isOpen())
		{	
			if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A))||
				(sf::Keyboard::isKeyPressed(sf::Keyboard::E))||
				(sf::Keyboard::isKeyPressed(sf::Keyboard::I))||
				(sf::Keyboard::isKeyPressed(sf::Keyboard::O))||
				(sf::Keyboard::isKeyPressed(sf::Keyboard::U))||
				(sf::Keyboard::isKeyPressed(sf::Keyboard::Y)))
			{	vowelSound.play();
			}
			
			
			if ((sf::Keyboard::isKeyPressed(sf::Keyboard::C))||
				(sf::Keyboard::isKeyPressed(sf::Keyboard::F))||
				(sf::Keyboard::isKeyPressed(sf::Keyboard::G))||
				(sf::Keyboard::isKeyPressed(sf::Keyboard::K))||
				(sf::Keyboard::isKeyPressed(sf::Keyboard::P))||
				(sf::Keyboard::isKeyPressed(sf::Keyboard::R))||
				(sf::Keyboard::isKeyPressed(sf::Keyboard::S))||
				(sf::Keyboard::isKeyPressed(sf::Keyboard::T))||
				(sf::Keyboard::isKeyPressed(sf::Keyboard::W)))
			{	hardsSound.play();	// glorious, GLORIOUS!!!
			}
			
			if ((sf::Keyboard::isKeyPressed(sf::Keyboard::B))||
				(sf::Keyboard::isKeyPressed(sf::Keyboard::D))||
				(sf::Keyboard::isKeyPressed(sf::Keyboard::H))||
				(sf::Keyboard::isKeyPressed(sf::Keyboard::L))||
				(sf::Keyboard::isKeyPressed(sf::Keyboard::M))||
				(sf::Keyboard::isKeyPressed(sf::Keyboard::N)))
			{	softsSound.setPitch(0.5);
				softsSound.play();	// glorious, GLORIOUS!!!
			}
			
			if ((sf::Keyboard::isKeyPressed(sf::Keyboard::J))||
				(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))||
				(sf::Keyboard::isKeyPressed(sf::Keyboard::V))||
				(sf::Keyboard::isKeyPressed(sf::Keyboard::X))||
				(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)))
			{	weirdsSound.play();	// glorious, GLORIOUS!!!
			}
			
			
			sf::Event event;
			while (window.pollEvent(event))
			{	if(event.type == sf::Event::Closed)
				{	window.close();
				}
			}
			window.clear();
			// eventually this can be some sort of logo
			window.display();
		}
	}
	return 0;
}
