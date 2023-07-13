#include <iostream>
using namespace std;
class account
{
public:
    string account_name;
    string account_number;
    friend class borrower;
    friend class lender;
};
class account_balance
{
    public:
    virtual int balance()
    {
        return 10000;
    }
};
class borrower
{
private:
    int amount_of_loan;
    int interest_rate;
    int number_of_payments;
    int payments_paid;
    account a;

public:
    borrower(int amount_of_loan_, int interest_rate_, int number_of_payments_)
    {
        amount_of_loan = amount_of_loan_;
        interest_rate = interest_rate_;
        number_of_payments = number_of_payments_;
        payments_paid = 0;
    }
    void set_account_name(string s) { a.account_name = s; }
    void set_account_number(string s) { a.account_number = s; }
    void set_amount_of_loan(int x) { amount_of_loan = x; }
    void set_number_of_payments(int x) { number_of_payments = x; }
    float payment_per_month() { return (float)(amount_of_loan * (1 + (float)(interest_rate) / 100)) / number_of_payments; }
    int payment_paid() { return ++payments_paid; }
    int number_of_payments_to_be_paid() { return number_of_payments - payments_paid; }
    float amount_to_be_paid() { return number_of_payments_to_be_paid() * payment_per_month(); }
};
class lender:public account_balance
{
private:
    account a;
    int money_to_lended;
    int duration_in_months;

public:
    void set_account_name(string s) { a.account_name = s; }
    void set_account_number(string s) { a.account_number = s; }
    void set_money_to_lended(int x) { money_to_lended = x; }
    void set_duration_in_months(int x) { duration_in_months = x; }
    int balance()
    {
        return 10000-money_to_lended;
    }
};
int main()
{
    int x;
    cout << "Enter 1 for borrowing money and 2 for lending money\n";
    cin >> x;
    if (x == 1)
    {
        borrower b(0, 50, 0);
        string s;
        cout << "Pls enter ur name\n";
        cin >> s;
        b.set_account_name(s);
        cout << "Pls enter your account number\n";
        cin >> s;
        b.set_account_number(s);
        cout << "Amount which you want to borrow\n";
        int y;
        cin >> y;
        b.set_amount_of_loan(y);
        cout << "Number of installments in which u want to repay the amoumt\n";
        cin >> y;
        b.set_number_of_payments(y);
        cout << "Enter\n1 to make the pay the installment\n2 to check payment per month\n";
        cout << "3 to check number of payments to be paid\n4 amount_to_be_paid\n5 to exit";
        int z;
        cin >> z;
        while (z != 5)
        {
            if (z == 1)
                cout << "no.of installments paid are" << b.payment_paid();
            else if (z == 2)
                cout << b.payment_per_month();
            else if (z == 3)
                cout << b.number_of_payments_to_be_paid();
            else if (z == 4)
                cout << b.amount_to_be_paid();
            else
            {
                cout << "invalid";
                break;
            }
            cout << "\nEnter\n1 to make the pay the installment\n2 to check payment per month\n";
            cout << "3 to check number of payments to be paid\n4 amount_to_be_paid\n5 to exit";
            cin >> z;
        }
    }
    else
    {
        string s;
        lender b;
        cout << "Pls enter ur name\n";
        cin >> s;
        b.set_account_name(s);
        cout << "Pls enter your account number\n";
        cin >> s;
        b.set_account_number(s);
        cout << "Amount which you want to lend\n";
        int y;
        cin >> y;
        b.set_money_to_lended(y);
        cout << "Duration for which u want to lend\n";
        cin >> y;
        b.set_duration_in_months(y);
        cout<<"Your current balance is "<<b.balance();
    }
}
