class ContaBancaria {
    private String nomeCorrentista;
    private double saldo;

    public ContaBancaria(String n, double s) {
        nomeCorrentista = n;
        saldo = s;
    }

    public double getSaldo() {
        return saldo;
    }

    public String getNome() {
        return nomeCorrentista;
    }

    public void deposita(double quantia) {
        if (quantia >= 0) {
            saldo += quantia;
        }
    }

    public void retira(double quantia) {
        if (quantia <= saldo && quantia >= 0) {
            saldo -= quantia;
        }
    }

    public void transfereDe(ContaBancaria de, double quanto) {
        deposita(quanto);
        de.retira(quanto);
    }

    public String toString() {
        return "Conta de " + nomeCorrentista + " tem saldo " + saldo;
    }
}

public class Banco {
    public static void main(String[] args) {
        ContaBancaria[] contas = new ContaBancaria[10];

        contas[0] = new ContaBancaria("Daniel Favero", 10000);
        contas[1] = new ContaBancaria("Cinglair Capello", 5000);
        contas[2] = new ContaBancaria("Igor Laggagio", 2500);

        System.out.println("Soma total dos saldos em contas: " + total(contas));
    }

    static double total(ContaBancaria[] contas) {
        double resultado = 0;

        for (ContaBancaria conta : contas) {
            if (conta != null) {
                resultado += conta.getSaldo();
            }
        }

        return resultado;
    }
}