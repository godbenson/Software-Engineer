#include "Memento.h"

int main()
{
	//��ʼ������״̬Ϊ��Old��
	Originator* o = new Originator("Old");
	o->show();

	//����������Memento
	Caretaker* pTaker = new Caretaker();
	pTaker->SetMemento(o->CreateMemento());

	//�ı�״̬
	o->SetState("New");
	o->show();

	//�ָ�״̬
	o->RestoreToMemento(pTaker->GetMemento());
	o->show();

	system("pause");
	return 0;
}