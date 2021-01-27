package com.example.android_demo.a;


import android.content.Intent;
import android.os.Bundle;

import androidx.appcompat.app.AppCompatActivity;

import com.example.android_demo.R;

public class Relati3Activity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_relati3);
        final Intent it = new Intent(Relati3Activity.this, AdActivity.class);
        Thread thread = new Thread() {
            @Override
            public void run() {
                try {
                    sleep(2000);
                    startActivity(it);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        };
        thread.start();
    }
}
