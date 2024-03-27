

#include <iostream>

using namespace std;

template <class T>
class Exchange
{
private:
    // ГРИВНИ ДО 
    double rate_UAH_to_USD = 41;
    double rate_UAH_to_EUR = 43.5;
    // ДОЛАРА ДО
    double rate_USD_to_UAH = 41;
    double rate_USD_to_EUR = 1.15;
    // ЭВРО ДО
    double rate_EUR_to_UAH = 43.5;
    double rate_EUR_to_USD = 1.15;

    double balance = 0;

public:
    inline double tradeRate(double amount, string from_rate, string to_rate)
    {
        if (amount > balance)
        {
            cout << "Your balance is not enough to trade!" << endl;
            return 0;
        }

        double result = 0;
        if (from_rate == "UAH" && to_rate == "USD")
        {
            result = amount / rate_UAH_to_USD;
        }
        else if (from_rate == "UAH" && to_rate == "EUR")
        {
            result = amount / rate_UAH_to_EUR;
        }
        else if (from_rate == "USD" && to_rate == "UAH")
        {
            result = amount * rate_USD_to_UAH;
        }
        else if (from_rate == "USD" && to_rate == "EUR")
        {
            result = amount / rate_USD_to_EUR;
        }
        else if (from_rate == "EUR" && to_rate == "UAH")
        {
            result = amount * rate_EUR_to_UAH;
        }
        else if (from_rate == "EUR" && to_rate == "USD")
        {
            result = amount * rate_EUR_to_USD;
        }

        balance -= amount;
        cout << "The rate is successfully converted: "<< result << endl;
        return result;
    }

    inline void getAllRates() const
    {
        cout << "UAH to USD: " << rate_UAH_to_USD << endl;
        cout << "UAH to EUR: " << rate_UAH_to_EUR << endl;
        cout << "USD to UAH: " << rate_USD_to_UAH << endl;
        cout << "USD to EUR: " << rate_USD_to_EUR << endl;
        cout << "EUR to UAH: " << rate_EUR_to_UAH << endl;
        cout << "EUR to USD: " << rate_EUR_to_USD << endl;
    }

    inline void setRateInExchange(string from_rate, string to_rate, double new_rate)
    {
        
        if (from_rate == "UAH" && to_rate == "USD")
        {
            rate_UAH_to_USD = new_rate;
        }
        else if (from_rate == "UAH" && to_rate == "EUR")
        {
            rate_UAH_to_EUR = new_rate;
        }
        else if (from_rate == "USD" && to_rate == "UAH")
        {
            rate_USD_to_UAH = new_rate;
        }
        else if (from_rate == "USD" && to_rate == "EUR")
        {
            rate_USD_to_EUR = new_rate;
        }
        else if (from_rate == "EUR" && to_rate == "UAH")
        {
            rate_EUR_to_UAH = new_rate;
        }
        else if (from_rate == "EUR" && to_rate == "USD")
        {
            rate_EUR_to_USD = new_rate;
        }
        cout << "The rate is successfully updated!" << endl;

    }

    inline void deposit(double amount)
    {
        balance += amount;
        cout << "Deposit successful! Current balance: " << balance << endl;
    }

    inline double getBalance() const
    {
        return balance;
    }
};


int main()
{
    Exchange<double> exchange;
    exchange.deposit(50);
    exchange.getAllRates();
    exchange.tradeRate(50, "USD", "UAH");
    
    exchange.setRateInExchange("UAH", "USD", 50);
    exchange.setRateInExchange("UAH", "EUR", 100);
    exchange.getAllRates();
    return 0;
}

/*
Deposit successful! Current balance: 50
UAH to USD: 41
UAH to EUR: 43.5
USD to UAH: 41
USD to EUR: 1.15
EUR to UAH: 43.5
EUR to USD: 1.15
The rate is successfully converted: 2050
The rate is successfully updated!
The rate is successfully updated!
UAH to USD: 50
UAH to EUR: 100
USD to UAH: 41
USD to EUR: 1.15
EUR to UAH: 43.5
EUR to USD: 1.15

C:\Users\David\source\repos\Project1\x64\Debug\Project1.exe (процесс 22540) завершил работу с кодом 0.
Нажмите любую клавишу, чтобы закрыть это окно:
*/