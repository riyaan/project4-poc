#include <Logging.h>
#include "sensorController.h"

SensorController::SensorController()
{;}

void SensorController::Initialize()
{
  Log.Info("SensorController - Initialize"CR);
  
  SetState(true);
}
