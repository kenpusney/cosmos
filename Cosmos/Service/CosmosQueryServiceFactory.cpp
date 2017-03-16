#include "../Common.h"
#include "CosmosQueryServiceFactory.h"
#include "DefaultCosmosQueryService.h"

CosmosQueryServiceFactory::CosmosQueryServiceFactory(MYSQL *dataSource)
	: _dataSource(dataSource)
{
}

CosmosQueryServiceFactory::~CosmosQueryServiceFactory()
{
	if (_dataSource)
		mysql_close(_dataSource);
}

CosmosQueryService* CosmosQueryServiceFactory::GetQueryService()
{
	return new DefaultCosmosQueryService(_dataSource);
}
