package quadrilatero;

public class Retangulo extends Paralelogramo {
    public Retangulo(Point p1, double width, double height) {
        super(p1, new Point(p1.getX(), p1.getY() + height), width);
    }
}
