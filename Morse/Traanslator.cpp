#include "Traanslator.h"

Traanslator::Traanslator()
{
}

std::string EngAlphabet = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '.', ',' };
std::string MorseAlphabet[30] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".-.-.-", "--..--" };

std::string Traanslator::toMorse(std::string Text)
{
	std::string Morse;

	std::transform(Text.begin(), Text.end(), Text.begin(), ::toupper);
	for (unsigned i = 0; i < Text.length(); ++i)
	{
		for (int counter = 0; counter < 30; counter++)
		{
			if (Text.at(i) == EngAlphabet[counter])
			{
				Morse += MorseAlphabet[counter] + ' ';
				break;
			}
		}
	}
	return Morse;
}

std::string Traanslator::toText(std::string Morse)
{
	std::string Text;

	for (unsigned i = 0; i < Morse.length(); ++i)
	{
		std::string token = Morse.substr(i, Morse.find(' '));
		token = token.substr(0, token.find(' '));
		for (int counter = 0; counter < 30; counter++)
		{
			if (token == MorseAlphabet[counter])
			{
				Text += EngAlphabet[counter];
				i += token.length();
				break;
			}
		}
	}
	return Text;
}