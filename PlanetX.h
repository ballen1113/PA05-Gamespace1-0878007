//------------------------------------------------------------------------------
//PlanetX : derived class definition, base class GameSpace
//------------------------------------------------------------------------------
#include "GameSpace.hpp"
#ifndef PLANETX_H
#define PLANETX_H

/*******************************************************************************
	* other classes use planetX, so these keep it from being defined more than once
/******************************************************************************/


class PlanetX : public GameSpace
	//------------------------------------------------------------------------------
{
private:
public:
	PlanetX();

	void print();
	void print(const std::string& message);

	/*******************************************************************************
		* added this to remove entities. it seemed like the only way I could do this 
		* properly
	/******************************************************************************/
	void removeEntity(size_t index) {
		vEntities.erase(vEntities.begin() + index);
	}
};

#endif