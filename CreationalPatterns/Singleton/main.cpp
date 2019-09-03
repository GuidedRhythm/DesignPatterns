#include<iostream>
using namespace std;

class Account
{
	int id;
	double balance;
	Account(int id, double balance) :id(id), balance(balance)
	{
		
	}
	static Account* account;
public:
	static Account* create_account(int id, double balance)
	{
		if (account == nullptr)
			return account = new Account(id, balance);
		else
			cout << "�� ���� ��� ��� ������ ����" << endl;
		return account;
	}
	void info()
	{
		cout << "��� id:\t" << id << endl;
		cout << "��� ������: " << balance << endl;
	}
};

Account* Account::account = nullptr;

void main()
{
	setlocale(LC_ALL, "");
	Account* pa = Account::create_account(0, 1000);
	pa->info();
	Account* pb = Account::create_account(1, 2000);
}