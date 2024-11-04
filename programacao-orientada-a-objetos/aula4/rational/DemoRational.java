package rational;

public class DemoRational {
    public static void main(String[] args) {
        Rational first = new Rational(1, 2);
        Rational second = new Rational(1, 2);
        Rational third = new Rational();
        third = third.sum(first, second);

        System.out.println(third);
    }
}
