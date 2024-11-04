package com.projeto1.game;

import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.graphics.Texture;
import com.badlogic.gdx.graphics.g2d.SpriteBatch;
import com.badlogic.gdx.math.Vector2;
import com.badlogic.gdx.utils.Pool;

public class Arrow implements Pool.Poolable {
    public Vector2 position;
    public boolean isActive;
    float speed = 300.0f;
    SpriteBatch batch;
    Texture texture;

    public Arrow(SpriteBatch batch, Texture texture) {
        this.batch = batch;
        this.texture = texture;
    }

    public void init(float x, float y) {
        position = new Vector2();
        position.set(x, y);
        isActive = true;
    }

    @Override
    public void reset() {
        position.set(0, 0);
        isActive = false;
    }

    public void update(float delta) {
        if(isOutOfScreen()){
            isActive = false;
        } else {
            position.add(1 * delta * speed, 0);
        }
    }

    public void render() {
        batch.begin();
        batch.draw(this.texture, this.position.x, this.position.y);
        batch.end();
    }

    private boolean isOutOfScreen() {
        return position.x > Gdx.graphics.getWidth();
    }
}
