#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <stdlib.h>

class Warrior{
  private:
    // The name of the Unit
    std::string name;
    // The class of the unit
    // Maybe nest a class in here for different types
    // std::string classType;
    int strength;
    int hitpoints;
    int defense;
    static int numWarriors;

  public:
    std::string getName() { return name; }
    // std::string getClass() { return classType;}
    void setName(std::string name) { this->name = name; }
    void setStr(int strength) { this->strength = strength; }
    void setHP(int hp) { this->hitpoints = hp; }
    void setDef(int def) { this->defense = def; }
    void setAll(std::string, int, int, int);
  // Constructor
  Warrior(std::string, int, int, int);

  // Overloaded constructor
  Warrior();

  // Destructor
  ~Warrior();

  void toString();

  static int getNumWarriors() { return numWarriors; }
};

int Warrior::numWarriors = 0;
void Warrior::setAll(std::string name, int strength, int hitpoints, int defense) {
  this->name = name;
  this->strength = strength;
  this->hitpoints = hitpoints;
  this->defense = defense;
  Warrior::numWarriors++;
}

Warrior::Warrior(std::string name, int strength, int hitpoints, int defense) {
  this->name = name;
  this->strength = strength;
  this->hitpoints = hitpoints;
  this->defense = defense;
  Warrior::numWarriors++;
}

Warrior::Warrior(){
  this->name = "";
  this->strength = 0;
  this->hitpoints = 0;
  this->defense = 0;
}

Warrior::~Warrior() {
  std::cout << "Warrior " << this->name << " destroyed\n";
}

void Warrior::toString(){
  std::cout << this->name << "'s stats:\n" << "Hitpoints: " << this->hitpoints << "\nStrength: " << this->strength << "\nDefense: " << this->defense << std::endl; 
}

class Mage: public Warrior{
  private:
    int magicLevel;
  public:
    int getMagicLvl(int level) { this->magicLevel = level; }
    /*
    void castSpell() {
    }
    */
  }

int main() {
  Warrior thor;
  thor.setName("Thor");
  thor.setHP(100);
  thor.setStr(100);
  thor.setDef(50);
  thor.toString();
  
  Warrior test("Test", 120, 120, 120);
  test.toString();
}
