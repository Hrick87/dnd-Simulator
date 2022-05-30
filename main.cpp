#include <iostream>
#include <filesystem>
#include <fstream>
#include "Character.h"
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool foundComma(char c)
{
	switch(c)
	{
		case ',':
			return true;
		default:
			return false;
	}
}

void loadCharacters()
{
	string path_to_dir = "Character_Sheets/";

	//FINDS ALL CHARCTER SHEETS FOR GAME
	for(const auto &entry : std::filesystem::directory_iterator(path_to_dir))
	{
		cout << entry.path() << endl;
		fstream charSheet;
		charSheet.open(entry.path());

		if(!charSheet) 
		{
			cout << "File not found";
		}
		else 
		{
			cout << "File found!";
		}

		std::vector<string> characterInfo;
		string tempStr = "";	

		while(tempStr != "Stats")
		{
			charSheet >> tempStr;
			tempStr.erase(remove_if(tempStr.begin(), tempStr.end(), &foundComma), tempStr.end());
			characterInfo.push_back(tempStr);
		}
		
		while(tempStr != "Saving Throws")
		{
			charSheet >> tempStr;
			tempStr.erase(remove_if(tempStr.begin(), tempStr.end(), &foundComma), tempStr.end());
			characterInfo.push_back(tempStr);
		}
		
		while(tempStr != "Skills")
		{
			charSheet >> tempStr;
			tempStr.erase(remove_if(tempStr.begin(), tempStr.end(), &foundComma), tempStr.end());
			characterInfo.push_back(tempStr);
		}
		
		while(tempStr != "Passive Wisdom")
		{
			charSheet >> tempStr;
			tempStr.erase(remove_if(tempStr.begin(), tempStr.end(), &foundComma), tempStr.end());
			characterInfo.push_back(tempStr);
		}
		
		while(tempStr != "Hit Dice")
		{
			charSheet >> tempStr;
			tempStr.erase(remove_if(tempStr.begin(), tempStr.end(), &foundComma), tempStr.end());
			characterInfo.push_back(tempStr);
		}

		while(tempStr != "Death Saves")
		{
			charSheet >> tempStr;
			tempStr.erase(remove_if(tempStr.begin(), tempStr.end(), &foundComma), tempStr.end());
			characterInfo.push_back(tempStr);
		}
		
		while(tempStr != "Attacks")
		{
			charSheet >> tempStr;
			tempStr.erase(remove_if(tempStr.begin(), tempStr.end(), &foundComma), tempStr.end());
			characterInfo.push_back(tempStr);
		}
		
		while(tempStr != "Spellcasting")
		{
			charSheet >> tempStr;
			tempStr.erase(remove_if(tempStr.begin(), tempStr.end(), &foundComma), tempStr.end());
			characterInfo.push_back(tempStr);
		}
		
		while(tempStr != "Equipment (Number of)")
		{
			charSheet >> tempStr;
			tempStr.erase(remove_if(tempStr.begin(), tempStr.end(), &foundComma), tempStr.end());
			characterInfo.push_back(tempStr);
		}
		
		while(tempStr != "Features and Traits")
		{
			charSheet >> tempStr;
			tempStr.erase(remove_if(tempStr.begin(), tempStr.end(), &foundComma), tempStr.end());
			characterInfo.push_back(tempStr);
		}
		
		while(tempStr != "Character Lore")
		{
			charSheet >> tempStr;
			tempStr.erase(remove_if(tempStr.begin(), tempStr.end(), &foundComma), tempStr.end());
			characterInfo.push_back(tempStr);
		}

		while(charSheet >> tempStr)
		{
			tempStr.erase(remove_if(tempStr.begin(), tempStr.end(), &foundComma), tempStr.end());
			characterInfo.push_back(tempStr);
		}

		Character * player = new Character(characterInfo);	

		charSheet.close();
	}
}

int main()
{

	loadCharacters();

	return 0;
}
