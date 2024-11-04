package quadrilatero;

public class Quadrilatero {
    protected Point point1;
    protected Point point2;
    protected Point point3;
    protected Point point4;

    public Quadrilatero(Point p1, Point p2, Point p3, Point p4) {
        point1 = new Point(p1);
        point2 = new Point(p2);
        point3 = new Point(p3);
        point4 = new Point(p4);
    }

    public String toString() {
        String s = "(" + point1.getX() + ", " + point1.getY() + "), \n";
        s += "(" + point2.getX() + ", " + point2.getY() + "), \n";
        s += "(" + point3.getX() + ", " + point3.getY() + "), \n";
        s += "(" + point4.getX() + ", " + point4.getY() + "), \n";
        s += "Área: " + this.area() + "u.a\n";

        return s;
    }

    public double area() {
        double longerBase = this.point4.getX() - this.point1.getX();
        double smallerBase = this.point3.getX() - this.point2.getX();
        double height = this.point2.getY() - this.point1.getY();

        return ((longerBase + smallerBase) * (height)) / 2;
    }
}
