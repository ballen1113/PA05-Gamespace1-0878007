//------------------------------------------------------------------------------
// PlanetX : derived class definition, base class GameSpace
//------------------------------------------------------------------------------
#include "GameSpace.hpp"

class PlanetX : public GameSpace
//------------------------------------------------------------------------------
{
private:
public:
	PlanetX();

	void print();
	void print(const std::string& message);
};