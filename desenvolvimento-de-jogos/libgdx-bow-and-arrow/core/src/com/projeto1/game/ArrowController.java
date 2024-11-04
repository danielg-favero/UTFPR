package com.projeto1.game;

import com.badlogic.gdx.graphics.Texture;
import com.badlogic.gdx.graphics.g2d.SpriteBatch;
import com.badlogic.gdx.utils.Pool;

import java.util.ArrayList;


public  class ArrowController {
    static ArrowController ref;
    SpriteBatch batch;
    Texture texture;


    public ArrowController(SpriteBatch batch, Texture texture) {
        this.batch = batch;
        this.texture = texture;
        ref = this;
    }
    private final ArrayList<Arrow> activeArrows = new ArrayList<Arrow>(), deadArrows = new ArrayList<Arrow>();

    public void render(float delta){
        if(activeArrows.size() > 0 && activeArrows != null) {
            for (Arrow arrow : activeArrows) {
                System.out.println(activeArrows);
                arrow.update(delta);
                arrow.render();

                if (!arrow.isActive) {
                    activeArrows.remove(arrow);
                    deadArrows.add(arrow);
                }
            }
        }
    }

    public void init(float x, float y){
        Arrow arrow;
        if (deadArrows.size() > 0){
            arrow = deadArrows.remove(0);
        } else {
            arrow = new Arrow(batch, texture);
            arrow.init(x, y);
        }

        activeArrows.add(arrow);
    }



}
