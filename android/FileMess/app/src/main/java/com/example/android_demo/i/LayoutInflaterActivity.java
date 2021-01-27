package com.example.android_demo.i;

import android.os.Bundle;
import android.widget.Button;
import android.widget.RelativeLayout;

import androidx.appcompat.app.AppCompatActivity;

public class LayoutInflaterActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
//        setContentView(R.layout.activity_layout_inflater);
        Button btnOne = new Button(this);
        RelativeLayout rly = new RelativeLayout(this);
        btnOne.setText("按钮1");
        Button btnTwo = new Button(this);
        btnTwo.setText("按钮2");
        // 为按钮1设置一个id值
        int a = 1234687;
        btnOne.setId(a);
        // 设置按钮1的位置,在父容器中居中
        RelativeLayout.LayoutParams rlp1 = new RelativeLayout.LayoutParams(
                RelativeLayout.LayoutParams.WRAP_CONTENT, RelativeLayout.LayoutParams.WRAP_CONTENT);
        rlp1.addRule(RelativeLayout.CENTER_IN_PARENT);
        // 设置按钮2的位置,在按钮1的下方,并且对齐父容器右面
        RelativeLayout.LayoutParams rlp2 = new RelativeLayout.LayoutParams(
                RelativeLayout.LayoutParams.WRAP_CONTENT, RelativeLayout.LayoutParams.WRAP_CONTENT);
        rlp2.addRule(RelativeLayout.BELOW, 123);
        rlp2.addRule(RelativeLayout.ALIGN_PARENT_RIGHT);
        // 将组件添加到外部容器中
        rly.addView(btnTwo, rlp2);
        rly.addView(btnOne, rlp1);
        // 设置当前视图加载的View即rly
        setContentView(rly);
    }


}
