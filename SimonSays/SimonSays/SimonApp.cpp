#include "SimonApp.h"



void SimonApp::Draw()
{
	rlUtilJMApp::Draw();
	red->draw();
	green->draw();
	blue->draw();
	yellow->draw();
}

void SimonApp::Start()
{
	red = new Entity(RLBACKGROUND, 20, 20);
	green = new Entity(RLBACKGROUND, 10, 40);
	blue = new Entity(RLBACKGROUND, 50, 40);
	yellow = new Entity(RLBACKGROUND, 20, 80);
	spriteRed = rlUtilJM::InitSpriteArray(20, 40);
	spriteBlue = rlUtilJM::InitSpriteArray(40, 20);
	colorRed = BBASERED;
	colorBlue = BBASEBLUE;
	colorGreen = BBASEGREEN;
	colorYellow = BBASEYELLOW;
	for (int i = 40; i--;)
	{
		for (int j = 20; j--;) 
		{
			spriteRed[j][i] = spriteBlue[i][j] = BACKGROUND1;
		}
	}
	red->InitSprite(40, 20);
	green->InitSprite(20, 40);
	yellow->InitSprite(40, 20);
	blue->InitSprite(20, 40);
	red->setIsStatic(true);
	green->setIsStatic(true);
	yellow->setIsStatic(true);
	red->setIsStatic(true);
	red->setColors(ALPHACOLOR, ALPHACOLOR, ALPHACOLOR, ALPHACOLOR);
	red->setLetters('\0', '\0', '\0', '\0');
	red->setBackgrounds(colorRed, BBASERED, BBASERED, BBASERED);
	red->setSprite(spriteRed);
	blue->setColors(ALPHACOLOR, ALPHACOLOR, ALPHACOLOR, ALPHACOLOR);
	blue->setLetters('\0', '\0', '\0', '\0');
	blue->setBackgrounds(colorBlue, BBASERED, BBASERED, BBASERED);
	blue->setSprite(spriteBlue);
	green->setColors(ALPHACOLOR, ALPHACOLOR, ALPHACOLOR, ALPHACOLOR);
	green->setLetters('\0', '\0', '\0', '\0');
	green->setBackgrounds(colorGreen, BBASERED, BBASERED, BBASERED);
	green->setSprite(spriteBlue);
	yellow->setColors(ALPHACOLOR, ALPHACOLOR, ALPHACOLOR, ALPHACOLOR);
	yellow->setLetters('\0', '\0', '\0', '\0');
	yellow->setBackgrounds(colorYellow, BBASERED, BBASERED, BBASERED);
	yellow->setSprite(spriteRed);
	rlUtilJM::ShouldClearScreen(true);
	rlUtilJMApp::Start();
}

void SimonApp::Update()
{
	rlUtilJMApp::Update();
	r = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
	g = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
	b = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
	y = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
	colorRed = r ? BBASELIGHTRED : BBASERED;
	colorGreen = g ? BBASELIGHTGREEN : BBASEGREEN;
	colorBlue = b ? BBASELIGHTBLUE : BBASEBLUE;
	colorYellow = y ? BBASEYELLOW : BBASEBROWN;
	yellow->setBackgrounds(colorYellow, BBASERED, BBASERED, BBASERED);
	green->setBackgrounds(colorGreen, BBASERED, BBASERED, BBASERED);
	blue->setBackgrounds(colorBlue, BBASERED, BBASERED, BBASERED);
	red->setBackgrounds(colorRed, BBASERED, BBASERED, BBASERED);
	if (!isPressed && (r || g || b || y))
	{
		isPressed = true;
		if (r)
		{
			rlUtilJM::PlaySoundEffect(rSound, 100);
		}
		if (g)
		{
			rlUtilJM::PlaySoundEffect(gSound, 100);
		}
		if (b)
		{
			rlUtilJM::PlaySoundEffect(bSound, 100);
		}
		if (y) 
		{
			rlUtilJM::PlaySoundEffect(ySound, 100);
		}
	}
	else if (isPressed && !(r || g || b || y)) isPressed = false;
	if (!(++count %= 3)) rlUtilJM::ForceClearScreen();
}
