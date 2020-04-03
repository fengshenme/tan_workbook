package com.example.demoone.h;

import android.content.Context;
import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Gallery;
import android.widget.ImageView;

import com.example.demoone.R;
import com.example.demoone.h.view.BlurMaskFilterView;

public class MaskFilterActivity extends AppCompatActivity {

    private Context mContext;

    private Button btn_mask;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_mask_filter);
    }


}
