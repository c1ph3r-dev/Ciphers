#include "../../include/ciphers.h"

const std::vector<char> alphabetLC = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
const std::vector<char> alphabetUC = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

namespace ciphers
{
	void Caeser(std::vector<char> inputText, std::vector<char>& output, short shift, e_Choice choice)
	{
		bool c;	
		switch (choice)
		{
		default:
			c = true;
			break;
		case e_Choice::ENCODE:
			c = true;
			break;
		case e_Choice::DECODE:
			c = false;
		}

		if (shift < 0)
			shift *= -1;

		unsigned long long size = 0;
		if (c)
		{
			while (shift < 0 || shift > 26)
			{
				if (shift < 0)
				{
					shift = shift * -1;
					shift = 26 - shift;
				}
				else 
				{
					shift = shift - 26;
				}
			}
		}
		else
		{
			shift = 26 - shift;
			while (shift < 0 || shift > 26)
			{
				if (shift < 0)
				{
					shift = shift * -1;
					shift = 26 - shift;
				}
				else
				{
					shift = shift - 26;
				}
			}
		}

		for (int x = 0; x < inputText.size(); x++)
		{
			int val;
			bool lCase;
			
			for (int y = 0; y < 26; y++)
			{
				if (inputText[x] == alphabetLC[y])
				{
					lCase = true;
					if (y + shift > 25)
					{
						val = (y + shift) - 26;
					}
					else
					{
						val = y + shift;
					}
					break;
				}

				if (inputText[x] == alphabetUC[y])
				{
					lCase = false;
					if (y + shift > 25)
					{
						val = (y + shift) - 26;
					}
					else
					{
						val = y + shift;
					}
					break;
				}
			}

			if (lCase)
			{
				output.push_back(alphabetLC[val]);
			}
			else
			{
				output.push_back(alphabetUC[val]);
			}
		}
	}

	void Caeser(std::vector<char> inputText, std::ofstream& output, short shift, e_Choice choice)
	{
		std::vector<char> temp;

		if (!output.is_open())
		{
			throw std::runtime_error("Please open file before calling this function!");
		}

		bool c;
		switch (choice)
		{
		default:
			c = true;
			break;
		case e_Choice::ENCODE:
			c = true;
			break;
		case e_Choice::DECODE:
			c = false;
		}

		if (shift < 0)
			shift *= -1;

		unsigned long long size = 0;
		if (c)
		{
			while (shift < 0 || shift > 26)
			{
				if (shift < 0)
				{
					shift = shift * -1;
					shift = 26 - shift;
				}
				else
				{
					shift = shift - 26;
				}
			}
		}
		else
		{
			shift = 26 - shift;
			while (shift < 0 || shift > 26)
			{
				if (shift < 0)
				{
					shift = shift * -1;
					shift = 26 - shift;
				}
				else
				{
					shift = shift - 26;
				}
			}
		}

		for (int x = 0; x < inputText.size(); x++)
		{
			int val;
			bool lCase;

			for (int y = 0; y < 26; y++)
			{
				if (inputText[x] == alphabetLC[y])
				{
					lCase = true;
					if (y + shift > 25)
					{
						val = (y + shift) - 26;
					}
					else
					{
						val = y + shift;
					}
					break;
				}

				if (inputText[x] == alphabetUC[y])
				{
					lCase = false;
					if (y + shift > 25)
					{
						val = (y + shift) - 26;
					}
					else
					{
						val = y + shift;
					}
					break;
				}
			}

			if (lCase)
			{
				temp.push_back(alphabetLC[val]);
			}
			else
			{
				temp.push_back(alphabetUC[val]);
			}
		}

		for (int i = 0; i < temp.size(); i++) 
		{
			output << temp[i];
		}
	}

