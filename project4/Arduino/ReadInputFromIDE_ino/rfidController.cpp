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

char* RfidController::CheckTag() { 	return tagId; }

// once a whole tag is read, process it
char* RfidController::ProcessTag() 
{
	// convert id to a string
  ParseTag();
  return tagId;
}

// this function clears the rest of data on the serial, to prevent multiple scans
void RfidController::ClearSerial() 
{
  while (Serial.read() >= 0) { 	; // do nothing 
  }
}

void RfidController::SetArrayElementValue(int element, int value) { readData[element] = value; }