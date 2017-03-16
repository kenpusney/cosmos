#ifndef IDENTIFIED_ENTITY_H
#define IDENTIFIED_ENTITY_H

#include "../Common.h"
#include "Entity.h"

class IdentifiedEntity : public Entity
{
public:
	IdentifiedEntity(int id, const std::string &name);

	int ID() const;
	void SetID(int id);

private:
	int _id;
};

#endif
