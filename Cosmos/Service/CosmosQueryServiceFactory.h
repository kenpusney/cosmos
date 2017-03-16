#ifndef COSMOS_QUERY_SERVICE_FACTORY_H
#define COSMOS_QUERY_SERVICE_FACTORY_H

#include "../Common.h"
#include "CosmosQueryService.h"

class CosmosQueryServiceFactory
{
public:
	CosmosQueryServiceFactory(MYSQL *dataSource);
	~CosmosQueryServiceFactory();

	CosmosQueryService* GetQueryService();

private:
	CosmosQueryServiceFactory(CosmosQueryServiceFactory&);
	CosmosQueryServiceFactory& operator=(const CosmosQueryServiceFactory&);

private:
	MYSQL *_dataSource;
};

#endif
