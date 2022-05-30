#include <map>
#include "Item.h"
#include <vector>
#include "Attack.h"
#include "Spell.h"
#include <string>

class Character
{
	public:
		Character(std::vector<std::string> characterInfo);
		~Character();
	private:
		std::map<std::string, Item> inventory; //<itemName, itemObj> Items store the amount in case of duplicates
		std::map<std::string, std::string> characterLore; //<label, description> for more in depth character lore 
		std::map<std::string, int> stats; //<strength, 14>
		std::map<std::string, std::string> hitDice; //Keeps track of hitdice character uses
		std::map<std::string, std::string> characterSum; //Brief overview of the character
		std::map<std::string, int> savingThrows; //<strength, 5>
		std::map<std::string, int> skills; //<acrobatics, -2>
		std::map<std::string, int> deathSaves; //<success, 1> 
		std::map<std::string, Attack> attacks;//<nameOfAttack, attackObj>
		std::map<std::string, Spell> spells;//<nameOfSpell, spellObj>
		std::map<std::string, std::string> featAndTrait; //<nameOfFeature, description>

		int passiveWisdom;
		int hitDiceTotal;
};
