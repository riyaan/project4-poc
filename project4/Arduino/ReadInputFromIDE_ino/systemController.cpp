#include <Logging.h>

#include "systemController.h"
#include "sensorController.h"
#include "productController.h"
#include "costController.h"
#include "displayController.h"

bool Initialize(SensorController & sc, ProductController & pc, CostController & cc)
{
  Log.Info("SystemController - Initialize"CR);

  sc.Initialize();
  pc.Initialize();
  cc.Initialize();
  
  return true;
}
