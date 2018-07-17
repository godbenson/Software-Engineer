#include "stack.h"
using namespace std;

int main(void){
	try{
		Stack<int> s1;
		s1.Push(1);
		s1.Push(2);

		cout << "size:" << s1.Size() << endl;
		s1.Pop();
		cout << "top: "<< s1.Top() << endl;
		s1.Pop();
		s1.Pop();
		cout << s1.Top() << endl;
		cout << "size: " << s1.Size() << endl;

		cout << "---------------------------------" << endl;

		Stack<int> s2(3);
		if(s2.IsEmpty()){
			cout << "Stack is empty." << endl;
		}

		s2.Push(1);
		s2.Push(2);
		s2.Push(3);
		s2.Push(4);
		cout << "Stack's size: " << s2.Size() << endl;

		cout << "-------------------------" << endl;

		Stack<char> s3;
		cout << "size: " << s3.Size() << endl;

		s3.Push('a');
		s3.Push('b');

		cout << "---------------------" << endl;

		Stack<string> s4(3);
		string a = "abc";
		cout << "a = " << a.c_str() << endl;
		s4.Push(a);
		s4.Push("bcd");
		s4.Push("cde");
		cout << "top: " << s4.Top().c_str() << endl;
		s4.Pop();
		cout << "top:" << s4.Top().c_str() <<endl;
	}catch(exception const &ex){
		cerr << "Exception:" << ex.what() << endl;
		return -1;
	}
	system("pause");
}