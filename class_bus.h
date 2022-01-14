#include<string>
using namespace std;

class bus
{
private:
	string last_name_driver;
	string number_bus;
	string number_route;
	string model;
	int year = 0;
	double mileage = 0;

public:

	bus() {}

	bus(string b_last_name_driver, string b_number_bus, string b_number_route, string b_model, int b_year, double b_mileage);
	bus(const bus& new_bus);

	~bus() {}

	void set_last_name_driver(string b_last_name_driver);
	string get_last_name_driver();

	void set_number_bus(string b_number_bus);
	string get_number_bus();

	void set_number_route(string b_number_route);
	string get_number_route();

	void set_model(string b_model);
	string get_model();

	void set_year(int b_year);
	int get_year();

	void set_mileage(double b_mileage);
	double get_mileage();

	void Print();

};