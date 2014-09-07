#ifndef rfidController_h
#define rfidController_h

#include "costController.h"

class RfidController
{
	private:
		bool State;
		int i;
		int counter;
		int readData[10];
		char tagId[11]; // final tag ID converted to a string
		//char* authorizedTags[4]; // array to hold the list of authorized tags

		//// fills the list of authorzied tags
		//void initAuthorizedTags() {
		//	// add your own tag IDs here
		//	authorizedTags[0] = "8500908889";
		//	authorizedTags[1] = "8500904E47";
		//	authorizedTags[2] = "17001FBEAF";
		//}

		CostController costController;

	public:
		RfidController();		
		void Initialize(CostController & cc);
		bool GetState() { return State; }
		bool SetState(bool value) { State = value; }
		int GetCounter() { return counter; }
		void SetCounter(int value) { counter = value; }
		void SetArrayElementValue(int element, int value);
		void ParseTag();
		void PrintTag();
		char* CheckTag();
		char* ProcessTag();
		void ClearSerial();
		void RfidTagSuccess();
		void RfidTagFailed();
};

#endif
