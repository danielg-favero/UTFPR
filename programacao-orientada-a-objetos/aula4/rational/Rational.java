package rational;

public class Rational {
    private int numerator;
    private int denominator;

    public Rational(int n, int d) {
        numerator = n;
        denominator = d;

        reduzir(numerator, denominator);
    }

    public Rational() {
        numerator = 1;
        denominator = 1;
    }

    public int getNumerator() {
        return numerator;
    }

    public void setNumerator(int n) {
        numerator = n;
    }

    public int getDenominator() {
        return denominator;
    }

    public void setDenominator(int d) {
        denominator = d;
    }

    public Rational sum(Rational r1, Rational r2) {
        int a = r1.getNumerator();
        int b = r1.getDenominator();

        int c = r2.getNumerator();
        int d = r2.getDenominator();

        Rational r = new Rational(a * d + c * b, b * d);

        return r;
    }

    public Rational sub(Rational r1, Rational r2) {
        int a = r1.getNumerator();
        int b = r1.getDenominator();

        int c = r2.getNumerator();
        int d = r2.getDenominator();

        Rational r = new Rational(a * d - c * b, b * d);

        return r;
    }

    public Rational mult(Rational r1, Rational r2) {
        int a = r1.getNumerator();
        int b = r1.getDenominator();

        int c = r2.getNumerator();
        int d = r2.getDenominator();

        Rational r = new Rational(a * c, b * d);

        return r;
    }

    public Rational div(Rational r1, Rational r2) {
        int a = r1.getNumerator();
        int b = r1.getDenominator();

        int c = r2.getNumerator();
        int d = r2.getDenominator();

        Rational r = new Rational(a * d, b * c);

        return r;
    }

    public void reduzir(int n, int d) {
        int _n = n;
        int _d = d;

        int i = 1;

        if (_d % _n == 0) {
            while (i < 10) {
                if (_n % i == 0 && _d % i == 0) {
                    _n = _n / i;
                    _d = _d / i;
                    i = 1;
                }
                i++;
            }
        }
        if (_n % _d == 0) {
            _n = _n / _d;
            _d = 1;
        }

        n = _n;
        d = _d;
    }

    public String toString() {
        if (denominator == 1) {
            return numerator + "";
        } else {
            return numerator + " / " + denominator;
        }
    }

    public void printFloatPoint() {
        double n = (double) numerator / denominator;

        System.out.printf("%.2f", n);
    }
}