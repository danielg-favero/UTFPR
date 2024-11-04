package com.mygdx.game.arrow;

import com.badlogic.gdx.graphics.g2d.SpriteBatch;
import com.mygdx.game.MeuJogo;

import java.util.concurrent.ConcurrentLinkedQueue;

public abstract class ArrowController {
    public static ConcurrentLinkedQueue<Arrow> aliveArrows;
    private static ConcurrentLinkedQueue<Arrow> deadArrows;

    public static void init(){
        aliveArrows = new ConcurrentLinkedQueue<Arrow>();
        deadArrows = new ConcurrentLinkedQueue<Arrow>();
        ArrowInputProcessor arrowInputProcessor = new ArrowInputProcessor();
        MeuJogo.addInputProcessor(arrowInputProcessor);
    }


    public static void set(float x, float y){
        Arrow a;

        if (!deadArrows.isEmpty()){
            a = deadArrows.remove();
        } else {
            a = new Arrow();
        }

        aliveArrows.add(a);
        a.setX(x);
        a.setY(y);
    }

    public static void draw(SpriteBatch batch, float delta){
        for (Arrow a : aliveArrows){
            a.draw(batch);
            a.update(delta);

            if (a.isOutOfScreen()){
                aliveArrows.remove(a);
                deadArrows.add(a);
            }
        }

        logger("Flechas disponíveis: " + deadArrows.size());
    }

    static void logger(String s) {
        System.out.println(s);
    }
}
