package com.example.demoone.h;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;

import com.example.demoone.R;
import com.example.demoone.h.view.AnimView;
import com.example.demoone.h.view.AnimView2;

public class FloatEvaluatorActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(new AnimView2(this));
    }
}
