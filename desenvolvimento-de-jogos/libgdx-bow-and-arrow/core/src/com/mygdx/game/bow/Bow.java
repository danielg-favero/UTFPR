package com.mygdx.game.bow;

import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.graphics.Texture;
import com.badlogic.gdx.graphics.g2d.Sprite;
import com.badlogic.gdx.graphics.g2d.SpriteBatch;
import com.mygdx.game.MeuJogo;

public class Bow extends Sprite {
    BowInputProcessor bowInputProcessor;

    public Bow(){
        super(MeuJogo.manager.<Texture>get("bow.png"));
        bowInputProcessor = new BowInputProcessor();
        MeuJogo.addInputProcessor(bowInputProcessor);
    }

    public void draw(SpriteBatch batch, float delta){
        super.draw(batch);
        update(delta);
    }

    public void update(float delta){
        if (bowInputProcessor.up){
            this.setY(this.getY() + 150*delta);
        }
        if (bowInputProcessor.down){
            this.setY(this.getY() - 150*delta);
        }
    }
}
