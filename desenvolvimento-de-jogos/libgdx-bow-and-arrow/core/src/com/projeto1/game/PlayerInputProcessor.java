package com.projeto1.game;

import com.badlogic.gdx.Input;
import com.badlogic.gdx.InputProcessor;

public class PlayerInputProcessor implements InputProcessor {
    public boolean up, down, space;
    @Override
    public boolean keyDown(int keycode) {
        if(keycode == Input.Keys.W) {
            up = true;
        } else if (keycode == Input.Keys.S) {
            down = true;
        } else if (keycode == Input.Keys.SPACE) {
            space = true;
        }

        return false;
    }

    @Override
    public boolean keyUp(int keycode) {
        if(keycode == Input.Keys.W) {
            up = false;
        } else if (keycode == Input.Keys.S) {
            down = false;
        } else if (keycode == Input.Keys.SPACE) {
            space = false;
        }

        return false;
    }

    @Override
    public boolean keyTyped(char character) {
        return false;
    }

    @Override
    public boolean touchDown(int screenX, int screenY, int pointer, int button) {
        return false;
    }

    @Override
    public boolean touchUp(int screenX, int screenY, int pointer, int button) {
        return false;
    }

    @Override
    public boolean touchCancelled(int screenX, int screenY, int pointer, int button) {
        return false;
    }

    @Override
    public boolean touchDragged(int screenX, int screenY, int pointer) {
        return false;
    }

    @Override
    public boolean mouseMoved(int screenX, int screenY) {
        return false;
    }

    @Override
    public boolean scrolled(float amountX, float amountY) {
        return false;
    }
}
