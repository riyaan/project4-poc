#include "costController.h"
#include <Logging.h>

CostController::CostController() 
{
	Log.Info("Cost Controller constructor");	
}

void CostController::Initialize()
{
  Log.Info("CostController - Initialize"CR);
  SetState(true);
  SessionTotalCost = 0;
}

void CostController::IncrementSessionTotalCost(int cost)
{
	SessionTotalCost += cost;
}

void CostController::DecrementSessionTotalCost(int cost)
{
	if(cost > SessionTotalCost)
		SessionTotalCost = 0;
	else
		SessionTotalCost -= cost;
}