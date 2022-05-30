#include <vector>
#include <string>

class Item
{
	public:
		Item(std::vector<std::string> tempItem);
		~Item();
	private:
		int amount;
		int attBonus;
		bool weapon;
		bool equipped;
		std::string damageType;
		std::string name;
		std::string description;
		std::string special;
};
