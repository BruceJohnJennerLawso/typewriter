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
#include <math.h>
#include <iostream>



enum note {C, D, E, F, G, A, B};

float getRelativePitchByNoteInEqualTemperament(note noteInOctave, int octaveOffset)
{
	float homeNotePitch = 0.0;
	if(octaveOffset == 0)
	{
		homeNotePitch = 1.0;
	}
	else
	{
		homeNotePitch = pow(2, float(octaveOffset));
	}	
	
	if(noteInOctave == C)
	{
		return homeNotePitch;
	}
	else if(noteInOctave == D)
	{
		return (homeNotePitch*pow((2.0), (1.0/6.0)));
	}
	else if(noteInOctave == E)
	{
		return (homeNotePitch*pow((2.0), (1.0/3.0)));
	}
	else if(noteInOctave == F)
	{
		return (homeNotePitch*pow((2.0), (5.0/12.0)));
	}	
	else if(noteInOctave == G)
	{
		return (homeNotePitch*pow((2.0), (7.0/12.0)));
	}	
	else if(noteInOctave == A)
	{
		return (homeNotePitch*pow((2.0), (3.0/4.0)));
	}		
	else if(noteInOctave == B)
	{
		return (homeNotePitch*pow((2.0), (11.0/12.0)));
	}	
}





