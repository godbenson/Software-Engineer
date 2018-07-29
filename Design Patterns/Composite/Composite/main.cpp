#include "Composite.h"
#include <iostream>

using namespace std;

int main()
{
	/*
		������Ҷ��Leaf����Composite����pRoot,pCom��ʵ����Operation�ӿ�
		���Կ���һ�¶Դ���ֱ�ӵ���Operation()
		�����ˡ�ʹ���û��Ե����������϶����ʹ�þ���һ���ԡ�
	*/

	Composite *pRoot = new Composite();
	
	//��϶������Ҷ�ӽڵ�
	pRoot->Add(new Leaf());

	Leaf* pLeaf1 = new Leaf();
	Leaf* pLeaf2 = new Leaf();

	//�����Ҷ�������Ҷ����û�������
	//����Ҷ������϶���̳�����ͬ�Ľӿڣ������﷨���ǶԵģ�ʵ����ʲôҲû��
	//���̳��Ի���Component��Add��������
	//Ҷ�ӽڵ�ֻʵ����Operation������������Add,Remove,GetChild���̳��Ի��࣬û��ʵ������

	pLeaf1->Add(pLeaf2);
	pLeaf1->Remove(pLeaf2);
	//ִ��Ҷ��Operation����
	pLeaf1->Operation();

	//��϶���ʵ���˻���Component�����нӿڣ����Կ��������ֲ�����Add,Remove,GetChild,Operation��
	Composite*pCom = new Composite();
	//��϶������Ҷ�ӽ��
	pCom->Add(pLeaf1);
	pCom->Add(pLeaf2);
	//ִ����϶���Operation����
	pCom->Operation();

	//��϶��������϶���
	pRoot->Add(pCom);

	//ִ����϶���Operation����
	pRoot->Operation();

	system("pause");
}