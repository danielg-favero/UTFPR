package com.projeto1.game;

import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.graphics.Texture;
import com.badlogic.gdx.graphics.g2d.Sprite;
import com.badlogic.gdx.graphics.g2d.SpriteBatch;

public class Player extends Sprite {
    float x = 0;
    float y = 0;
    boolean isUpPressed = false;
    boolean isDownPressed = false;
    float speed = 10.0f;
    Texture arrowTexture;
    SpriteBatch batch;
    PlayerInputProcessor playerInputProcessor;

    public Player() {
        super(ProjectOne.manager.<Texture>get("shot_1.png"));
        playerInputProcessor = new PlayerInputProcessor();
        Gdx.input.setInputProcessor(playerInputProcessor);

        arrowTexture = new Texture("arrow.png");
        new ArrowController(batch, arrowTexture);
    }

    public void draw(SpriteBatch batch) {
        super.draw(batch);
        this.update();
    }

    public void update() {
        if(playerInputProcessor.up && y < Gdx.graphics.getHeight() - speed) {
            y += speed;
        } else if(playerInputProcessor.down && y >= 0) {
            y -= speed;
        }

        ArrowController.ref.render(Gdx.graphics.getDeltaTime());
    }
}
