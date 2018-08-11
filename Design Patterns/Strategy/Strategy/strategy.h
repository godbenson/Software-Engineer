#pragma once
class Strategy
{
public:
	~Strategy();
	virtual void AlgorithmInterface() = 0;
protected:
	Strategy();
private:
};

class ConcreteStrategyA : public Strategy
{
public:
	ConcreteStrategyA();
	~ConcreteStrategyA();
	virtual void AlgorithmInterface();
protected:
private:
};

class ConcreteStrategyB : public Strategy
{
public:
	ConcreteStrategyB();
	~ConcreteStrategyB();
	virtual void AlgorithmInterface();
protected:
private:
};

/*�������Strategyģʽ�Ĺؼ���
  Ҳ��Strategyģʽ��Templateģʽ�ĸ����������ڡ�
  *Strategyͨ������ϡ���ί�У���ʽʵ���㷨��ʵ�֣����칹��
   ��Templateģʽ���ȡ���Ǽ̳еķ�ʽ
   ������ģʽ������Ҳ�Ǽ̳к��������ʵ�ֽӿ����õķ�ʽ������
*/

class Context
{
public:
	Context(Strategy*);
	~Context();
	void DoAction();
private:
	Strategy* _strategy;
};