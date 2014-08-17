#include <Logging.h>
#include "sensorController.h"

SensorController::SensorController()
{;}

void SensorController::Initialize()
{
  Log.Info("Begin SensorController Initializing... "CR);
  
  SetState(true);
}
