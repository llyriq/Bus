#include <iostream>
#include <vector>
#include "class_bus.h"

using namespace std;

bus addBus()
{
	string name;
	int year_n;
	double mile;
	bus add_bus;
	while (1)
	{
		try
		{
			cout << "Введите фамилию водителя - ";
			cin >> name;
			add_bus.set_last_name_driver(name);
			cout << "Введите номер автобуса - ";
			cin >> name;
			add_bus.set_number_bus(name);
			cout << "Введите номер маршрута - ";
			cin >> name;
			add_bus.set_number_route(name);
			cout << "Введите марку - ";
			cin >> name;
			add_bus.set_model(name);
			cout << "Введите год начала эксплуатации - ";
			cin >> year_n;
			if (cin.fail())
			{
				throw 1;
			}
			add_bus.set_year(year_n);
			cout << "Введите пробег (в км.) - ";
			cin >> mile;
			if (cin.fail())
			{
				throw 1;
			}
			add_bus.set_mileage(mile);
			return add_bus;
		}
		catch (int i)
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "\nОшибка №" << i << " - введено некорректное значение\n";
		}
	}
}

bus editBus(bus &ed_bus)
{
	string name;
	int year_n;
	double mile;
	int choise;
	bool exit = false;
	while (exit == false)
	{
		ed_bus.Print();

		cout << "Выберите параметр изменения:" << "\n";
		cout << "1) Фамилию водителя" << "\n";
		cout << "2) Номер автобуса" << "\n";
		cout << "3) Номер маршрута" << "\n";
		cout << "4) Марку" << "\n";
		cout << "5) Год начала эксплуатации" << "\n";
		cout << "6) Пробег" << "\n";
		cout << "7) Закончить изменения" << "\n";

		try
		{
			cin >> choise;

			if (cin.fail())
			{
				throw 1;
			}

			switch (choise)
			{
			case 1:
				cout << "Введите замену - ";
				cin >> name;
				ed_bus.set_last_name_driver(name);
				break;
			case 2:
				cout << "Введите замену - ";
				cin >> name;
				ed_bus.set_number_bus(name);
				break;
			case 3:
				cout << "Введите замену - ";
				cin >> name;
				ed_bus.set_number_route(name);
				break;
			case 4:
				cout << "Введите замену - ";
				cin >> name;
				ed_bus.set_model(name);
				break;
			case 5:
				cout << "Введите замену - ";
				cin >> year_n;
				if (cin.fail())
				{
					throw 1;
				}
				ed_bus.set_year(year_n);
				break;
			case 6:
				cout << "Введите замену - ";
				cin >> mile;
				if (cin.fail())
				{
					throw 1;
				}
				ed_bus.set_mileage(mile);
				break;
			case 7:
				exit = true;
				break;
			default:
				cout << "Выбран неверный вариант.";
				break;
			}

		}
		catch (int i)
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "\nОшибка №" << i << " - введено некорректное значение\n";
		}
	}
	return ed_bus;
}

void show_list_bus_route(vector <bus> &y_bus)
{
	int size_bus, track = 0;
	string rt, rt_b;
	size_bus = y_bus.size();
	cout << "Введите номер маршрута - ";
	cin >> rt;
	cout << "Автобусы, удовлетворяющие запросу:" << "\n";
	for (int i = 0; i < size_bus; i++)
	{
		rt_b = y_bus[i].get_number_route();
		if (rt_b == rt)
		{
			cout << i + 1 << ")" << "\n";
			y_bus[i].Print();
			cout << "\n";
			track++;
		}
	}
	if (track == 0)
	{
		cout << "Не найдено." << "\n";
	}
}

