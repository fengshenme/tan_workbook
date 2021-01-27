package com.example.android_demo.f;

import android.content.Intent;
import android.os.Bundle;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

import com.example.android_demo.R;

public class Message2Activity extends AppCompatActivity {

    private TextView txtshow;
    private String name;
    private String sex;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_message2);

        txtshow = (TextView)findViewById(R.id.txtshow);
        //获得Intent对象,并且用Bundle出去里面的数据
        Intent it = getIntent();
        Bundle bd = it.getExtras();

        //按键值的方式取出Bundle中的数据
        name = bd.getCharSequence("user").toString();
        sex = bd.getCharSequence("sex").toString();
        txtshow.setText("尊敬的"+name + " " + sex + "士"+"恭喜你,注册成功~");
    }

}
