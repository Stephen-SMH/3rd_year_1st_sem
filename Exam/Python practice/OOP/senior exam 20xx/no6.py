from abc import ABC, abstractmethod

class PhoneService(ABC):
    def __init__(self, phone_no, customer_name, month_year):
        self.phone_no = phone_no
        self.customer_name = customer_name
        self.month_year = month_year

    @abstractmethod
    def find_cost(self):
        pass
class Post_paid(PhoneService):
    def __init__(self, phone_no, customer_name, month_year, monthly_fix_cost, monthly_allowance, call_duration):
        super().__init__(phone_no, customer_name, month_year)
        self.monthly_fix_cost = monthly_fix_cost
        self.monthly_allowance = monthly_allowance
        self.call_duration = call_duration

    def find_cost(self):
        if self.call_duration <= self.monthly_allowance:
            return self.monthly_fix_cost
        else:
            extra_minutes = self.call_duration - self.monthly_allowance
            extra_cost = extra_minutes * 1  # 1 Baht per extra minute
            total_cost = self.monthly_fix_cost + extra_cost
            return total_cost

class Pre_paid(PhoneService):
    def __init__(self, phone_no, customer_name, month_year, call_duration):
        super().__init__(phone_no, customer_name, month_year)
        self.call_duration = call_duration

    def find_cost(self):
        return self.call_duration * 2  # 2 Baht per minute

class Fixed_line(PhoneService):
    def __init__(self, phone_no, customer_name, month_year, num_local_calls):
        super().__init__(phone_no, customer_name, month_year)
        self.num_local_calls = num_local_calls

    def find_cost(self):
        return self.num_local_calls * 3  # 3 Baht per local call

def main():
    # Post-paid service details
    post_paid = Post_paid("081-000-0007", "John English", "09-2021", 800, 1000, 1250)
    post_paid_cost = post_paid.find_cost()
    print(f"Post-paid service cost: {post_paid_cost} Bahts")

    # Pre-paid service details
    pre_paid = Pre_paid("080-000-0007", "John English", "09-2021", 100)
    pre_paid_cost = pre_paid.find_cost()
    print(f"Pre-paid service cost: {pre_paid_cost} Bahts")

    # Fixed-line service details
    fixed_line = Fixed_line("02-000-0007", "John English", "09-2021", 200)
    fixed_line_cost = fixed_line.find_cost()
    print(f"Fixed-line service cost: {fixed_line_cost} Bahts")

if __name__ == "__main__":
    main()

