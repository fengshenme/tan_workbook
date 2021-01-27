package com.example.android_demo.j;

import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.TextView;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;

import com.example.android_demo.R;

public class JniActivity extends AppCompatActivity {

    private JNI jni;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_jni);
        // Example of a call to a native method
        TextView tv = findViewById(R.id.sample_text);
//        tv.setText(stringFromJNI());
        jni = new JNI();
        tv.setText(jni.stringFromJNI());

        initActionBar();
    }

    /**
     * 定义的标题栏
     */
    public void initActionBar() {
        Toolbar toolbar = findViewById(R.id.toolbar);
        toolbar.setLogo(R.mipmap.icon_a);
        setSupportActionBar(toolbar);
        toolbar.setNavigationIcon(R.mipmap.back_mtrl_am_alpha);
        toolbar.setNavigationOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                finish();
            }
        });

    }

    public void onClick(View view){
        jni.callbackAdd();
        jni.callbackHelloFromJava();
        jni.callbackPrintString();
        jni.callbackSayHello();
        this.callBackShowToast();

        int[] array = {1,2,3,4,5};
        int[] result = jni.increaseArrayEles(array);
        final String simpleName = JniActivity.class.getSimpleName();
        for ( int a: result) {
            Log.e(simpleName,String.valueOf(a));
        }

        int i = jni.checkPwd("1234567");
        Log.e(simpleName,String.valueOf(i));

    }

    /**
     * 让C代码调用JniActivity里面的showToast
     */
    public native void callBackShowToast();
    public void showToast(){
        System.out.println("showToast----------------");
        Toast.makeText(JniActivity.this,"showToast----------------",Toast.LENGTH_SHORT).show();
    }


}

