import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        long modValue = 1000000;

        long periodLength = pisanoPeriod(modValue);
        long result = fibonacciModulo(n % periodLength, modValue);

        System.out.println(result);
    }

    static long fibonacciModulo(long n, long m) {
        if (n <= 1) {
            return n % m;
        }

        long previous = 0, current = 1;
        for (long i = 0; i < n - 1; i++) {
            long temp = current;
            current = (previous + current) % m;
            previous = temp;
        }

        return current;
    }

    static long pisanoPeriod(long m) {
        long previous = 0, current = 1;
        for (long i = 0; i < m * 6; i++) {
            long temp = current;
            current = (previous + current) % m;
            previous = temp;

            if (previous == 0 && current == 1) {
                return i + 1;
            }
        }

        return -1;
    }
}