	static char Logic(char letter, unsigned short shift, bool encode)
	{
		char res;
		unsigned short val;
		bool lCase;

		if (!encode)
		{
			shift = 26 - shift;
			while (shift < 0 || shift > 26)
			{
				if (shift < 0)
				{
					shift = shift * -1;
					shift = 26 - shift;
				}
			}
		}

		for (int y = 0; y < 26; y++)
		{
			if (letter == alphabetLC[y])
			{
				lCase = true;
				if (y + shift > 25)
				{
					val = (y + shift) - 26;
				}
				else
				{
					val = y + shift;
				}
				break;
			}

			if (letter == alphabetUC[y])
			{
				lCase = false;
				if (y + shift > 25)
				{
					val = (y + shift) - 26;
				}
				else
				{
					val = y + shift;
				}
				break;
			}
		}

			if (lCase)
			{
				res = alphabetLC[val];
			}
			else
			{
				res = alphabetUC[val];
			}
			return res;		
	}

	void Vigenere(std::vector<char> inputText, std::vector<char>& output, std::vector<char> shift, e_Choice choice)
	{
		bool c;
		switch (choice)
		{
		default:
			c = true;
			break;
		case e_Choice::ENCODE:
			c = true;
			break;
		case e_Choice::DECODE:
			c = false;
		}

		std::vector<short> shiftNum;

		for (int i = 0; i < shift.size(); i++)
		{
			for (int j = 0; j < 26; j++)
			{
				if (shift[i] == alphabetLC[j])
				{
					shiftNum.push_back(j);
					break;
				}
			}
		}

		unsigned short count = 0;
		for (int i = 0; i < inputText.size(); i++)
		{
			output.push_back(Logic(inputText[i], shiftNum[count], c));
			count++;
			if (count == shift.size())
			{
				count = 0;
			}
		}
	}

	void Vigenere(std::vector<char> inputText, std::ofstream& output, std::vector<char> shift, e_Choice choice)
	{
		if (!output.is_open())
		{
			throw std::runtime_error("Please open file before calling this function!");
		}

		bool c;
		switch (choice)
		{
		default:
			c = true;
			break;
		case e_Choice::ENCODE:
			c = true;
			break;
		case e_Choice::DECODE:
			c = false;
		}

		std::vector<short> shiftNum;

		for (int i = 0; i < shift.size(); i++)
		{
			for (int j = 0; j < 26; j++)
			{
				if (shift[i] == alphabetLC[j])
				{
					shiftNum.push_back(j);
					break;
				}
			}
		}

		unsigned short count = 0;
		for (int i = 0; i < inputText.size(); i++)
		{
			output << Logic(inputText[i], shiftNum[count], c);
			count++;
			if (count == shift.size())
			{
				count = 0;
			}
		}
	}

	void Atbash(std::vector<char> inputText, std::vector<char>& output)
	{
		char reverse[26];

		while (true)
		{
			unsigned short j = 25;
			for (int i = 0; i < 26; i++)
			{
				reverse[i] = alphabetLC[j];
				j--;
			}
			break;
		}

		for (int x = 0; x < inputText.size(); x++)
		{
			int loc;
			for (int y = 0; y < 26; y++)
			{
				if (inputText[x] == alphabetLC[y])
				{
					loc = y;
					break;
				}
			}
			output.push_back(reverse[loc]);
		}
	}

	void Atbash(std::vector<char> inputText, std::ofstream& output)
	{
		if (!output.is_open())
		{
			throw std::runtime_error("Please open file before calling this function!");
		}

		char reverse[26];

		while (true)
		{
			unsigned short j = 25;
			for (int i = 0; i < 26; i++)
			{
				reverse[i] = alphabetLC[j];
				j--;
			}
			break;
		}

		for (int x = 0; x < inputText.size(); x++)
		{
			int loc;
			for (int y = 0; y < 26; y++)
			{
				if (inputText[x] == alphabetLC[y])
				{
					loc = y;
					break;
				}
			}
			output << reverse[loc];
		}
	}
}