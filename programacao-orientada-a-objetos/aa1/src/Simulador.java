import java.util.Scanner;

/*
*   SIMULADOR DE CORRIDA DE VEÍCULOS 
*   Desenvolvido por: Daniel Gustavo Favero
*   RA: 2157128
*   Professora: Luciene de Oliveira Marin
*   Disciplina: Programação Orientada a Objetos
*   Turma: 4CP
*   Ano/Perído: 2021/1
*   Universidade Tecnológica Federal do Paraná - PB
*/

public class Simulador {
    // Número de veículos do array
    private static final int N_VEICULOS = 20;

    // array de veículos com o total de 20 veiculos
    private static Veiculo[] veiculos = new Veiculo[N_VEICULOS];

    public static void main(String[] args) {
        menu();
    }

    // função para pausar a execução da aplicação
    // usada para o usuário poder ler o que tem em tela antes de prosseguir com a
    // continuação do programa
    private static void pausarExecucao() {
        Scanner pausar = new Scanner(System.in);
        pausar.nextLine();
    }

    // função para limpar a tela toda vez que o menu é mostrado novamente em tela
    private static void limparTela() {
        System.out.print("\033[H\033[2J");
    }

    // função para solicitar o id do veiculo dentro do array
    public static int solicitarID() {
        System.out.print("\nInforme o id do veiculo: ");

        Scanner teclado = new Scanner(System.in);
        int id = teclado.nextInt(); // usuário informa o id

        // retornar o id digitado pelo usuário
        return id;
    }

    // função para mostrar o menu de opções do simulador para o usuário
    public static void menu() {
        int opcao = 0;

        // mostrar o menu enquanto o usuário não informar o opção de sair
        while (opcao != 11) {
            System.out.println("1) Incluir veículo");
            System.out.println("2) Remover veículo");
            System.out.println("3) Abastecer veículo");
            System.out.println("4) Movimentar veículo");
            System.out.println("5) Movimentar todos os veículos");
            System.out.println("6) Imprimir todos os dados de todos os veículos");
            System.out.println("7) Esvaziar pneu de veiculo");
            System.out.println("8) Calibrar pneu de veiculo");
            System.out.println("9) Calibrar todos os pneus dos veiculos");
            System.out.println("10) Imprimir pista");
            System.out.println("11) Sair");
            System.out.print("Opção: ");

            // ler a opção do menu
            Scanner teclado = new Scanner(System.in);
            opcao = teclado.nextInt();

            switch (opcao) {
            case 1: {
                incluirVeiculo();
                break;
            }
            case 2: {
                // solicitar o id do veiculo a ser excluido pelo usuário
                int id = solicitarID();

                excluirVeiculo(id);
                break;
            }
            case 3: {
                // solicitar o id do veiculo a ser abastecido
                int id = solicitarID();

                // usuário deve informar a quantidade de combustível a abastecer
                System.out.print("\nInforme a quantidade de combustível a ser adicionada: ");
                Scanner sc = new Scanner(System.in);
                double quantidade = sc.nextFloat();

                abastecerVeiculo(id, quantidade);
                break;
            }
            case 4: {
                int id = solicitarID();
                movimentarVeiculo(id);
                break;
            }
            case 5: {
                movimentarVeiculo();
                break;
            }
            case 6: {
                imprimirDadosVeiculos();
                break;
            }
            case 7: {
                // solicitar o id do veículo a calibrar os pneus
                int id = solicitarID();

                // solicitar o pneu a ser esvaziado
                System.out.print("\nInforme o pneu a ser esvaziada: ");
                Scanner sc = new Scanner(System.in);
                int pneu = sc.nextInt();

                esvaziarPneuDeVeiculo(id, pneu);
                break;
            }
            case 8: {
                // solicitar o id do veículo a calibrar os pneus
                int id = solicitarID();

                // solicitar o pneu a ser calibrado
                System.out.print("\nInforme o pneu a ser calibrado: ");
                Scanner sc = new Scanner(System.in);
                int pneu = sc.nextInt();

                // verificar se o veículo existe
                calibrarPneuDeVeiculo(id, pneu);
                break;
            }
            case 9: {
                calibrarPneuDeVeiculo();
                break;
            }
            case 10: {
                imprimirPista();
                break;
            }
            case 11: {
                sair();
                break;
            }
            default: {
                System.out.println("\nOpção inválida, tente novamente");
            }
            }

            pausarExecucao();
            limparTela();
        }
    }

