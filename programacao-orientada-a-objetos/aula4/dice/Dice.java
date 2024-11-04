package dice;

import java.util.Random;

public class Dice {
    private int sideUp;

    public Dice() {

    }

    public int getSideUp() {
        return sideUp;
    }

    public void roll() {
        Random r = new Random();
        sideUp = r.nextInt(6) + 1;
    }
}

class DiceDemo {
    public static void main(String[] args) {
        Dice first = new Dice();
        Dice second = new Dice();

        // rolar os dados
        first.roll();
        second.roll();

        int sum = first.getSideUp() + second.getSideUp();

        // mostrar a soma dos lados
        System.out.println("Soma dos lados dos dados: " + sum);
    }
}