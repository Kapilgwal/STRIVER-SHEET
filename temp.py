
def func(a,b):
    try:
        x = a / b # Division by zero
        return "Complete"
    except ZeroDivisionError as e:
        return "Incomplete"
    finally:
        return ("Execution complete")  # Runs whether exception occurs or not

print(func(5,1))