from abc import ABC, abstractmethod

# Define abstract classes
class SaleItem(ABC):
    @abstractmethod
    def calculate_cost(self) -> float:
        pass

class Food(SaleItem):
    pass

# Define concrete classes
class Book(SaleItem):
    def __init__(self, cover_price: float):
        self.cover_price = cover_price

    def calculate_cost(self) -> float:
        return self.cover_price * 0.85

class Appliance(SaleItem):
    def __init__(self, price: float):
        self.price = price

    def calculate_cost(self) -> float:
        return self.price * 1.07

class ItemizedFood(Food):
    def __init__(self, unit_price: float, quantity: int):
        self.unit_price = unit_price
        self.quantity = quantity

    def calculate_cost(self) -> float:
        return self.unit_price * self.quantity

class MeasuredFood(Food):
    def __init__(self, price_per_kg: float, weight_kg: float):
        self.price_per_kg = price_per_kg
        self.weight_kg = weight_kg

    def calculate_cost(self) -> float:
        return self.price_per_kg * self.weight_kg

# Main program to calculate total cost
def main():
    items = [
        ItemizedFood(unit_price=40, quantity=2),     # 2 bottles of vegetable oil, each 40 Bahts
        MeasuredFood(price_per_kg=70, weight_kg=1.8), # 1.8 Kg of mangoes, each Kg 70 Bahts
        Book(cover_price=200),                        # one Python book costs 200 Bahts
        Appliance(price=1200)                         # one rice cooker costs 1200 Bahts
    ]

    total_cost = sum(item.calculate_cost() for item in items)
    print(f"Total cost of purchased items: {total_cost:.2f} Bahts")

if __name__ == "__main__":
    main()