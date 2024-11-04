import java.io.Serializable;

public class Pessoa implements Serializable {
    private String nome;
    private String cpf;

    public Pessoa(String nome, String cpf) {
        this.nome = nome;
        this.cpf = cpf;
    }

    public String getNome() {
        return this.nome;
    }

    public String toString() {
        return "Nome: " + this.nome + "\n" + "CPF: " + this.cpf + "\n";
    }
}
