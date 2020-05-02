package com.example.android_demo.e;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

import com.example.android_demo.R;
import com.example.android_demo.e.common.MyClick;

// 直接使用Activity作为事件监听器
public class HandlingEventsActivity extends AppCompatActivity implements View.OnClickListener {
    private Button btnshow;
    private Button btnshow0;
    private Button btnshow1;
    private Button btnshow2;
    private TextView txtshow;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_handling_events);

        // 直接用匿名内部类
        btnshow = (Button) findViewById(R.id.btnshow);
        btnshow.setOnClickListener(new View.OnClickListener() {
            //重写点击事件的处理方法onClick()
            @Override
            public void onClick(View v) {
                //显示Toast信息
                Toast.makeText(getApplicationContext(), "你点击了按钮", Toast.LENGTH_SHORT).show();
            }
        });

        btnshow0 =  findViewById(R.id.btnshow0);
        //直接new一个内部类对象作为参数
        btnshow0.setOnClickListener(new BtnClickListener());

        btnshow1 = (Button) findViewById(R.id.btnshow1);
        txtshow = (TextView) findViewById(R.id.textshow);
        //直接new一个外部类，并把TextView作为参数传入
        btnshow1.setOnClickListener(new MyClick(txtshow));


        btnshow2 = (Button) findViewById(R.id.btnshow2);
        //直接写个this
        btnshow2.setOnClickListener(this);
    }
    //重写接口中的抽象方法
    @Override
    public void onClick(View v) {
        Toast.makeText(getApplicationContext(), "点击了按钮", Toast.LENGTH_SHORT).show();
    }

    //定义一个内部类,实现View.OnClickListener接口,并重写onClick()方法
    class BtnClickListener implements View.OnClickListener
    {
        @Override
        public void onClick(View v) {
            Toast.makeText(getApplicationContext(), "按钮被点击了", Toast.LENGTH_SHORT).show();
        }
    }

    //自定义一个方法,传入一个view组件作为参数

    /**
     * 就是直接在xml布局文件中对应得Activity中定义一个事件处理方法 eg:public void myClick(View source) source对应事件源(组件)
     * 接着布局文件中对应要触发事件的组建,设置一个属性:onclick = "myclick"即可
     * @param source
     */
    public void myclick(View source)
    {
        Toast.makeText(getApplicationContext(), "按钮被点击了", Toast.LENGTH_SHORT).show();
    }

}
