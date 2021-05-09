#pragma once
#ifndef _CIPHERS_H_
#define _CIPHERS_H_

#include <iostream>
#include <vector>
#include <fstream>

namespace ciphers
{
	enum class e_Choice
	{
		ENCODE, DECODE
	};

	void Caeser(std::vector<char> inputText, std::vector<char>& output, short shift = 3, e_Choice choice = e_Choice::ENCODE);
	void Caeser(std::vector<char> inputText, std::ofstream& output, short shift = 3, e_Choice choice = e_Choice::ENCODE);

	void Vigenere(std::vector<char> inputText, std::vector<char>& output, std::vector<char> shift, e_Choice choice = e_Choice::ENCODE);
	void Vigenere(std::vector<char> inputText, std::ofstream& output, std::vector<char> shift, e_Choice choice = e_Choice::ENCODE);

	void Atbash(std::vector<char> inputText, std::vector<char>& output);
	void Atbash(std::vector<char> inputText, std::ofstream& output);
}
#endif