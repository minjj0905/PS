def fibonacci_modulo(n, m):
    if n <= 1:
        return n % m

    previous, current = 0, 1
    for _ in range(n - 1):
        previous, current = current, (previous + current) % m

    return current


def pisano_period(m):
    previous, current = 0, 1
    for i in range(m * 6):
        previous, current = current, (previous + current) % m
        if previous == 0 and current == 1:
            return i + 1


n = int(input())
mod_value = 1000000

period_length = pisano_period(mod_value)
result = fibonacci_modulo(n % period_length, mod_value)

print(result)