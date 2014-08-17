#ifndef sensorController_h
#define sensorController_h

class SensorController
{
  private:
    bool State;
    bool SetupListeners();
    void ReadRFIDTag();
  public:
    SensorController();    
    void Initialize();
    bool GetState() { return State; }
    bool SetState(bool value) { State = value; }
    void AddItem_Event();
    void RemoveItemEvent();    
};

#endif
