class EWallet:
    def __init__(self, owner, max_amount):
        self.owner = owner
        self.max_amount = max_amount
        self.current_amount = 0

    def deposit(self, amount):
        if amount < 0:
            print("Cannot deposit a negative amount.")
            return False
        
        if self.current_amount + amount > self.max_amount:
            print(f"Deposit exceeds the maximum limit of {self.max_amount}.")
            return False
        
        self.current_amount += amount
        print(f"Deposited {amount}. Current balance is {self.current_amount}.")
        return True

    def withdraw(self, amount):
        if amount < 0:
            print("Cannot withdraw a negative amount.")
            return False
        
        if self.current_amount - amount < 0:
            print("Insufficient funds for withdrawal.")
            return False
        
        self.current_amount -= amount
        print(f"Withdrew {amount}. Current balance is {self.current_amount}.")
        return True

    def check_balance(self):
        print(f"Current balance: {self.current_amount}")
        return self.current_amount

# Example usage
wallet = EWallet("John Doe", 5000)
wallet.deposit(1500)
wallet.withdraw(500)
wallet.check_balance()
wallet.withdraw(2000)
wallet.deposit(10000)  # Should exceed the limit
wallet.check_balance()
