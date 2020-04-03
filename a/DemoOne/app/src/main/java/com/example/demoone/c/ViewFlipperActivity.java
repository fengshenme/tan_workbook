package com.example.demoone.c;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.ViewFlipper;

import com.example.demoone.R;

public class ViewFlipperActivity extends AppCompatActivity {
    private ViewFlipper vflp_help;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_view_flipper);

        vflp_help = findViewById(R.id.vflp_help);
        vflp_help.startFlipping();
    }
}
