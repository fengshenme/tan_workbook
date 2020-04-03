package com.example.demoone.h;

import android.annotation.SuppressLint;
import android.graphics.drawable.AnimationDrawable;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.MotionEvent;
import android.view.View;
import android.widget.FrameLayout;

import com.example.demoone.R;
import com.example.demoone.h.view.FrameView;


public class AnimationDrawableActivity extends AppCompatActivity {

//    @Override
//    protected void onCreate(Bundle savedInstanceState) {
//        super.onCreate(savedInstanceState);
//        setContentView(R.layout.activity_animation_drawable);
//    }

    private FrameView fView;
    private AnimationDrawable anim = null;

    @SuppressLint("ResourceType")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        FrameLayout fly = new FrameLayout(this);
        setContentView(fly);
        fView = new FrameView(this);
        fView.setBackgroundResource(R.drawable.anim_zhuan);
        fView.setVisibility(View.INVISIBLE);
        anim = (AnimationDrawable) fView.getBackground();
        fView.setAnim(anim);
        fly.addView(fView);
        fly.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View v, MotionEvent event) {
                //设置按下时才产生动画效果
                if(event.getAction() == MotionEvent.ACTION_DOWN){
                    anim.stop();
                    float x = event.getX();
                    float y = event.getY();
                    fView.setLocation((int) y - 40,(int)x-20);  //View显示的位置
                    fView.setVisibility(View.VISIBLE);
                    anim.start();    //开启动画
                }
                return false;
            }
        });
    }

}
