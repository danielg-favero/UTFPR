import java.util.Random;

// classe veículo, o simulador poderá ter no máximo 20 veículos
public class Veiculo {
    private final int N_RODAS = 4; // número de pneus

    private static double tanque; // capacidade do tanque do veículo
    private static double valor; // valor do veículo

    private int id; // id do veículo
    private Roda[] rodas; // rodas do veículo
    private double combustivel; // quantidade de combustível do veículo
    private boolean ipvaPago; // controlar se o ipva está pago ou não
    private int blocosAndados; // quantidade de blocos andados

    // método construtor para iniciar todas as variáveis da classe
    public Veiculo(int id) {
        this.id = id;
        this.combustivel = 3.5; // combustível em litros
        this.blocosAndados = 0;

        Veiculo.tanque = 50; // capacidade do tanque em litros
        Veiculo.valor = 20000; // valor em R$

        // iniciar as rodas
        this.rodas = new Roda[this.N_RODAS];
        this.iniciarPneus();

        // iniciar o ipva
        // caso de r for par o ipva está pago, caso contrário não
        Random r = new Random();
        this.ipvaPago = r.nextInt(100) % 2 == 0 ? true : false;
    }

    // função para retornar o id do veículo
    public int getId() {
        return this.id;
    }

    // função para iniciar a calibragem dos pneus
    private void iniciarPneus() {
        int i;
        Random r = new Random(); // classe Random do java.util

        // percorrer todas as rodas do veículo
        for (i = 0; i < this.N_RODAS; i++) {
            this.rodas[i] = new Roda(); // criar nova roda
            int c = r.nextInt(100);

            // caso o valor de c for par o pneu é calibrado, caso contrário não
            if (c % 2 == 0) {
                this.rodas[i].setCalibragem(true);
            }
        }
    }

    // função para abastecer o veículo
    public boolean abastecer(double quantidade) {
        if (quantidade >= 0) {
            if (this.combustivel + quantidade <= Veiculo.tanque) {
                // caso a quantidade de combustível couber no tanque
                this.combustivel += quantidade;
            } else {
                // caso a quantidade de combustível for maior que o limite do tanque, deve-se
                // encher tudo até completar
                this.combustivel += Veiculo.tanque - this.combustivel;
            }

            return true;
        }

        return false;
    }

    // função que verificar se o veículo pode moder
    // um veículo poderá se mover se:
    // 1 - Todas os pneus estiverem calibradas
    // 2 - Possir combustível suficiente (cada movimento reduz 0,55L do tanque)
    // 3 - O ipva estiver pago
    private boolean podeMover() {
        // verificar se todas os pneus estão calibrar
        for (Roda roda : this.rodas) {
            if (!roda.getCalibragem()) {
                // roda não calibrada encontrada
                return false;
            }
        }

        return this.combustivel - 0.55 >= 0 && this.ipvaPago;
    }

    // função para movimentar o veículo
    // a função retorna verdadeiro caso o movimento for bem sucedido
    public boolean movimentar() {
        if (podeMover()) {
            // descontar 0,55L do tanque
            this.combustivel -= 0.55;

            // aumentar a quantidade de blocos andados
            this.blocosAndados += 5;

            // movimento foi bem sucedido
            return true;
        }

        // movimento não pôde ser realizado
        return false;
    }

    // função para esvaziar um pneu do veículo
    // o pneu a ser esvaziada é passado por parâmetro
    public void esvaziarPneu(int roda) {
        // percorrer todas as rodas e esvaziar os pneus
        this.rodas[roda].setCalibragem(false);
    }

    // sobrecarga do método esvaziarPneu
    // caso o usuário não informar a roda será esvaziado todas
    public void esvaziarPneu() {
        // percorrer todas as rodas e esvaziar os pneus
        for (Roda roda : rodas) {
            roda.setCalibragem(false);
        }
    }

    // função para calibrar um pneu do veículo
    // o pneu a ser calibrada é passado por parâmetro
    public void calibrarPneu(int roda) {
        this.rodas[roda].setCalibragem(true);
    }

    // sobrecarga do método calibrarPneu
    // caso o usuário não informar a roda será calibrado todas
    public void calibrarPneu() {
        // percorrer todas as rodas e calibrar os pneus
        for (Roda roda : rodas) {
            roda.setCalibragem(true);
        }
    }

    // função para desenhar o veículo na linha de comando
    public void desenhar() {
        int i;
        String espacos = "";

        // incluir o número de blocos andados antes da impressão do veículo
        for (i = 0; i < this.blocosAndados; i++)
            espacos += " ";

        System.out.println(espacos + "    ___  ");
        System.out.println(espacos + " __/ |_\\_");
        System.out.println(espacos + "|  _ " + this.id + "  _‘‘-.");
        System.out.println(espacos + "’-(_)---(_)--’\n");
    }

    // função para imprimir as informações do veículo
    public String toString() {
        // id
        String s = "\nid: " + this.id + "\n";

        // valor
        s += "Valor: " + Veiculo.valor + "\n";

        // combustível
        s += "Combustível: " + this.combustivel + "\n";

        // ipva pago
        String ipvaEstaPago = this.ipvaPago ? "Pago\n" : "Não pago\n";
        s += "IPVA: " + ipvaEstaPago;

        // calibragem dos pneus
        int i;
        String pneusCalibrados = "Pneus Calibradas: ";
        for (i = 0; i < this.N_RODAS; i++) {
            // 1 para calibrado e 0 para não calibrado
            pneusCalibrados += this.rodas[i].getCalibragem() ? "1 " : "0 ";
        }
        s += pneusCalibrados + '\n';

        return s;
    }
}
