#include <iostream>
#include <string>

using namespace std;

// Base class GameStructure
class GameStructure {
public:
	// Pure virtual function to be overriden by drived classes
	virtual void Help() = 0;
};

// Character class inheriting from GameStructure
class Character : public GameStructure {
public:
	string Name; // Public property for the name

	// Getter for the private property health
	int getHealth() {
		return Health;
	}

	// Setter for the private property health
	void setHealth(int newHealth) { // If Health is less than zero
		if (newHealth < 0) { // Set health to 0
			Health = 0;
			cout << Name << " has Expired..." << endl; // Notify that character is expired
		}
		else {
			Health = newHealth; // Set health to new value
		}
	}

	// Overloaded Talk method: Outputs name and stuff to say
	void Talk(string stuffToSay) {
		cout << Name << " says: " << stuffToSay << endl;
	}

	// Overloaded Talk method with name and message
	void Talk(string name, string stuffToSay) {
		cout << name << " says: " << stuffToSay << endl;
	}

	// Virtual attack method that returns 10 hit points
	virtual int Attack() {
		return 10;
	}

	// Override Help method in Character Class (does nothing here)
	void Help() override {}

protected:
	int Health; // Private property for health
};

// Ninja class inheriting from Character
class Ninja : public Character {
public:
	// Constructor to initialize name and health for Ninja
	Ninja(string name, int health) {
		Name = name;
		setHealth(health);
	}

	// Method for Ninja to throw stars
	void ThrowStars() {
		cout << "I am throwing stars!" << endl;
	}

	// Override attack method, Ninja delas 25 hit points
	int Attack() override {
		return 25;
	}

	// Override Help method for Ninja
	void Help() override {
		cout << "Ninja's are really cool, you can use them to throw stars!" << endl;
	}
};

// Pirate class inheriting from Character
class Pirate : public Character {
public:
	// Constructor to initialize name and health for Pirate
	Pirate(string name, int health) {
		Name = name;
		setHealth(health);
	}

	// Method for Pirate to use sword
	void UseSword() {
		cout << "I am Swooshing my Sword!" << endl;
	}

	// Overide attack method, Pirate deals 25 hit points
	int Attack() override {
		return 25;
	}

	// Override Help method for Pirate
	void Help() override {
		cout << "Pirates are fearless, you can use them to swoosh swords!" << endl;
	}
};

// Function to display the game's introduction
void gameIntro() {
	cout << "---------------------------------" << endl;
	cout << "Welcome to Pirates vs Ninjas Game!" << endl;
	cout << "---------------------------------" << endl;
}

// Function to simulate battle between Ninja and Pirate
void battle(Ninja& ninja, Pirate& pirate) {
	while (ninja.getHealth() > 0 && pirate.getHealth() > 0) {
		cout << "\nNinja attacks Pirate!" << endl;
		pirate.setHealth(pirate.getHealth() - ninja.Attack());
		cout << "Pirate's health: " << pirate.getHealth() << endl;

		if (pirate.getHealth() <= 0) {
			cout << "Pirate has been defated! Ninja Wins!" << endl;
			return; // End the game when Pirate dies
		}

		cout << "\nPirate attacks Ninja!" << endl;
		ninja.setHealth(ninja.getHealth() - pirate.Attack());
		cout << "Ninja's health: " << ninja.getHealth() << endl;

		if (ninja.getHealth() <= 0) {
			cout << "Ninja has been defeated! Pirate Wins!" << endl;
			return; // End the game when Ninja dies
		}
	}
}

// Main function with game loop and interaction
int main() {
	gameIntro(); // Display the game intro

	// Create a Ninja and Pirate instance
	Ninja ninja("shadow", 100);
	Pirate pirate("Blackbeard", 100);


    bool keepPlaying = true; // Boolean to control game loop


	while (keepPlaying) {
		cout << "\nChoose a character: " << endl;
		cout << "1. Ninja\n2. Pirate\n3. Battle\n4. Exit\n";
		int choice;
		cin >> choice;

		if (choice == 1) {
			cout << "You chose Ninja!" << endl;
			ninja.Talk("shadow", "Prepare to face my stars!");
			ninja.ThrowStars();
			ninja.Help();
		}
		else if (choice == 2) {
			cout << "You chose Pirate!" << endl;
			pirate.Talk("Blackbeard", "Prepare to taste my sword!");
			pirate.UseSword();
			pirate.Help();
		}
		else if (choice == 3) {
			// Initiate the battle
			battle(ninja, pirate);
			keepPlaying = false; // End the game after the battle
		}
		else if (choice == 4) {
			cout << "Exiting game... Goodbye!" << endl;
			keepPlaying = false; // Exit game loop
		}
		else {
			cout << "Invalid choice, try again!" << endl;
		}
	}

	return 0;
}