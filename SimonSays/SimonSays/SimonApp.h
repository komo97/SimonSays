#pragma once
#include <rlutil\rlutilJMApp.h>
#include <rlutil\rlutilJM.h>
#include <rlutil\Entity.h>
#include <vector>
class SimonApp : public rlUtilJMApp
{

private:
	void Draw() final;
	void Start() final;
	void Update() final;
	Entity* red, *green, *blue, *yellow;
	int** spriteRed, ** spriteGreen, ** spriteBlue, ** spriteYellow;
	int count = 0;
	int colorRed, colorGreen, colorBlue, colorYellow;
	bool r, g, b, y;
	const char* rSound = "data/a_sharp.wav", *gSound = "data/c_sharp.wav",
		*bSound = "data/d_sharp.wav", *ySound = "data/f_sharp.wav";
	bool isPressed = false;
	std::vector<int> presses, simonPresses;
};

