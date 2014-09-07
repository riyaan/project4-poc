#include "rfidController.h"
#include <Logging.h>


RfidController::RfidController() 
{
	Log.Info("Rfid Controller constructor");	
}

void RfidController::Initialize(CostController & cc)
{
	Log.Info("RfidController - Initialize"CR);
	SetState(true);
	//initAuthorizedTags();
	costController = cc;
}

// convert the int values read from serial to ASCII chars
void RfidController::ParseTag() 
{
  int i;
  for (i = 0; i < 10; ++i) 
  {
    tagId[i] = readData[i];
  }
  tagId[10] = 0;
}

void RfidController::PrintTag() 
{
  Serial.print("Tag value: ");
  Serial.println(tagId);
}

char* RfidController::CheckTag()
{
	Log.Info("CheckTag Start"CR);
	Log.Info("RFID: %s"CR, tagId);

	return "tagId";
	/*int i;
  
  for (i = 0; i < 4; ++i) {
    if (strcmp(authorizedTags[i], tagId) == 0) {
      return 1;
    }
  }*/

	//Log.Info("Store contains %d items."CR, productController.GetAllShopProducts().size());	

	//Product product = productController.FindProductUsingRFIDTag(tagId);
	////Log.Debug("RFID Tag: %s"CR, product.GetRFIDTag());

	//if(strcmp(product.GetRFIDTag(), "-1") == 0) // Check the shop inventory for the item details
	//{
	//	Log.Info("Item does not have any RFID information."CR);
	//	return "-1";
	//}
	//else
	//{		
	//	Log.Info("Item contains RFID information."CR);
	//	return tagId;
	//}
}

// once a whole tag is read, process it
char* RfidController::ProcessTag() 
{
	Log.Info("ProcessTag() Start"CR);

	// convert id to a string
  ParseTag();
	
	// print it
  PrintTag();
	
	// check if the tag is authorized
  //if (CheckTag() == 1) 
  //{
  //  RfidTagSuccess(); // if so, perform an action (blink a led, open a door, etc...)
  //}
  //else
  //{
  //  RfidTagFailed(); // otherwise, inform user of failure
  //}
  //return CheckTag();
  return tagId;
}

// this function clears the rest of data on the serial, to prevent multiple scans
void RfidController::ClearSerial() 
{
  while (Serial.read() >= 0) { 	; // do nothing 
  }
}

// perform an action when an authorized tag was read
void RfidController::RfidTagSuccess() 
{
  /*Serial.println("Tag authorized.");*/
	Log.Info("Item found"CR);
  delay(2000);
}

// inform the user that the tag is not authorized
void RfidController::RfidTagFailed() 
{
  //Serial.println("Unauthorized access!");
	Log.Info("Item not found"CR);
  delay(2000);
}

void RfidController::SetArrayElementValue(int element, int value)
{
	readData[element] = value;
}