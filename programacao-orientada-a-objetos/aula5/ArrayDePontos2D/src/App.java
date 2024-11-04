public class App {
    public static void main(String[] args) {
        ArrayDePonto2D pontos = new ArrayDePonto2D(6);

        pontos.modifica(0, 1, 1);
        pontos.modifica(1, 1, 0);
        pontos.modifica(6, 0, 1);

        System.out.println(pontos);
        System.out.println(pontos.tamanho());
        System.out.println(pontos.valor(0));
    }
}
