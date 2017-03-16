#ifndef COSMOS_QUERY_SERVICE_H
#define COSMOS_QUERY_SERVICE_H

#include "../Common.h"
#include "../Entity/Entity.h"

class CosmosQueryService
{
public:
	CosmosQueryService();
	virtual ~CosmosQueryService();

	virtual Entity* QuerySystemStructure(const std::string &name) = 0;
	virtual Entity* QuerySystemMembership(const std::string &name) = 0;
};

#endif
