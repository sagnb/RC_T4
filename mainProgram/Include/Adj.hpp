#ifndef ADJ_HPP
#define ADJ_HPP

class Adj{
private:
	int at;
	int cap;
public:
	Adj();
	Adj(int at, int cap);
	~Adj();
	void setCap(int cap);
	int getAt();
	int getCap();
};

#endif