package quadrilatero;

public class Trapezio extends Quadrilatero {

    public Trapezio(Point p1, Point p2, double longerBase, double smallerbase) {
        super(p1, p2, new Point(p2.getX() + smallerbase, p2.getY()), new Point(p1.getX() + longerBase, p1.getY()));
    }
}
