package com.example.android_demo.h;

import android.content.Context;
import android.os.Bundle;
import android.widget.Button;

import androidx.appcompat.app.AppCompatActivity;

import com.example.android_demo.R;

public class MaskFilterActivity extends AppCompatActivity {

    private Context mContext;

    private Button btn_mask;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_mask_filter);
    }


}
