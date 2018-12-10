#ifndef ADJ_HPP
#define ADJ_HPP

class Adj{
private:
	int to;
	int cap;
	int charge;
	int cost;
public:
	Adj();
	Adj(int to, int cap, int cost);
	~Adj();
	int getTo();
	int getCost();
	bool canUpdate(int charge);
	void update(int charge);
	void reset();
};

#endif