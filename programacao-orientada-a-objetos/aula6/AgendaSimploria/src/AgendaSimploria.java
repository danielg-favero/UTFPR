import java.io.FileInputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.ObjectInput;
import java.io.ObjectInputStream;
import java.io.ObjectOutput;
import java.io.ObjectOutputStream;
import java.util.Scanner;

public class AgendaSimploria {
    static Scanner teclado = new Scanner(System.in);

    public static void main(String[] args) throws Exception {
        Pessoa[] agenda = new Pessoa[10];
        menu(agenda);
    }

    public static void pausarExecucao() {
        String pausar = teclado.nextLine();
    }

    public static void menu(Pessoa[] agenda) {
        int opcao = 0;

        while (opcao != 6) {
            System.out.println("Bem Vindo");
            System.out.println("1) Incluir pessoa");
            System.out.println("2) Listas pessoas cadastradas na agenda");
            System.out.println("3) Excluir pessoa (Pelo nome)");
            System.out.println("4) Gravar agenda em arquivo");
            System.out.println("5) Ler a agenda em arquivo");
            System.out.println("6) Sair do programa");
            System.out.print("Opção: ");
            opcao = teclado.nextInt();
            teclado.nextLine();

            switch (opcao) {
            case 1: {
                incluirPessoa(agenda);
                break;
            }
            case 2: {
                listarPessoas(agenda);
                break;
            }
            case 3: {
                excluirPessoa(agenda);
                break;
            }
            case 4: {
                gravarEmAgenda(agenda);
                break;
            }
            case 5: {
                agenda = lerEmAgenda();
                break;
            }
            case 6: {
                break;
            }
            default: {
                System.out.println("Opcao inválida, tente novamente");
                pausarExecucao();
            }
            }

            System.out.print("\033[H\033[2J");
            System.out.flush();
        }
    }

    public static void incluirPessoa(Pessoa[] agenda) {
        int i;
        String nome;
        String cpf;

        System.out.print("\nNome: ");
        nome = teclado.nextLine();

        System.out.print("CPF: ");
        cpf = teclado.nextLine();

        for (i = 0; i < agenda.length; i++) {
            if (agenda[i] == null) {
                agenda[i] = new Pessoa(nome, cpf);
                i = agenda.length;
                System.out.println("Pessoa inserida com sucesso");
            }
        }

        if (i < agenda.length) {
            System.out.println("Não foi possível inserir a pessoa");
        }

        pausarExecucao();
    }

    public static void listarPessoas(Pessoa[] agenda) {
        for (Pessoa pessoa : agenda) {
            if (pessoa != null) {
                System.out.println(pessoa);
            }
        }
        pausarExecucao();
    }

    public static void excluirPessoa(Pessoa[] agenda) {
        int i;

        System.out.print("\nInforme o nome da pessoa: ");
        String nome = teclado.nextLine();

        for (i = 0; i < agenda.length; i++) {
            if (agenda[i] != null && agenda[i].getNome().equals(nome)) {
                agenda[i] = null;
                i = agenda.length;
                System.out.println("Pessoa removida com sucesso");
            }
        }

        if (i < agenda.length) {
            System.out.println("Não possível remover a pessoa");
        }

        pausarExecucao();
    }

    public static void gravarEmAgenda(Pessoa[] agenda) {
        File arquivo = new File("agenda.dat");

        try {
            FileOutputStream fout = new FileOutputStream(arquivo);
            ObjectOutputStream oos = new ObjectOutputStream(fout);

            // gravando o vetor de objetos pessoa no arquivo
            oos.writeObject(agenda);

            // fechar o fluxo de arquivos
            oos.flush();
            oos.close();
            fout.close();
        } catch (Exception ex) {
            System.out.println("Erro: " + ex.toString());
        }
    }

    public static Pessoa[] lerEmAgenda() {
        File arquivo = new File("agenda.dat");
        Pessoa[] agendaArq = null;

        try {
            FileInputStream fin = new FileInputStream(arquivo);
            ObjectInputStream oin = new ObjectInputStream(fin);

            // ler as informações dentro do arquivo
            agendaArq = (Pessoa[]) oin.readObject();

            // fechando o fluxo de arquivos
            oin.close();
            fin.close();

        } catch (Exception ex) {
            System.out.println("Erro: " + ex.toString());
        }
        return agendaArq;
    }
}
