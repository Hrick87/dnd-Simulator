#include "Character.h"
#include <iostream>

Character::Character(std::vector<std::string> characterInfo)
{
	std::cout << "Making character\n";

	if(characterInfo[0] == "Character Summary")
	{
		unsigned long int i = 0;

		for(i = 2; characterInfo[i] != "Stats"; i + 2)
		{	
			characterSum.insert( { characterInfo[i], characterInfo[i + 1] } );
		}

		i++;

		for(;characterInfo[i] != "Skills"; i + 2)
		{
			stats.insert( { characterInfo[i], std::stoi(characterInfo[i + 1]) } );
		}

		i++;
		for(;characterInfo[i] != "Passive Wisdom"; i + 2)
		{
			skills.insert( { characterInfo[i], std::stoi(characterInfo[i + 1]) } );
		}

		i++;
		for(i; characterInfo[i] != "Hit Dice"; i + 2)
		{
			skills.insert( { characterInfo[i], std::stoi(characterInfo[i + 1]) } );
		}

		i++;
		for(i; characterInfo[i] != "Death Saves"; i + 2)
		{
			hitDice.insert( { characterInfo[i], characterInfo[i + 1] } );
		}

		i++;
		for(i; characterInfo[i] != "Attacks"; i + 2)
		{
			deathSaves.insert( { characterInfo[i], std::stoi(characterInfo[i + 1]) } );
		}

		i++;

		bool spellCast = false;
		for(i; characterInfo[i] != "Spellcasting";) //BEGIN INSERTING ATTACKS
		{
			if(characterInfo[i] == "Name")
			{
				std::vector<std::string> attVec;
				int j = 0;
				bool secondLoop = false;
				spellCast = false;
				//START AT ATTACK NAME, END WHEN AT NEXT ATTACK OR AT SPELLCASTING
				for(j = i; ; j + 2)
				{
					if(secondLoop)
					{
						if(characterInfo[j] == "Name" || characterInfo[j] == "Spellcasting")
						{
							if(characterInfo[j] == "Spellcasting")
							{
								spellCast = true;
							}

							break;
						}
					}

					attVec.push_back(characterInfo[j + 1]);	
					secondLoop = true;
				}

				Attack tempAttack(attVec);
				
				if(spellCast == false)
				{
					attacks.insert( { characterInfo[i + 1], tempAttack } );
				}

				attVec.clear();	
				i = j;
			}

		}

		i++;
		for(i; characterInfo[i] != "Equipment (Number of)"; i + 2)
		{
			std::vector<std::string> spellVec;
			Spell tempSpell = Spell(spellVec); //Create spell based on name

			spells.insert( { characterInfo[i], tempSpell } );
		}

		i++;
		for(i; characterInfo[i] != "Features and Traits"; i + 2)
		{
			std::vector<std::string> tempItem;
			Item anItem = Item(tempItem);
			inventory.insert( { characterInfo[i], anItem } );
		}

		i++;
		for(i; characterInfo[i] != "Character Lore"; i + 2)
		{
			featAndTrait.insert( { characterInfo[i], characterInfo[i + 1] } );
		}

		i++;
		for(; i < characterInfo.size(); i + 2)
		{
			characterLore.insert( { characterInfo[i], characterInfo[i + 1] } );
		}

	}
	else
	{
		std::cerr << "Character Summary not found\n";
	}
}

Character::~Character()
{
}
