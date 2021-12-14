#ifndef PCH_H
#define PCH_H
#include <fstream>
using namespace std;
class transport {
private:
	int spead;
	int distance;
public:
	static transport* In(ifstream &ifst);
	virtual void InData(ifstream &ifst) = 0; // ввод
	virtual void Out(ofstream &ofst) = 0; // вывод
	float Travel_time();
	void OutCommon(ofstream &ofst);
	bool Compare(transport &other);
};
class container
{
private:
	class Node {
	public:
		Node();
		Node* Next;
		Node* Prev;
		transport* data;
		void castl();
	};
	Node* Top;
	int count;
public:
	void In(ifstream &ifst); // ввод
	void Out(ofstream &ofst); // вывод
	void Clear(); // очистка контейнера от фигур
	container(); // инициализация контейнера
	void Sort();
	~container() { Clear(); }
};


class plane : public transport {
	int range;
	int c;

public:
	void InData(ifstream &ifst); // ввод
	void Out(ofstream &ofst); // вывод
	plane() {} // создание без инициализации.
};
class traine : public transport {
	int count;

public:
	void InData(ifstream &ifst); // ввод
	void Out(ofstream &ofst); // вывод
	traine() {} // создание без инициализации.
};

// TODO: add headers that you want to pre-compile here

#endif //PCH_H#pragma once
