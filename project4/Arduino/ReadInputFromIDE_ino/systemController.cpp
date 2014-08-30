#include <Logging.h>

#include "systemController.h"
#include "sensorController.h"
#include "productController.h"
#include "costController.h"
#include "displayController.h"
#include "rfidController.h"

bool Initialize(SensorController & sc, ProductController & pc, CostController & cc, RfidController & rc)
{
  Log.Info("SystemController - Initialize"CR);

  sc.Initialize();
  pc.Initialize();
  cc.Initialize();
  rc.Initialize();
  
  return true;
}
