// classe Roda, cada veículo terá 4 rodas
public class Roda {
    // variável que controla se o pneu está calibrado ou não
    private boolean estaCalibrada;

    // método construtor que inicia as variáveis da classe
    public Roda() {
        this.estaCalibrada = false;
    }

    // função que retorna true se o pneu está calibrada e false caso o contrário
    public boolean getCalibragem() {
        return this.estaCalibrada;
    }

    // função que seta a calibragem através de um parâmetro boolean passado como
    // parâmetro
    public void setCalibragem(boolean calibrar) {
        this.estaCalibrada = calibrar;
    }
}
