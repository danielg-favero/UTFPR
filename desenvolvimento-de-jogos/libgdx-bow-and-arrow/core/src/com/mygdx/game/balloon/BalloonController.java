package com.mygdx.game.balloon;

import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.graphics.g2d.SpriteBatch;
import com.mygdx.game.MeuJogo;
import com.mygdx.game.arrow.Arrow;
import com.mygdx.game.arrow.ArrowController;

import java.util.concurrent.ConcurrentLinkedQueue;

public class BalloonController {
    private static ConcurrentLinkedQueue<Balloon> aliveBalloons;
    private static ConcurrentLinkedQueue<Balloon> deadBalloons;
    private static double timer;

    public static void init(){
        aliveBalloons = new ConcurrentLinkedQueue<Balloon>();
        deadBalloons = new ConcurrentLinkedQueue<Balloon>();

        Balloon b = new Balloon();
        aliveBalloons.add(b);
    }


    public static void set(float x, float y){
        Balloon b;
        if (deadBalloons.size() > 0){
            b = deadBalloons.remove();
        } else {
            b = new Balloon();
        }
        aliveBalloons.add(b);
        b.setX(x);
        b.setY(y);
    }


    public static void draw(SpriteBatch batch, float delta){
        if(timer >= 5) timer -= 5;

        timer = Gdx.graphics.getDeltaTime();

        for (Balloon b : aliveBalloons){
            b.draw(batch);
            b.update(delta);

            if (b.isOutOfScreen()){
                aliveBalloons.remove(b);
                deadBalloons.add(b);
            }

            if(b.hasCollided()) {
                aliveBalloons.remove(b);
                deadBalloons.add(b);
                MeuJogo.score++;
                logger("Score: " + MeuJogo.score);
            }
        }
    }

    static void logger(String s) {
        System.out.println(s);
    }
}
