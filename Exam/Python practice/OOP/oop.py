class BankAccount:
    def __init__(self, bank_name, acc_name, acc_id, balance=0):
        self.bank_name = bank_name
        self.acc_name = acc_name
        self.acc_id = acc_id
        self.balance = balance
    
    def get_balance(self):
        return self.balance
    
    def deposit(self, money, person, date):
        if money > 0:
            self.balance += money
            print(f"{money} deposited by {person} on {date}. New balance: {self.balance}")
        else:
            print("Deposit amount must be positive.")
    
    def withdraw(self, money, person, date):
        if money > 0 and self.balance >= money:
            self.balance -= money
            print(f"{money} withdrawn by {person} on {date}. New balance: {self.balance}")
        else:
            print("Insufficient balance or invalid withdrawal amount.")

class SavingAccount(BankAccount):
    def __init__(self, bank_name, acc_name, acc_id, balance=0):
        super().__init__(bank_name, acc_name, acc_id, balance)
    
    def withdraw(self, money, person, date):
        if money > 0 and self.balance >= money:
            super().withdraw(money, person, date)
        else:
            print("Cannot withdraw: insufficient funds or invalid amount. Savings account cannot have negative balance.")

class OverDrawnAccount(BankAccount):
    def __init__(self, bank_name, acc_name, acc_id, balance=0, overdraw_limit=0):
        super().__init__(bank_name, acc_name, acc_id, balance)
        self.overdraw_limit = overdraw_limit
    
    def withdraw(self, money, person, date):
        if money > 0 and (self.balance - money) >= -self.overdraw_limit:
            self.balance -= money
            print(f"{money} withdrawn by {person} on {date}. New balance: {self.balance}")
        else:
            print("Cannot withdraw: exceeds overdraw limit or invalid amount.")

class Customer:
    def __init__(self, name):
        self.name = name
        self.accounts = []
    
    def add_account(self, account):
        if isinstance(account, BankAccount):
            self.accounts.append(account)
            print(f"Account {account.acc_id} added to customer {self.name}")
        else:
            print("Invalid account. Must be an instance of BankAccount or its subclasses.")
    
    def print_accounts(self):
        print(f"Customer {self.name} owns the following accounts:")
        for account in self.accounts:
            print(f"Account ID: {account.acc_id}, Balance: {account.get_balance()}")
    
    def get_total_balance(self):
        total_balance = sum(account.get_balance() for account in self.accounts)
        return total_balance

# Example usage
customer1 = Customer("John Doe")
saving_acc = SavingAccount("Bank A", "John Doe", "SA123", 1000)
overdraw_acc = OverDrawnAccount("Bank A", "John Doe", "OD456", 500, overdraw_limit=1000)

customer1.add_account(saving_acc)
customer1.add_account(overdraw_acc)

customer1.print_accounts()
print("Total balance:", customer1.get_total_balance())

saving_acc.deposit(200, "John Doe", "2024-06-29")
saving_acc.withdraw(150, "John Doe", "2024-06-30")

overdraw_acc.withdraw(700, "John Doe", "2024-06-29")
overdraw_acc.withdraw(800, "John Doe", "2024-06-30")

customer1.print_accounts()
print("Total balance:", customer1.get_total_balance())