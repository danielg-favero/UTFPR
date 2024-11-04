public class Ponto2D {
    private double x, y;

    public Ponto2D(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }

    public boolean eIgual(Ponto2D ponto2) {
        return x == ponto2.x && y == ponto2.y;
    }

    public Ponto2D origem() {
        return new Ponto2D(0, 0);
    }

    public Ponto2D clona() {
        Ponto2D temp = new Ponto2D(x, y);
        return temp;
    }

    public String toString() {
        return "(" + x + ", " + y + ")";
    }
}
