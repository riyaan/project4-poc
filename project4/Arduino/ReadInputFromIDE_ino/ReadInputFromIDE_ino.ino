#include "common.h"
#include "systemController.h"
#include "sensorController.h"
#include "productController.h"
#include "costController.h"
#include "displayController.h"

int failedTries=0;

SensorController sensorController;
ProductController productController;
CostController costController;
DisplayController displayController;

void setup()
{
  Serial.begin(9600);//Prepare serial port for use
  
  Serial.println("Initializing... ");
  
  // SystemController Initialization
  Initialize(sensorController, productController);
  
  if(sensorController.GetState())
  {
    Serial.println("Sensor controller initialized");
  };
  
  if(productController.GetState())
  {
    Serial.println("Product controller initialized");
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
  
  Serial.print("Two times ");
  Serial.print(input);
  Serial.print(" is ");
  
  input = input * 2;
  
  Serial.println(input);
}

/*
End loop
*/
