#include "sensorController.h"
#include "productController.h"
#include "costController.h"
#include "rfidController.h"

#ifndef systemController_h
#define systemController_h

bool Initialize(SensorController & sc, ProductController & pc, CostController & cc, RfidController & rc);

#endif
