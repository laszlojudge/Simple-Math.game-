#include <iostream>
#include <time.h>

// Just a little demonstrate where i stand and what i learn now.
// Wasn't really checking for fast code.. just run something as my first Github upload =)


class Player
{
private:
public:
	std::string name;
	int health;
	int hitpoint;
	bool is_dead;
public:
	Player(std::string char_name, int hp, int hitp, bool dead = false)
	:name{char_name}, health{hp}, hitpoint{hitp}{

	}
};

std::string Welcome_program()
{
	std::cout << "Welcome to my program!" << std::endl;
	std::cout << "It's a simple math program to kill an enemy." << std::endl;
	std::cout << "Choose your name: ";
	std::string name;
	std::cin >> name;
	return name;
}
void Welcome_character(const std::string name, int& health, int& hitpoint)
{
	int input;
	std::cout << "Hello there, " << name << "!" << std::endl;
	std::cout << "Now we set your health." << std::endl;
	std::cout << "Choose the correct answer!" << std::endl;
	std::cout << "8 * 9 = ";
	std::cin >> input;
	if (input == 72)
		health = 100;
	else 
		health = 85;
	std::cout << "Your health is: " << health << std::endl;
	std::cout << "Now we set your hitpoint!" << std::endl;
	std::cout << "80 % 3 = ";
	std::cin >> input;
	if (input == 2)
		hitpoint = 12;
	else
		hitpoint = 10;
	std::cout << "Your hitpoint is: " << hitpoint << std::endl;
}

int Player_attack(int &hitpoint, int &e_health)
{
	srand (time(NULL));
	int a = rand() % 10 + 1;
	int b = rand() % 10 + 1;
	std::cout << "What is: " << a << " * " << b << ": ";
	int result = 0;
	std::cin >> result;
	if (result == a * b)
	{
		if(e_health < 60)
		{
			std::cout << "Critical damage!!" << std::endl;
			return (rand() % hitpoint + 4) * 2;
		}
		else
		{
			return rand() % hitpoint + 4;
		}
	}
	return (rand() % hitpoint +4) / 2;
}

void Gametable (Player &player, Player &enemy)
{
	srand (time(NULL));
	int result = 0;
	int loss = 0;
	std::cout << "You have to give the correct answers to hit the boss." << std::endl;
	std::cout << "Begin" << std::endl;
	while(player.is_dead != true && enemy.is_dead != true)
	{

		loss = rand() % 13 + 5;
		player.health -= loss;
		if (player.health < 0)
		{
			player.is_dead = true;
			return;
		}
		std::cout << "Boss hit you: -" << loss << " health";
		std::cout << "\tYour health: " << player.health << std::endl;
		result = Player_attack(player.hitpoint, enemy.health);
		enemy.health -= result;
		std::cout << "You hit the boss: -" << result << " damage";
		std::cout << "\tBoss health: " << enemy.health << std::endl; 
		if (enemy.health < 0)
		{
			enemy.is_dead = true;
			return;
		}
	}
}

void sayBye(Player* player, const Player* enemy)
{
	if (enemy -> is_dead){
		std::cout << "You defeated the boss!" << std::endl << "Thanks for playing!" << std::endl;
		std::cout << "Player remaining health: " << player -> health;
	}

	if (player -> is_dead){
		std::cout << "The boss defeated you!" << std::endl << "Thanks for playing and try again!" << std::endl;
		std::cout << "Boss remaining health: " << enemy -> health;
	}
}

int main()
{
	std::string name = Welcome_program();
	int hp = 0, hitpoint = 0;
	Welcome_character(name, hp, hitpoint);
	Player player(name, hp, hitpoint);
	Player enemy("Boss", 110, 13);
	Gametable(player, enemy);
	sayBye(&player, &enemy);
}