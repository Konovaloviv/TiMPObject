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
	virtual void InData(ifstream &ifst) = 0; // ����
	virtual void Out(ofstream &ofst) = 0; // �����
	virtual void Out_only_plane(ofstream &ofst);
	void OutCommon(ofstream &ofst);
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
	};
	Node* Top;
	int count;
public:
	void Out_only_plane(ofstream &ofst);
	void In(ifstream &ifst); // ����
	void Out(ofstream &ofst); // �����
	void Clear(); // ������� ���������� �� �����
	container(); // ������������� ����������
	~container() { Clear(); }
};


class plane : public transport {
	int range;
	int c;

public:
	void Out_only_plane(ofstream &ofst);
	void InData(ifstream &ifst); // ����
	void Out(ofstream &ofst); // �����
	plane() {} // �������� ��� �������������.
};
class traine : public transport {
	int count;

public:
	void InData(ifstream &ifst); // ����
	void Out(ofstream &ofst); // �����
	traine() {} // �������� ��� �������������.
};

// TODO: add headers that you want to pre-compile here

#endif //PCH_H#pragma once
