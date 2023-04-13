#include <iostream>
#include <chrono>
#include <string>
#include <fstream>
#include <stdio.h>  //color print

using namespace std;
using namespace std::chrono;

class Plant
{
private:
    string name;
    long long growth_time;
    system_clock::time_point start_time;
    int quantity;
    double price;
    string colour;

public:

    Plant()
    {
        name = "";                   //default constructor
        growth_time = 0;
        quantity = 0;
        price = 0.0;
        colour = "";
        start_time = system_clock::now();
    }

    Plant(const Plant& other)                 //copy constructor
    {
        name = other.name;
        growth_time = other.growth_time;
        start_time = other.start_time;
        quantity = other.quantity;
        price = other.price;
        colour = other.colour;
    }

    string getName() //getting name
    {
        return name;
    }

    long long getGrowthTime() //getting time that is needed to grow a plant
    {
        return growth_time;
    }

    long long getSecondsGrown()   //calculates the number of seconds that have elapsed since the plant was created
    {
        auto elapsed_time = duration_cast<seconds>(system_clock::now() - start_time);
        return elapsed_time.count();
    }

    int GetQuantity()        //returning quantity
    {
        return quantity;
    }

    double GetPrice()        //returning price
    {
        return price;
    }

    string GetColour()         //returning colour
    {
        return colour;
    }

    void SetQuantity(double new_quantity)          //setting quantity
    {
        quantity = new_quantity;
    }

    friend istream& operator>>(istream& is, Plant& plant)     //scanning input
    {
        is >> plant.name;
        is >> plant.growth_time;
        is >> plant.quantity;
        is >> plant.price;
        is >> plant.colour;
        is >> plant.start_time;
        return is;
    }
    friend ostream& operator<<(ostream& os, const Plant& plant) //output to stream
    {
        os << plant.name << endl;
        os << plant.growth_time << endl;
        os << plant.quantity << endl;
        os << plant.price << endl;
        os << plant.colour << endl;
        os << plant.start_time << endl;
        return os;
    }
    void PrintPlant()
    {
        if (name == "eggplant" || name == "Eggplant")
        {
            printf("\033[1;35mEggplant\033[0m\n");
        }
        else if (name == "corn" || name == "Corn")
        {
            printf("\033[1;33mCorn\033[0m\n");
        }
        else if (name == "cabbage" || name == "Cabbage")
        {
            printf("\033[1;32mCabbage\033[0m\n");
        }
        else if (name == "beetroot" || name == "Beetroot")
        {
            printf("\033[1;31mBeetroot\033[0m\n");
        }
        else if (name == "horseradish" || name == "Horseradish")
        {
            printf("\033[1;37mHorseradish\033[0m\n");
        }
        printf("\033[0m");
    }
    };