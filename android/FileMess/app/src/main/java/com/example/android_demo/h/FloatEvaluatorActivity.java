package com.example.android_demo.h;

import android.os.Bundle;

import androidx.appcompat.app.AppCompatActivity;

import com.example.android_demo.h.view.AnimView2;

public class FloatEvaluatorActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(new AnimView2(this));
    }
}
