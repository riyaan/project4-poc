#include <Logging.h>
#include "product.h"
#include "common.h"
#include "systemController.h"
#include "sensorController.h"
#include "productController.h"
#include "costController.h"
#include "displayController.h"
#include "rfidController.h"
#include <StandardCplusplus.h>
#include <vector>
#include <SoftwareSerial.h>

SoftwareSerial RFID(2, 3); // RX and TX

using std::vector;

#define LOGLEVEL LOG_LEVEL_DEBUG

int failedTries=0;
const int BAUD_RATE = 9600;
int i=0;

SensorController sensorController;
ProductController productController;
CostController costController;
DisplayController displayController;
RfidController rfidController;

void setup()
{           
  RFID.begin(BAUD_RATE); // start serial to RFID reader  
  Serial.begin(BAUD_RATE);//Prepare serial port for use
   
  Log.Init(LOGLEVEL, BAUD_RATE);
  Log.Info("Arduino setup... "CR);
  
  // SystemController Initialization
  Initialize(sensorController, productController, costController, rfidController);
  
  if(sensorController.GetState())
    Log.Info("SensorController initialized successfully"CR);
  
  if(productController.GetState())
    Log.Info("Product controller initialized successfully"CR);

  if(costController.GetState())
    Log.Info("Cost controller initialized successfully"CR);

  if(rfidController.GetState())
    Log.Info("Rfid controller initialized successfully"CR);

  Log.Info("Arduino setup complete. "CR);
}

/*
Begin loop
*/
void loop()
{
 //Log.Info("Arduino loop"CR);
/*
  int input=0;
  int myByte=0;
  int incomingByte=0;
  failedTries=0;
  
  //do nothing (except continue to check) until something has been sent.
  while (Serial.available() == 0) {;};
  
  while ((Serial.available() > 0) || (failedTries < 10000))
  {
    int *p=&failedTries;
	myByte = Serial.read();
    incomingByte = AsciiToBinary(myByte);
    input = FetchNextCharacterAndAddToAccumulator(incomingByte, input, p);
  };

  // Check if the item is in the basket already. If so remove it.
  // This simulates the 'RemoveListener'
  if(productController.FindProductUsingRFIDTag(input))
  {
	// remove the product
	  Log.Info("Found a match."CR);
	  if(productController.RemoveProduct(input))
		  Log.Info("Item successfully removed."CR);
	  else
		  Log.Info("Something went wrong trying to remove the item."CR);

	costController.DecrementSessionTotalCost(50);
  }
  else
  {
	if(productController.AddProduct(input, "Linctagon Nasal Spray", 50))
	{    
		costController.IncrementSessionTotalCost(50);
		Log.Info("Successfully added product"CR);
	}
	else
		Log.Info("Failed to add the product."CR);
  } 
  
  Log.Info("Session total cost: %d"CR, costController.GetSessionTotalCost());
  */

  /*
  ======== RFID Functionality ================
  */
  if (RFID.available() > 0) 
  {
	 delay(100);

     i = RFID.read();
     if(i == 2){
         rfidController.SetCounter(0);
     }
     else if(i == 3){
	   RFID.flush(); // stops multiple reads
       rfidController.ProcessTag();
       rfidController.ClearSerial();
       rfidController.SetCounter(-1);
     }
     else if(rfidController.GetCounter() >= 0){
       rfidController.SetArrayElementValue(rfidController.GetCounter(), i);
       rfidController.SetCounter(rfidController.GetCounter()+1);
     }
  }
}

/*
End loop
*/
