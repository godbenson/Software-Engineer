#pragma once
class Handler {
public:
	virtual ~Handler() {};
	virtual bool canIEatChocolate() = 0;
	void setSuccessor(Handler * handler) { m_pSuccesor = handler; };
	Handler * successor() { return m_pSuccesor; }
private:
	Handler * m_pSuccesor;
};
class Child {
public:

	void eatChocolate();
	void setHandler(Handler * handler);
private :
	Handler * m_pHandler;
};



class Mother : public Handler {
	bool canIEatChocolate();
};

class Father : public Handler {
	bool canIEatChocolate();
};

class Grandmother : public Handler {
	bool canIEatChocolate();
};