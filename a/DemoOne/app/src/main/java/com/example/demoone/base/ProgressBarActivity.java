package com.example.demoone.base;

import android.graphics.drawable.AnimationDrawable;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.ImageView;

import com.example.demoone.R;

public class ProgressBarActivity extends AppCompatActivity {

    private ImageView img_pgbar;
    private AnimationDrawable ad;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_progress_bar);

        img_pgbar = (ImageView) findViewById(R.id.img_pgbar);
        ad = (AnimationDrawable) img_pgbar.getDrawable();
        img_pgbar.postDelayed(new Runnable() {
            @Override
            public void run() {
                ad.start();
            }
        }, 100);

    }

}
