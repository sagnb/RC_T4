#ifndef ADJ_HPP
#define ADJ_HPP

class Adj{
private:
	int at;
	int cap;
	int charge;
	int cost;
public:
	Adj();
	Adj(int at, int cap, int cost);
	~Adj();
	int getAt();
	int getCost();
	bool updateCharge(int charge);
};

#endif