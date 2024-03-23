#include <iostream>
#include <Windows.h>
#pragma execution_character_set("utf-8")

class BankAccount {

private:
    int accountNumber;
    double balance;
    double interestRate;

public:
    BankAccount(int accNum, double initialBalance) {
        accountNumber = accNum;
        balance = initialBalance;
        interestRate = 0.7;
    }

    // Внести средства на счет
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    // Снять средства со счета
    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            return true;
        }
        return false;
    }

    // Получить текущий баланс
    double getBalance() const {
        return balance;
    }

    // Рассчитать и вернуть сумму процентов
    double getInterest() const {
        int a;
        a = balance * interestRate * (1.0 / 12.0);
        return a;
    }

    // Обновить процентную ставку
    void setInterestRate(double rate) {
        if (rate >= 0) {
            interestRate = rate;
        }
    }

    // Получить номер счета
    int getAccountNumber() const {
        return accountNumber;
    }

    // Дружественная функция для перевода средств между счетами
    friend bool transfer(BankAccount& sender, BankAccount& receiver, double amount);
};

// Функция для перевода средств между счетами
bool transfer(BankAccount& sender, BankAccount& receiver, double amount) {
    if (sender.withdraw(amount)) {
        receiver.deposit(amount);
        return true;
    }
    return false;
}

int main() {
    SetConsoleCP(65001); // устанавливаем кодировку входящего потока данных на UTF-8
    SetConsoleOutputCP(65001); // устанавливаем кодировку исходящего потока данных на UTF-8
    BankAccount acc1(12345, 1000.0);
    BankAccount acc2(54321, 500.0);
    
    std::cout << "выберите действие:" << std::endl;
    std::cout << "1.пополнить баланс:" << std::endl;
    std::cout << "2.снять деньги:" << std::endl;
    std::cout << "3.узнать баланс:" << std::endl;
    std::cout << "4.Рассчитать и вернуть сумму процентов:" << std::endl;
    std::cout << "5.Обновить процентную ставку:" << std::endl;
    std::cout << "6.Получить номер счета:" << std::endl;
    std::cout << "7.перевести другому пользователю:" << std::endl;
    std::cout << "8.вернуться обратно:" << std::endl;


    int a;
    std::cin >> a;
    while (a != 8){

        switch (a) {

        case 1: {

            std::cout << "Введите сумму:" << std::endl;
            int b;
            std::cin >> b;
            acc1.deposit(b);
            std::cout << "ваш баланс:" << acc1.getBalance() << std::endl;
            
        }break;


        case 2: {

            std::cout << "Введите сумму:" << std::endl;
            int c;
            std::cin >> c;
            acc1.withdraw(c);
            std::cout << "ваш баланс:" << acc1.getBalance() << std::endl;
            
        }
        case 3: {

            std::cout << "ваш баланс:" << acc1.getBalance() << std::endl;
        }break;
        case 4: {

            acc1.getInterest();
            std::cout << "сумма процентов:" << a << std::endl;
        }break;
        case 5: {

            acc1.setInterestRate(0.9);
            std::cout << "процентная ставка изменена:" << std::endl;
        }break;
        case 6: {

            std::cout << "номер счета: " << acc1.getAccountNumber() << std::endl;
        }break;
        case 7: {

            std::cout << "До перевода:" << std::endl;
            std::cout << "Баланс 1 аккаунта: " << acc1.getBalance() << std::endl;
            std::cout << "Баланс 2 аккаунта: " << acc2.getBalance() << std::endl;

            double transferAmount = 200.0;
            if (transfer(acc1, acc2, transferAmount)) {
                std::cout << "Перевод успешен!" << std::endl;
            }
            else {
                std::cout << "Перевод не прошел!" << std::endl;
            }

            std::cout << "После перевода:" << std::endl;
            std::cout << "Баланс 1 аккаунта: " << acc1.getBalance() << std::endl;
            std::cout << "Баланс 2 аккаунта: " << acc2.getBalance() << std::endl;
        }break;
    }break;
    }
   

    

}

