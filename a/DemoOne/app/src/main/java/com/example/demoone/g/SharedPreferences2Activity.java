package com.example.demoone.g;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;

import com.example.demoone.R;
import com.example.demoone.g.utils.MD5;

public class SharedPreferences2Activity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_shared_preferences2);

        Log.e("16---","aa");

        Log.e("HeHe", MD5.getMD5x10("呵呵"));

    }
}
