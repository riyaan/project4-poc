#include <Logging.h>
#include <SoftwareSerial.h>
SoftwareSerial RFID(2, 3); // RX and TX

#define LOGLEVEL LOG_LEVEL_DEBUG

const int BAUD_RATE = 9600;
int i;
int counter=-1;
int readData[10];
char tagId[11]; // final tag ID converted to a string
char* authorizedTags[4]; // array to hold the list of authorized tags

// fills the list of authorzied tags
void initAuthorizedTags() {
	// add your own tag IDs here
  authorizedTags[0] = "8500908889";
  authorizedTags[1] = "8500904E47";
  authorizedTags[2] = "17001FBEAF";
}

void setup()
{
  RFID.begin(BAUD_RATE); // start serial to RFID reader
  Serial.begin(BAUD_RATE);// start serial to PC 
   
  Log.Init(LOGLEVEL, BAUD_RATE);
  Log.Info("Arduino setup... "CR);
}

void loop()
{
  if (RFID.available() > 0) 
  {
     i = RFID.read();
     //Log.Info("Value Read: %d"CR, i);
     if(i == 2){
         counter = 0;
         Log.Info("Start of tag"CR);
     }
     else if(i == 3){
       processTag();
       clearSerial();
       counter = -1;
     }
     else if(counter >= 0){
       readData[counter] = i;
       counter++;
     }
  }
}

// convert the int values read from serial to ASCII chars
void parseTag() {
  int i;
  for (i = 0; i < 10; ++i) {
    tagId[i] = readData[i];
  }
  tagId[10] = 0;
}

void printTag() {
  Serial.print("Tag value: ");
  Serial.println(tagId);
}

int checkTag() {
  int i;
  
  for (i = 0; i < 4; ++i) {
    if (strcmp(authorizedTags[i], tagId) == 0) {
      return 1;
    }
  }
  return 0;
}

// once a whole tag is read, process it
void processTag() {
	// convert id to a string
  parseTag();
	
	// print it
  printTag();
	
	// check if the tag is authorized
  if (checkTag() == 1) {
    tagSuccess(); // if so, perform an action (blink a led, open a door, etc...)
  } else {
    tagFailed(); // otherwise, inform user of failure
  }
}

// this function clears the rest of data on the serial, to prevent multiple scans
void clearSerial() {
  while (Serial.read() >= 0) { 	; // do nothing 
  }
}

// perform an action when an authorized tag was read
void tagSuccess() {
  Serial.println("Tag authorized.");
	
	// here, we simply turn on the success LED for 2s
  //digitalWrite(SUCCESS, HIGH);
  //digitalWrite(ERROR, LOW);
  delay(2000);
}

// inform the user that the tag is not authorized
void tagFailed() {
  Serial.println("Unauthorized access!");
	
  //digitalWrite(SUCCESS, LOW);
  //digitalWrite(ERROR, HIGH);
  delay(2000);
}
