#include <iostream>
#include <string>
#include <msclr\marshal_cppstd.h>
#include <algorithm>

#pragma once
ref class Traanslator
{

public:
	Traanslator();
	static std::string toText(std::string Morse);
	static std::string toMorse(std::string Text);
};

