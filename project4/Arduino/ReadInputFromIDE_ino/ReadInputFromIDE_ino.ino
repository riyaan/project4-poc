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

void loop()
{
  if (RFID.available() > 0) 
  {
	 delay(100);

     i = RFID.read();
     if(i == 2){
         rfidController.SetCounter(0);
     }
     else if(i == 3){
	   RFID.flush(); // stops multiple reads
       char* tagId = rfidController.ProcessTag();

	   Product product = productController.FindProductUsingRFIDTag(tagId, 1);

	   if(strcmp(product.GetRFIDTag(), "-1") == 0) // Check the shop inventory for the item details
		   Log.Info("Item does not have any RFID information."CR);
	   else		
		   Log.Info("Item contains RFID information."CR);

       rfidController.ClearSerial();
       rfidController.SetCounter(-1);

	   // Check the user's basket. If the item is already present, then remove it.
		Product shoppingBasketProduct = productController.FindProductUsingRFIDTag(tagId, 0);
		if(strcmp(shoppingBasketProduct.GetRFIDTag(), "-1") == 0)
		{
			//Product product = productController.FindProductUsingRFIDTag(tagId);
			if(productController.AddProduct(product.GetRFIDTag(), product.GetDescription(), product.GetPrice()))
			{    
				costController.IncrementSessionTotalCost(product.GetPrice());
				Log.Info("Successfully added product"CR);
			}
			else
				Log.Info("Failed to add the product."CR);
		}
		else
		{			
			// remove the product
			Log.Info("Found a match."CR);
			if(productController.RemoveProduct(shoppingBasketProduct.GetRFIDTag()))
				Log.Info("Item successfully removed."CR);
			else
				Log.Info("Something went wrong trying to remove the item."CR);

			costController.DecrementSessionTotalCost(shoppingBasketProduct.GetPrice());
		}

	   Log.Info("Session total cost: %d"CR, costController.GetSessionTotalCost());
     }
     else if(rfidController.GetCounter() >= 0){
       rfidController.SetArrayElementValue(rfidController.GetCounter(), i);
       rfidController.SetCounter(rfidController.GetCounter()+1);
     }
  }
}