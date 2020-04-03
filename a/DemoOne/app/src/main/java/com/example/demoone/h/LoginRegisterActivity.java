package com.example.demoone.h;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.view.animation.TranslateAnimation;
import android.widget.LinearLayout;

import com.example.demoone.R;

public class LoginRegisterActivity extends AppCompatActivity {

    private LinearLayout start_ctrl;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login_register);
        start_ctrl = (LinearLayout) findViewById(R.id.start_ctrl);
        //设置动画，从自身位置的最下端向上滑动了自身的高度，持续时间为500ms
        final TranslateAnimation ctrlAnimation = new TranslateAnimation(
                TranslateAnimation.RELATIVE_TO_SELF, 0, TranslateAnimation.RELATIVE_TO_SELF, 0,
                TranslateAnimation.RELATIVE_TO_SELF, 1, TranslateAnimation.RELATIVE_TO_SELF, 0);
        ctrlAnimation.setDuration(500l);     //设置动画的过渡时间
        start_ctrl.postDelayed(new Runnable() {
            @Override
            public void run() {
                start_ctrl.setVisibility(View.VISIBLE);
                start_ctrl.startAnimation(ctrlAnimation);
            }
        }, 2000);
    }

}