void show_bus_more_year(vector <bus> &y_bus)
{
	int size_bus, m_y, f_y, chk = 0;
	size_bus = y_bus.size();
	cout << "Введите количество лет - ";
	try
	{
		cin >> m_y;
		if (cin.fail())
		{
			throw 1;
		}
		if (m_y > 50)
		{
			throw 3;
		}
		cout << "Автобусы, удовлетворяющие запросу:" << "\n";
		for (int i = 0; i < size_bus; i++)
		{
			f_y = 2020 - y_bus[i].get_year();
			if (f_y > m_y)
			{
				cout << i + 1 << ")" << "\n";
				y_bus[i].Print();
				cout << "\n";
				chk++;
			}
		}
		if (chk == 0)
		{
			cout << "Не найдено." << "\n";
		}
	}
	catch (int i)
	{
		if (i == 1)
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "\nОшибка №" << i << " - введено некорректное значение\n";
		}
		if (i == 3)
		{
			cout << "\nОшибка №" << i << " - введено недопустимое значение\n";
		}
	}
}

void show_bus_more_mileage(vector <bus> &y_bus)
{
	int size_bus, chk = 0;
	double m_m, f_m;
	size_bus = y_bus.size();
	cout << "Введите пробег (в км.) - ";
	try
	{
		cin >> m_m;
		if (cin.fail())
		{
			throw 1;
		}
		cout << "Автобусы, удовлетворяющие запросу:" << "\n";
		for (int i = 0; i < size_bus; i++)
		{
			f_m = y_bus[i].get_mileage();
			if (f_m > m_m)
			{
				cout << i + 1 << ")" << "\n";
				y_bus[i].Print();
				cout << "\n";
				chk++;
			}
		}
		if (chk == 0)
		{
			cout << "Не найдено." << "\n";
		}
	}
	catch (int i)
	{
		if (i == 1)
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "\nОшибка №" << i << " - введено некорректное значение\n";
		}
	}
}


int main()
{
	setlocale(LC_ALL, "RUS");
	bool exit = false;
	int choise = 0, ind_go;

	vector <bus> station(0);
	vector <bus> ::iterator index;
	cout << "Список пуст. Добавьте автобус." << "\n";
	while (exit == false)
	{
		cout << "1) Вывод списка автобусов" << "\n";
		cout << "2) Добавить автобус" << "\n";
		cout << "3) Удалить автобус" << "\n";
		cout << "4) Редактировать автобус" << "\n";
		cout << "5) Вывод списка автобусов для заданного номера маршрута" << "\n";
		cout << "6) Вывод списка автобусов, которые эксплуатируются больше заданного количества лет" << "\n";
		cout << "7) Вывод списка автобусов, пробег у которых больше заданного количества км." << "\n";
		cout << "8) Выход" << "\n";

		try
		{

			cin >> choise;
			cout << "\n";

			if (cin.fail())
			{
				throw 1;
			}

			switch (choise)
			{
			case 1:
				int size_s;
				size_s = station.size();
				if (size_s == 0)
				{
					cout << "Список пуст." << "\n";
				}
				for (int i = 0; i < size_s; i++)
				{
					cout << i + 1 << ")" << "\n";
					station[i].Print();
				}
				break;
			case 2:
				station.push_back(addBus());
				cout << "\n" << "Автобус добавлен в список" << "\n";
				break;
			case 3:
				index = station.begin();
				cout << "Введите номер автобуса - ";
				cin >> ind_go;
				if (cin.fail())
				{
					throw 1;
				}
				if (ind_go > station.size())
				{
					throw 2;
				}
				ind_go--;
				index += ind_go;
				station.erase(index);
				cout << "Автобус удален из списка" << "\n";
				break;
			case 4:
				cout << "Введите номер автобуса - ";
				cin >> ind_go;
				if (cin.fail())
				{
					throw 1;
				}
				if (ind_go > station.size())
				{
					throw 2;
				}
				ind_go--;
				station[ind_go] = editBus(station[ind_go]);
				break;
			case 5:
				show_list_bus_route(station);
				break;
			case 6:
				show_bus_more_year(station);
				break;
			case 7:
				show_bus_more_mileage(station);
				break;
			case 8:
				exit = true;
				break;
			default:
				cout << "Выбран неверный вариант.";
				break;
			}
		}
		catch (int i)
		{
			if (i == 1)
			{
				cin.clear();
				while (cin.get() != '\n');
				cout << "\nОшибка №" << i << " - введено некорректное значение\n";
			}
			if (i == 2)
			{
				cout << "\nОшибка №" << i << " - введено значение, превышающее количество автобусов\n";
			}
		}

		cout << "\n";
	}

	return 0;
}