from no4 import EWallet


class SmartEWallet(EWallet):
    def __init__(self, owner, max_amount):
        super().__init__(owner, max_amount)
        self.transaction_history = []

    def deposit(self, amount):
        if super().deposit(amount):
            self.transaction_history.append(f"Deposited {amount}")

    def withdraw(self, amount, max_takeout_amount):
        if amount < 0:
            print("Cannot withdraw a negative amount.")
            return False
        
        if self.current_amount - amount < 0:
            print("Insufficient funds for withdrawal.")
            return False
        
        if amount > max_takeout_amount:
            print(f"Withdrawal amount {amount} exceeds the maximum limit of {max_takeout_amount}.")
            return False
        
        self.current_amount -= amount
        self.transaction_history.append(f"Withdrew {amount} (Max takeout: {max_takeout_amount})")
        print(f"Withdrew {amount}. Current balance is {self.current_amount}.")
        return True

    def view_transaction_history(self):
        print(f"Transaction History for {self.owner}:")
        for transaction in self.transaction_history:
            print(transaction)

# Example usage
smart_wallet = SmartEWallet("Jane Smith", 5000)
smart_wallet.deposit(1500)
smart_wallet.withdraw(500, 1000)
smart_wallet.withdraw(2000, 1500)
smart_wallet.view_transaction_history()

