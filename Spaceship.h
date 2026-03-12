#include "GameSpace.hpp"
//GameSpace is in a source folder bc its a copied repo

class Spaceship : public GameSpace
{
private:
	int speed;
	bool inOrbit;
public:
	Spaceship();
	bool getOrbitStatus();
	int getSpd();
	void print();
	void print(const std::string& message);
};

