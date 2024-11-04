public class Calculadora {
    public static void main(String[] args) {
        // não foi passado argumentos
        if (args.length < 3) {
            System.out.println("Esse programa precisa de 3 ou mais argumentos");
            System.exit(1);
        }

        char operator = args[0].charAt(0);
        int result = 0;

        if (operator != '+' && operator != 'x') {
            System.out.println("Informe um operador válido");
        }

        switch (operator) {
        case '+': {
            int i;
            result = 0;

            for (i = 1; i < args.length; i++) {
                result += Integer.parseInt(args[i]);
            }

            break;
        }
        case 'x': {
            int i;
            result = 1;

            for (i = 1; i < args.length; i++) {
                result *= Integer.parseInt(args[i]);
            }

            break;
        }
        }

        int i;
        for (i = 1; i < args.length; i++) {
            System.out.print(args[i] + " " + operator + " ");
        }
        System.out.println("= " + result);
    }
}
