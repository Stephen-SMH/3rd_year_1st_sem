class SavingAccount:
    def __init__(self, bank_name, acc_name, acc_id, balance=0):
        self.bank_name = bank_name
        self.acc_name = acc_name
        self.acc_id = acc_id
        self.balance = balance
        self.transaction_history = []

    def deposit(self, money, person, date):
        self.balance += money
        self.transaction_history.append({
            'type': 'deposit',
            'amount': money,
            'person': person,
            'date': date,
            'balance': self.balance
        })

    def withdraw(self, money, person, date):
        if self.balance >= money:
            self.balance -= money
            self.transaction_history.append({
                'type': 'withdraw',
                'amount': money,
                'person': person,
                'date': date,
                'balance': self.balance
            })
            return True
        else:
            print("Insufficient funds for withdrawal.")
            return False

    def get_balance(self):
        return self.balance

    def print_statement(self):
        print(f"Account Statement for {self.acc_name} (ID: {self.acc_id}) at {self.bank_name}")
        for transaction in self.transaction_history:
            print(f"{transaction['date']} - {transaction['type'].capitalize()} of {transaction['amount']} by {transaction['person']}. Balance: {transaction['balance']}")

class OverDrawnAccount(SavingAccount):
    def __init__(self, bank_name, acc_name, acc_id, overdraw_limit, balance=0):
        super().__init__(bank_name, acc_name, acc_id, balance)
        self.overdraw_limit = overdraw_limit

    def withdraw(self, money, person, date):
        if self.balance - money >= -self.overdraw_limit:
            self.balance -= money
            self.transaction_history.append({
                'type': 'withdraw',
                'amount': money,
                'person': person,
                'date': date,
                'balance': self.balance
            })
            return True
        else:
            print("Withdrawal denied. Overdraw limit exceeded.")
            return False

# Create a SavingAccount
savings = SavingAccount('Bank A', 'John Doe', '12345', 1000)
savings.deposit(500, 'John Doe', '2024-06-29')
savings.withdraw(300, 'John Doe', '2024-06-30')
savings.print_statement()

# Create an OverDrawnAccount
overdrawn = OverDrawnAccount('Bank B', 'Jane Smith', '67890', 500, 1000)
overdrawn.deposit(200, 'Jane Smith', '2024-06-29')
overdrawn.withdraw(1500, 'Jane Smith', '2024-06-30')  # Should be allowed
overdrawn.withdraw(300, 'Jane Smith', '2024-07-01')   # Should be denied if it exceeds limit
overdrawn.print_statement()
