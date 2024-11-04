package com.mygdx.game;

import com.badlogic.gdx.ApplicationAdapter;
import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.InputMultiplexer;
import com.badlogic.gdx.InputProcessor;
import com.badlogic.gdx.assets.AssetManager;
import com.badlogic.gdx.graphics.Texture;
import com.badlogic.gdx.graphics.g2d.SpriteBatch;
import com.badlogic.gdx.utils.ScreenUtils;
import com.mygdx.game.arrow.ArrowController;
import com.mygdx.game.balloon.Balloon;
import com.mygdx.game.balloon.BalloonController;
import com.mygdx.game.bow.Bow;

public class MeuJogo extends ApplicationAdapter {
	SpriteBatch batch;
	public static int score;
	public static Bow bow;
	public static AssetManager manager;
	public static InputMultiplexer multiplexer;
	public static int timer;

	public static void addInputProcessor(InputProcessor inputProcessor){
		if (multiplexer == null) multiplexer = new InputMultiplexer();
		multiplexer.addProcessor(inputProcessor);
		Gdx.input.setInputProcessor(multiplexer);
	}
	
	@Override
	public void create () {
		timer = 0;
		score = 0;
		batch = new SpriteBatch();

		manager = new AssetManager();
		manager.load("bow.png", Texture.class);
		manager.load("arrow.png", Texture.class);
		manager.load("balloon.png", Texture.class);
		manager.finishLoading();
		bow = new Bow();
		ArrowController.init();
		BalloonController.init();
	}

	@Override
	public void render () {
		ScreenUtils.clear(1, 1, 1, 1);
		Gdx.graphics.setTitle(Gdx.graphics.getFramesPerSecond()+"");
		batch.begin();

		bow.draw(batch, Gdx.graphics.getDeltaTime());
		ArrowController.draw(batch, Gdx.graphics.getDeltaTime());
		BalloonController.draw(batch, Gdx.graphics.getDeltaTime());
		batch.end();

		timer++;
		if(timer >= 500) {
			BalloonController.set((float)(Math.random() * Gdx.graphics.getWidth()), 0);
			timer = 0;
		}
	}
	
	@Override
	public void dispose () {
		batch.dispose();
	}
}