    public static void incluirVeiculo() {
        int i;

        // incluir veiculos no array
        for (i = 0; i < veiculos.length; i++) {

            // incluir o veiculo caso haja posição disponível
            if (veiculos[i] == null) {
                // O id do veículo será sua posição dentro do array
                veiculos[i] = new Veiculo(i);

                // forçar saida do for
                i = veiculos.length;

                // mostrar mensagem de sucesso para o usuário
                System.out.println("\nVeículo adicionado com sucesso");
            }
        }

        // caso não for encontrado posição disponível, ou seja, i nunca é igual a
        // veiculos.length, avisar o usuário que não possível a inserção do veículo
        if (i < veiculos.length) {
            System.out.println("\nNão foi possível adicionar o veículo");
        }
    }

    public static void excluirVeiculo(int id) {
        // verificar se o veiculo existe no array
        if (veiculos[id] != null && id >= 0 && id < veiculos.length) {

            // caso tenha encontrado
            veiculos[id] = null;
            System.out.println("\nVeículo removido com sucesso");
        } else {

            // caso NÃO tenha encontrado
            System.out.println("\nNão foi possível remover o veículo");
        }
    }

    public static void abastecerVeiculo(int id, double quantidade) {
        if (veiculos[id] != null) {

            // caso o veiculo for encontrado
            if (veiculos[id].abastecer(quantidade)) {
                System.out.println("\nVeículo abastecido com sucesso");
            } else {
                System.out.println("\nInforme um quantidade de combustível válida");
            }
        } else {

            // caso o veiculo NÃO for encontrado
            System.out.println("\nNão foi possível abastecer o veículo");
        }
    }

    public static void movimentarVeiculo(int id) {

        // verificar se o veículo foi movimento e validar se sua movimentação foi bem
        // sucedida
        if (veiculos[id] != null && veiculos[id].movimentar()) {

            // veículo se movimentou com sucesso
            System.out.println("\nVeiculo movido com sucesso");
        } else {

            // veículo não conseguiu se movimentar
            System.out.println("\nNão foi possível movimentar o veiculo");
        }
    }

    public static void movimentarVeiculo() {
        // percorrer todos os veículos e eventualmente movimenta-los
        for (Veiculo veiculo : veiculos) {
            if (veiculo != null) {
                veiculo.movimentar();
            }
        }

        System.out.println("\nVeiculos movimentados com sucesso");
    }

    public static void imprimirDadosVeiculos() {
        // percorrer todos os veículos e imprimir todos os seus dados
        for (Veiculo veiculo : veiculos) {
            if (veiculo != null) {
                System.out.println(veiculo);
            }
        }
    }

    public static void esvaziarPneuDeVeiculo(int id, int pneu) {
        // verificar se o veículo existe
        if (veiculos[id] != null) {
            // verificar se a pneu informada é válida
            if (pneu >= 0 && pneu < 4) {
                veiculos[id].esvaziarPneu(pneu);

                // pneu esvaziado com sucesso
                System.out.println("\nPneus esvaziadas com sucesso");
            } else {

                // NÃO foi possível esvaziar os pneus
                System.out.println("\nInforme um valor válido para os Pneus");
            }

        } else {

            // NÃO foi possível esvaziar os pneus
            System.out.println("\nNão foi possível esvaziadar os Pneus");
        }
    }

    public static void calibrarPneuDeVeiculo(int id, int pneu) {
        if (veiculos[id] != null) {
            if (pneu >= 0 && pneu < 4) {
                veiculos[id].calibrarPneu(pneu);

                // Pneus calibrados com sucesso
                System.out.println("\nPneus calibradas com sucesso");
            } else {
                // NÃO foi possível esvaziar os pneus
                System.out.println("\nInforme um valor válido para os Pneus");
            }
        } else {

            // NÃO foi possível calibrar os pneus
            System.out.println("\nNão foi possível calibrar os pneus");
        }
    }

    // sobrecarga do método calibrarPneuDeVeiculo
    // caso o usuário não informar a roda e o id do veículo todos os pneus de todos
    // os
    // veículos serão calibrados
    public static void calibrarPneuDeVeiculo() {
        // percorrer todos os veículos e calibrar o pneu de cada um
        for (Veiculo veiculo : veiculos) {
            if (veiculo != null) {
                veiculo.calibrarPneu();
            }
        }

        System.out.println("\nPneus calibradas com sucesso");
    }

    public static void imprimirPista() {
        // desenhar todos os veiculo dentro do array
        for (Veiculo veiculo : veiculos) {
            if (veiculo != null) {
                veiculo.desenhar();
            }
        }
    }

    public static void sair() {
        // sair da aplicação
        System.exit(1);
    }
}
