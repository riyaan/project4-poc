#include <Logging.h>

RfidController::RfidController() 
{
	Log.Info("Rfid Controller constructor");	
}

void RfidController::Initialize()
{
	Log.Info("RfidController - Initialize"CR);
	SetState(true);
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

int RfidController::CheckTag()
{
  /*int i;
  
  for (i = 0; i < 4; ++i) {
    if (strcmp(authorizedTags[i], tagId) == 0) {
      return 1;
    }
  }*/
  return 0;
}

// once a whole tag is read, process it
void RfidController::ProcessTag() 
{
	// convert id to a string
  parseTag();
	
	// print it
  printTag();
	
	// check if the tag is authorized
  if (checkTag() == 1) 
    tagSuccess(); // if so, perform an action (blink a led, open a door, etc...)
  else
    tagFailed(); // otherwise, inform user of failure
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
  Serial.println("Tag authorized.");
  delay(2000);
}

// inform the user that the tag is not authorized
void RfidController::RfidTagFailed() 
{
  Serial.println("Unauthorized access!");
  delay(2000);
}