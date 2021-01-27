package com.example.android_demo.f;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;

import androidx.appcompat.app.AppCompatActivity;

import com.example.android_demo.R;

public class Message3Activity extends AppCompatActivity {

    private Button btnchoose;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_message3);

        btnchoose = (Button)findViewById(R.id.btnchoose);
        btnchoose.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent it = new Intent(Message3Activity.this,Message4Activity.class);
                startActivityForResult(it,0x123);
            }
        });
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        if(requestCode == 0x123 && resultCode == 0x123)
        {
            Bundle bd = data.getExtras();
            int imgid = bd.getInt("imgid");
            //获取布局文件中的ImageView组件
            ImageView img = (ImageView)findViewById(R.id.imgicon);
            img.setImageResource(imgid);
        }
    }

}
