#include <Logging.h>

#include "common.h"
#include "systemController.h"
#include "sensorController.h"
#include "productController.h"
#include "costController.h"
#include "displayController.h"

#define LOGLEVEL LOG_LEVEL_DEBUG

int failedTries=0;
const int BAUD_RATE = 9600;

SensorController sensorController;
ProductController productController;
CostController costController;
DisplayController displayController;

void setup()
{             
  Serial.begin(BAUD_RATE);//Prepare serial port for use
   
  Log.Init(LOGLEVEL, BAUD_RATE);
  Log.Info("Setup... "CR);
  
  // SystemController Initialization
  Initialize(sensorController, productController);
  
  if(sensorController.GetState())
  {
    Log.Info("SensorController initialized"CR);
  };
  
  if(productController.GetState())
  {
    Log.Info("Product controller initialized"CR);
  };
}

/*
Begin loop
*/
void loop()
{
  int input=0;
  failedTries=0;
  
  //do nothing (except continue to check) until something has been sent.
  while (Serial.available() == 0) {;};
  
  while ((Serial.available() > 0) || (failedTries < 1000))
  {
    int *p=&failedTries;
    int incomingByte = AsciiToBinary(Serial.read());
    input = FetchNextCharacterAndAddToAccumulator(incomingByte, input, p);
  };  
  
  Log.Debug("Input: %d"CR, input);
  
  if(productController.AddProduct(input, "Linctagon Nasal Spray", 78.99))
    Log.Info("Successfully added product"CR);
  else
    Log.Info("Failed to add the product."CR);
  
  //Serial.print("Two times ");
  //Serial.print(input);
  //Serial.print(" is ");
  
  //input = input * 2;
  
  //Serial.println(input);
}

/*
End loop
*/
