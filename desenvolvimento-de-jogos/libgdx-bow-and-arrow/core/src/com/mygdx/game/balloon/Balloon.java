package com.mygdx.game.balloon;

import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.graphics.Texture;
import com.badlogic.gdx.graphics.g2d.Sprite;
import com.badlogic.gdx.math.Vector2;
import com.mygdx.game.MeuJogo;
import com.mygdx.game.arrow.Arrow;
import com.mygdx.game.arrow.ArrowController;

public class Balloon extends Sprite {
    public Balloon() {
        super((Texture) MeuJogo.manager.get("balloon.png"));
    }

    public void update(float delta) {
        this.setY(this.getY() + 300 * delta);
    }

    public boolean hasCollided() {
        Vector2 arrowHitbox = new Vector2(0, 0);
        for (Arrow a : ArrowController.aliveArrows) {
            arrowHitbox.set(a.getX() + a.getWidth(), a.getY() + a.getHeight());
            if (arrowHitbox.x >= this.getX() && arrowHitbox.x <= this.getX() + this.getWidth() && arrowHitbox.y >= this.getY() && arrowHitbox.y <= this.getY() + this.getHeight()) {
                return true;
            }
        }

        return false;
    }


    public boolean isOutOfScreen() {
        return this.getY() > Gdx.graphics.getHeight();
    }
}
