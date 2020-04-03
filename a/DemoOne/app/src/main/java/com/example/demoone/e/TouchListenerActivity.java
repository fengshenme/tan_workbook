package com.example.demoone.e;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.MotionEvent;
import android.view.View;
import android.widget.ImageView;
import android.widget.Toast;

import com.example.demoone.R;

public class TouchListenerActivity extends AppCompatActivity {

    private ImageView imgtouch;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_touch_listener);

        imgtouch = findViewById(R.id.imgtouch);
        imgtouch.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View v, MotionEvent event) {
                Toast.makeText(getApplicationContext(),"你通过监听器模式:OnTouchListener摸了伦家~", Toast.LENGTH_LONG).show();
                return true;
            }
        });

    }

}
