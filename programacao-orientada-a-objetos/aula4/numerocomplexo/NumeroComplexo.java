package numerocomplexo;

public class NumeroComplexo {
    private double real;
    private double imaginario;

    public NumeroComplexo() {
        real = 0;
        imaginario = 0;
    }

    public void inicializarNumero(double r, double i) {
        real = r;
        imaginario = i;
    }

    public String imprimeNumero() {
        return real + " + " + imaginario + "i";
    }

    public boolean eIgual(NumeroComplexo z) {
        return real == z.real && imaginario == z.imaginario;
    }

    public void soma(NumeroComplexo z) {
        real = real + z.real;
        imaginario = imaginario + z.imaginario;
    }

    public void subtrai(NumeroComplexo z) {
        real = real - z.real;
        imaginario = imaginario - z.imaginario;
    }

    public void multiplica(NumeroComplexo z) {
        real = real * z.real - imaginario * z.imaginario;
        imaginario = real * z.imaginario + imaginario * z.real;
    }

    public void divide(NumeroComplexo z) {
        real = (real * z.real + imaginario * z.imaginario) / (z.real * z.real + z.imaginario * z.imaginario);
        imaginario = (imaginario * z.real - real * z.imaginario) / (z.real * z.real + z.imaginario * z.imaginario);
    }
}

class DemoNumeroComplexo {
    public static void main(String[] args) {
        NumeroComplexo z = new NumeroComplexo();
        NumeroComplexo w = new NumeroComplexo();

        z.inicializarNumero(1, 2);
        w.inicializarNumero(2, 1);

        System.out.println("número complexo: " + z.imprimeNumero());

        System.out.print(z.imprimeNumero() + " é igual à " + w.imprimeNumero() + "? ");
        System.out.println(z.eIgual(w));

        System.out.print("(" + z.imprimeNumero() + ")" + " + " + "(" + w.imprimeNumero() + ")" + " = ");
        z.soma(w);
        System.out.println(z.imprimeNumero());

        System.out.print("(" + z.imprimeNumero() + ")" + " - " + "(" + w.imprimeNumero() + ")" + " = ");
        z.subtrai(w);
        System.out.println(z.imprimeNumero());

        System.out.print("(" + z.imprimeNumero() + ")" + " * " + "(" + w.imprimeNumero() + ")" + " = ");
        z.multiplica(w);
        System.out.println(z.imprimeNumero());

        System.out.print("(" + z.imprimeNumero() + ")" + " / " + "(" + w.imprimeNumero() + ")" + " = ");
        z.divide(w);
        System.out.println(z.imprimeNumero());
    }
}
