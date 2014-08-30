#ifndef costController_h
#define costController_h

class CostController
{
  private:
	bool State;
	int SessionTotalCost;
  public:
	CostController();
    void Initialize();
    bool GetState() { return State; }
    bool SetState(bool value) { State = value; }
	void IncrementSessionTotalCost(int cost);
	void DecrementSessionTotalCost(int cost);
	int GetSessionTotalCost() { return SessionTotalCost; }
};

#endif
