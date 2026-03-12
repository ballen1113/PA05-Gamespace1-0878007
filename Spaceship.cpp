#include "Spaceship.h"

Spaceship::Spaceship()
{
	name = "Planet Express";
	description = "A delivery vessel designed to transport cargo from Earth to across the entire galaxy";


    //Pre-existing entities
    addEntity({ "Captain Turanga Leela", 10 });
    addEntity({ "Delivery Intern Barb", 10 });
    addEntity({ "Dr. Zoidberg" });
};
void Spaceship::print()
{
    //spaceship-specific console output here
    std::cout << name << " is a spaceship that will travel to Chapek 9 on an organic life rescue mission.\n";
    std::cout << "Here is more about " << name << ": \n" << description << std::endl;
    std::cout << name << " has " << getEntityCount() << " passengers.\n"; 
    std::cout << "-----------------------------------------------------------------------------------------------\n";
  
}

void Spaceship::print(const std::string& message)
{
    std::cout << name << " is a " << description << ".\n";
    print(); 
}
