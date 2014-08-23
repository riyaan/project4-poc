#include <Logging.h>

#include "systemController.h"
#include "sensorController.h"
#include "productController.h"
#include "costController.h"
#include "displayController.h"

bool Initialize(SensorController & sc, ProductController & pc)
{
  Log.Info("SystemController - Initialize"CR);

  sc.Initialize();
  pc.Initialize();
  
  return true;
}
