package com.example.android_demo.b;

import android.content.Context;
import android.os.Bundle;
import android.widget.SeekBar;
import android.widget.TextView;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

import com.example.android_demo.R;


public class SeekBarActivity extends AppCompatActivity {

    private SeekBar sb_normal;
    private TextView txt_cur;
    private Context mContext;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_seek_bar);

        mContext = SeekBarActivity.this;
        bindViews();

    }

    private void bindViews() {
        sb_normal = findViewById(R.id.sb_normal);
        txt_cur = findViewById(R.id.txt_cur);
        sb_normal.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
                txt_cur.setText("当前进度值:" + progress + "  / 100 ");
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {
                Toast.makeText(mContext, "触碰SeekBar", Toast.LENGTH_SHORT).show();
            }

            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {
                Toast.makeText(mContext, "放开SeekBar", Toast.LENGTH_SHORT).show();
            }
        });
    }

}
