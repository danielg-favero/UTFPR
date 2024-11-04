package quadrilatero;

public class Demo {
    public static void main(String[] args) {
        Trapezio a = new Trapezio(new Point(0, 0), new Point(1, 1), 10, 5);
        Paralelogramo b = new Paralelogramo(new Point(0, 0), new Point(1, 1), 10);
        Retangulo c = new Retangulo(new Point(0, 0), 10, 2);
        Quadrado d = new Quadrado(new Point(0, 0), 10);

        System.out.println(a);
        System.out.println(b);
        System.out.println(c);
        System.out.println(d);
    }
}
