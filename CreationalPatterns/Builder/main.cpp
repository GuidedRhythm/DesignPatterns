#include<iostream>
#include<string>
#include<memory>
using namespace std;

//Product:
class Pizza
{
	string base;
	string sauce;
	string topping;	//�������
public:
	void set_base(const string& base)
	{
		this->base = base;
	}
	void set_sauce(const string& sauce)
	{
		this->sauce = sauce;
	}
	void set_topping(const string& topping)
	{
		this->topping = topping;
	}
	void open()
	{
		cout << "���������:\t" << base << endl;
		cout << "����:\t" << sauce << endl;
		cout << "�������:\t" << topping << endl;
	}
};

class PizzaBuilder	//Abstract builder
{
protected:
	unique_ptr<Pizza> pizza;
public:
	virtual ~PizzaBuilder()
	{

	}

	Pizza* get_pizza()
	{
		return pizza.release();
	}

	void create_new_pizza()
	{
		pizza = make_unique<Pizza>();
	}

	virtual void build_base() = 0;
	virtual void build_sauce() = 0;
	virtual void build_topping() = 0;
};

class HawaiianPizzaBuilder :public PizzaBuilder
{
public:
	virtual void build_base()
	{
		this->pizza->set_base("�����");
	}
	virtual void build_sauce()
	{
		this->pizza->set_sauce(" ��������, �� ������");
	}
	virtual void build_topping()
	{
		this->pizza->set_topping("������ � �����, ��������� � ���������");
	}
};

class BBQPizzaBuilder :public PizzaBuilder
{
public:
	virtual void build_base()
	{
		this->pizza->set_base("black");
	}
	virtual void build_sauce()
	{
		this->pizza->set_sauce(" ����� ��� ������� ;-)");
	}
	virtual void build_topping()
	{
		this->pizza->set_topping("������ � �����, �����(�����), �����������, � ������������ �����");
	}
};

class MargaretBuilder :public PizzaBuilder
{
public:
	virtual void build_base()
	{
		this->pizza->set_base("white");
	}
	virtual void build_sauce()
	{
		this->pizza->set_sauce(" �������� ");
	}
	virtual void build_topping()
	{
		this->pizza->set_topping("�_� ���, ��� ����???!!!!!!!! ���� ��������, ��������� � ������");
	}
};

class Cook
{
	PizzaBuilder* builder;
public:
	void open_pizza()
	{
		builder->get_pizza()->open();
	}
	void make_pizza(PizzaBuilder* pb)
	{
		builder = pb;
		builder->create_new_pizza();
		builder->build_base();
		builder->build_sauce();
		builder->build_topping();
	}
};

void main()
{
	setlocale(LC_ALL, "");
	Cook cook;
	HawaiianPizzaBuilder hawaii_pb;
	BBQPizzaBuilder bbq_pb;
	MargaretBuilder margaret_pb;

	cook.make_pizza(&hawaii_pb);
	cook.open_pizza();

	cook.make_pizza(&bbq_pb);
	cook.open_pizza();
}