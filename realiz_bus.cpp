#include <iostream>
#include "class_bus.h"
using namespace std;

bus::bus(string b_last_name_driver, string b_number_bus, string b_number_route, string b_model, int b_year, double b_mileage)
{
	last_name_driver = b_last_name_driver;
	number_bus = b_number_bus;
	number_route = b_number_route;
	model = b_model;
	year = b_year;
	mileage = b_mileage;
}

bus::bus(const bus& new_bus)
{
	last_name_driver = new_bus.last_name_driver;
	number_bus = new_bus.number_bus;
	number_route = new_bus.number_route;
	model = new_bus.model;
	year = new_bus.year;
	mileage = new_bus.mileage;
}

void bus::set_last_name_driver(string b_last_name_driver)
{
	last_name_driver = b_last_name_driver;
}
string bus::get_last_name_driver() { return this->last_name_driver; }

void bus::set_number_bus(string b_number_bus)
{
	this->number_bus = b_number_bus;
}
string bus::get_number_bus() { return this->number_bus; }

void bus::set_number_route(string b_number_route)
{
	this->number_route = b_number_route;
}
string bus::get_number_route() { return this->number_route; }

void bus::set_model(string b_model)
{
	this->model = b_model;
}
string bus::get_model() { return this->model; }

void bus::set_year(int b_year)
{
	this->year = b_year;
}
int bus::get_year() { return this->year; }

void bus::set_mileage(double b_mileage)
{
	this->mileage = b_mileage;
}
double bus::get_mileage() { return this->mileage; }

void bus::Print()
{
	cout << "Фамилия водителя - " << last_name_driver << "\n";
	cout << "Номер автобуса - " << number_bus << "\n";
	cout << "Номер маршрута - " << number_route << "\n";
	cout << "Марка - " << model << "\n";
	cout << "Год начала эксплуатации - " << year << "\n";
	cout << "Пробег - " << mileage << " км." << "\n\n";
}