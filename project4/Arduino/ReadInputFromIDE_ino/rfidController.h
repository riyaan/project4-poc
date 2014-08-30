#ifndef rfidController_h
#define rfidController_h

class ProductController
{
	private:
		bool State;
		int i;
		int counter=-1;
		int readData[10];
		char tagId[11]; // final tag ID converted to a string
		char* authorizedTags[4]; // array to hold the list of authorized tags

	public:
		RfidController();
		void Initialize();
		bool GetState() { return State; }
		bool SetState(bool value) { State = value; }
		void ParseTag();
		void PrintTag();
		int CheckTag();
		void ProcessTag();
		void ClearSerial();
		void RfidTagSuccess()
		void RfidTagFailed();

#endif