#pragma once
#include <iostream>
#include <string>

using namespace std;

//����
struct ArcNode {
	int adjvex;//ĳ����ָ����Ǹ������λ�ã�һ���������С�꣩
	ArcNode * next;//ָ����һ������
	int weight; //�ߵ�Ȩ��
};

//ͷ���
struct Vnode {
	ArcNode * firstarc; //��һ���͸ö��������ıߵ���Ϣ
	string data;//��¼�ö������Ϣ
};

struct Graph_List {
	int vexnum;//�������
	int edge; //�ߵ�����
	Vnode * node;//�����
};

//����ͼ����һ�����غ���
void createGraph(Graph_List &g)
{
	cout << "�����붥���������붥��ߵĸ�����" << endl;
	cin >> g.vexnum;
	cin >> g.edge;
	g.node = new Vnode[g.vexnum];
	int i;
	for (i = 0; i < g.vexnum; i++) {
		g.node[i].data = "v" + std::to_string(i + 1);//��ÿ�������������
		g.node[i].firstarc = NULL;//��ʼ��ÿ���������������
	}

	cout << "������ÿ����֮��Ķ����ţ������Ŵ�1��ʼ�����Լ��ñߵ�Ȩ�أ�" << endl;
	for (i = 0; i < g.edge; i++)
	{
		int start;
		int end;
		cin >> start; //����ÿ���ߵ����
		cin >> end; //����ÿ���ߵ��յ�
		int weight;
		cin >> weight;

		ArcNode * next = new ArcNode;
		next->adjvex = end - 1;
		next->next = NULL;
		next->weight = weight;
		//�����һ�������ı�Ϊ��
		if (g.node[start - 1].firstarc == NULL) {
			g.node[start - 1].firstarc = next;
		}
		else {
			ArcNode * temp;//��ʱ����
			temp = g.node[start - 1].firstarc;
			while (temp->next) {//�ҵ�������start-1���������������һ������
				temp = temp->next;
			}
			temp->next = next;//�ڸ������β������һ�����
		}

		//��Ϊ����ͼ����˫���
		ArcNode * next_2 = new ArcNode;
		next_2->adjvex = start - 1;
		next_2->weight = weight;
		next_2->next = NULL;

		//�����һ�������ı�Ϊ��
		if (g.node[end - 1].firstarc == NULL)
		{
			g.node[end - 1].firstarc = next_2;
		}
		else {
			ArcNode * temp;//��ʱ����
			temp = g.node[end - 1].firstarc;
			while (temp->next)//�ҵ�������start-1���������������һ������
			{
				temp = temp->next;
			}
			temp->next = next_2;//�ڸ������β������һ������
		}
	}
}


void print(Graph_List g) {
	cout << "ͼ���ڽӱ�" << endl;
	for (int i = 0; i < g.vexnum; i++)
	{
		cout << g.node[i].data << " ";
		ArcNode * next;
		next = g.node[i].firstarc;
		while (next) {
			cout << "(" << g.node[i].data << "," << g.node[next->adjvex].data << ")=" << next->weight << endl;
			next = next->next;
		}
		cout << "^" << endl;
	}
}


////��Ϊ��¼�ߵ���Ϣ����Щ�߶��Ǵﵽend�����б��У�Ȩ����С���Ǹ�
struct Assis_array {
	int start;//�ߵ��յ�
	int end;//�ߵ����
	int weight;//�ߵ�Ȩ��
};

void Prim(Graph_List g, int begin) {
	cout << "ͼ����С������:" << endl;
	//close_edge��������¼����ĳ������ĸ������е�Ȩ�������Ǹ���
	Assis_array * close_edge = new Assis_array[g.vexnum];
	int j;
	for (j = 0; j < g.vexnum; j++)
	{
		close_edge[j].weight = INT_MAX;
	}
	ArcNode* arc = g.node[begin - 1].firstarc;

	while (arc) {
		close_edge[arc->adjvex].end = arc->adjvex;
		close_edge[arc->adjvex].start = begin - 1;
		close_edge[arc->adjvex].weight = arc->weight;
		arc = arc->next;
	}

	//������close_edge�е�ֵ����Ϊ-1�������Ѿ����뵽����U��
	close_edge[begin - 1].weight = -1;
	//����ʣ�µĶ��㣬���������μ��뵽����U
	for (j = 1; j < g.vexnum; j++)
	{
		int min = INT_MAX;
		int k;
		int index;
		//Ѱ������close_edge��Ȩ����С���Ǹ���
		for (k = 0; k < g.vexnum; k++)
		{
			if (close_edge[k].weight != -1)
			{
				if (close_edge[k].weight < min) {
					min = close_edge[k].weight;
					index = k;
				}
			}
		}

		//�����Ӧ�ıߵ���Ϣ
		cout << g.node[close_edge[index].start].data
			<< "--------------"
			<< g.node[close_edge[index].end].data
			<< "="
			<< close_edge[index].weight
			<< endl;
		//��Ȩ����С�������ߵ��յ�Ҳ���뵽����U
		close_edge[index].weight = -1;
		//�������ǵ�close_edge���顣
		ArcNode * temp = g.node[close_edge[index].end].firstarc;
		while (temp) {
			if (close_edge[temp->adjvex].weight > temp->weight) {
				close_edge[temp->adjvex].weight = temp->weight;
				close_edge[temp->adjvex].start = index;
				close_edge[temp->adjvex].end = temp->adjvex;
			}
			temp = temp->next;
		}
	}
}