int main()
{	
	
	std::cout << getRelativePitchByNoteInEqualTemperament(C, -1) << std::endl;
	std::cout << getRelativePitchByNoteInEqualTemperament(D, -1) << std::endl;
	std::cout << getRelativePitchByNoteInEqualTemperament(E, -1) << std::endl;
	std::cout << getRelativePitchByNoteInEqualTemperament(F, -1) << std::endl;
	std::cout << getRelativePitchByNoteInEqualTemperament(G, -1) << std::endl;
	std::cout << getRelativePitchByNoteInEqualTemperament(A, -1) << std::endl;
	std::cout << getRelativePitchByNoteInEqualTemperament(B, -1) << std::endl;
	std::cout << getRelativePitchByNoteInEqualTemperament(C, 0) << std::endl;
	std::cout << getRelativePitchByNoteInEqualTemperament(D, 0) << std::endl;
	std::cout << getRelativePitchByNoteInEqualTemperament(E, 0) << std::endl;
	std::cout << getRelativePitchByNoteInEqualTemperament(F, 0) << std::endl;
	std::cout << getRelativePitchByNoteInEqualTemperament(G, 0) << std::endl;
	std::cout << getRelativePitchByNoteInEqualTemperament(A, 0) << std::endl;
	std::cout << getRelativePitchByNoteInEqualTemperament(B, 0) << std::endl;	
	std::cout << getRelativePitchByNoteInEqualTemperament(C, 1) << std::endl;
	std::cout << getRelativePitchByNoteInEqualTemperament(D, 1) << std::endl;
	std::cout << getRelativePitchByNoteInEqualTemperament(E, 1) << std::endl;
	std::cout << getRelativePitchByNoteInEqualTemperament(F, 1) << std::endl;
	std::cout << getRelativePitchByNoteInEqualTemperament(G, 1) << std::endl;
	std::cout << getRelativePitchByNoteInEqualTemperament(A, 1) << std::endl;
	std::cout << getRelativePitchByNoteInEqualTemperament(B, 1) << std::endl;
	std::cout << getRelativePitchByNoteInEqualTemperament(C, 2) << std::endl;				
	
	sf::SoundBuffer doubleBeepBuffer;
	sf::SoundBuffer singleHighBeepBuffer;
	
	sf::SoundBuffer singleBeepBuffer;
	sf::SoundBuffer singleLowBeepBuffer;
	sf::SoundBuffer singleFuzzyBeepBuffer;
	sf::SoundBuffer singleSoftBeepBuffer;
	
	sf::SoundBuffer lowVeryShortBeepBuffer;	
	
	sf::SoundBuffer clickSnapBuffer;		
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
	else if (!lowVeryShortBeepBuffer.loadFromFile("./keystrokeSounds/lowVeryShortBeep.wav"))
	{	return -1;
	}		
	else if (!clickSnapBuffer.loadFromFile("./keystrokeSounds/clickSnap.wav"))
	{	return -1;
	}
	else
	{	sf::Sound vowelSound;
		vowelSound.setBuffer(singleLowBeepBuffer);
		
		sf::Sound hardsSound;
		hardsSound.setBuffer(lowVeryShortBeepBuffer);
		
		sf::Sound softsSound;
		softsSound.setBuffer(singleSoftBeepBuffer);
		
		sf::Sound weirdsSound;
		weirdsSound.setBuffer(singleFuzzyBeepBuffer);
		//weirdsSound.setPitch(0.25);


		sf::Sound auxButtonsSound;
		auxButtonsSound.setBuffer(singleBeepBuffer);

		sf::Sound tildaSound;
		tildaSound.setBuffer(clickSnapBuffer);
		
		
		float vowelHomeNote = 0.5;
		
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
			{	
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::E))
				{
					vowelSound.setPitch(vowelHomeNote*getRelativePitchByNoteInEqualTemperament(B, 0));
				}
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				{
					vowelSound.setPitch(vowelHomeNote*getRelativePitchByNoteInEqualTemperament(A, 0));
				}				
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::O))
				{
					vowelSound.setPitch(vowelHomeNote*getRelativePitchByNoteInEqualTemperament(G, 0));
				}
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::I))
				{
					vowelSound.setPitch(vowelHomeNote*getRelativePitchByNoteInEqualTemperament(F, 0));
				}								
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::U))
				{
					vowelSound.setPitch(vowelHomeNote*getRelativePitchByNoteInEqualTemperament(E, 0));
				}
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
				{
					vowelSound.setPitch(vowelHomeNote*getRelativePitchByNoteInEqualTemperament(D, 0));
				}								
				vowelSound.play();
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
			{	
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::T))
				{
					hardsSound.setPitch(1.0);
				}
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				{
					hardsSound.setPitch(0.5*pow(2, (11.0/12.0)));
				}
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
				{
					hardsSound.setPitch(0.5*pow(2, (3.0/4.0)));
				}				
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::C))
				{
					hardsSound.setPitch(0.5*pow(2, (7.0/12.0)));
				}
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::F))
				{
					hardsSound.setPitch(0.5*pow(2, (5.0/12.0)));
				}								
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::P))
				{
					hardsSound.setPitch(0.5*pow(2, (1.0/3.0)));
				}
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::G))
				{
					hardsSound.setPitch(0.5*pow(2, (1.0/6.0)));
				}
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				{
					hardsSound.setPitch(0.5);
				}
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::K))
				{
					hardsSound.setPitch(0.25*pow(2, (11.0/12.0)));
				}				
				
				
				hardsSound.play();
			}
			
			if ((sf::Keyboard::isKeyPressed(sf::Keyboard::B))||
				(sf::Keyboard::isKeyPressed(sf::Keyboard::D))||
				(sf::Keyboard::isKeyPressed(sf::Keyboard::H))||
				(sf::Keyboard::isKeyPressed(sf::Keyboard::L))||
				(sf::Keyboard::isKeyPressed(sf::Keyboard::M))||
				(sf::Keyboard::isKeyPressed(sf::Keyboard::N)))
			{	if(sf::Keyboard::isKeyPressed(sf::Keyboard::N))
				{
					softsSound.setPitch(vowelHomeNote*pow(2, (11.0/12.0)));
				}
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::H))
				{
					softsSound.setPitch(vowelHomeNote*pow(2, (3.0/4.0)));
				}				
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::L))
				{
					softsSound.setPitch(vowelHomeNote*pow(2, (7.0/12.0)));
				}
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				{
					softsSound.setPitch(vowelHomeNote*pow(2, (5.0/12.0)));
				}								
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::M))
				{
					softsSound.setPitch(vowelHomeNote*pow(2, (1.0/3.0)));
				}
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::B))
				{
					softsSound.setPitch(vowelHomeNote*pow(2, (1.0/6.0)));
				}		
				softsSound.play();
			}
			
			if ((sf::Keyboard::isKeyPressed(sf::Keyboard::J))||
				(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))||
				(sf::Keyboard::isKeyPressed(sf::Keyboard::V))||
				(sf::Keyboard::isKeyPressed(sf::Keyboard::X))||
				(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)))
			{	weirdsSound.play();
			}
			
			
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Tilde))
			{
				tildaSound.play();
			}
			
			
			if ((sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))||
				(sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt))||
				(sf::Keyboard::isKeyPressed(sf::Keyboard::LSystem))||
				(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))||
				(sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))||
				(sf::Keyboard::isKeyPressed(sf::Keyboard::RControl)))
			{
				auxButtonsSound.play();
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
