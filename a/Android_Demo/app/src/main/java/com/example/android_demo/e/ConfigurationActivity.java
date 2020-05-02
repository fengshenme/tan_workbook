package com.example.android_demo.e;

import android.content.pm.ActivityInfo;
import android.content.res.Configuration;
import android.os.Build;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import androidx.annotation.RequiresApi;
import androidx.appcompat.app.AppCompatActivity;

import com.example.android_demo.R;


public class ConfigurationActivity extends AppCompatActivity {

    @RequiresApi(api = Build.VERSION_CODES.JELLY_BEAN_MR1)
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_configuration);

        TextView txtResult = (TextView) findViewById(R.id.txtResult);
        StringBuffer status = new StringBuffer();
        //①获取系统的Configuration对象
        Configuration cfg = getResources().getConfiguration();
        //②想查什么查什么
        status.append("densityDpi屏幕密度:" + cfg.densityDpi + "\n");
        status.append("fontScale:当前用户设置的字体的缩放因子:" + cfg.fontScale + "\n");
        status.append("hardKeyboardHidden判断硬键盘是否可见:" + cfg.hardKeyboardHidden + "\n");
        status.append("keyboard获取当前关联额键盘类型:" + cfg.keyboard + "\n");
        status.append("keyboardHidden该属性返回一个boolean值用于标识当前键盘是否可用。该:" + cfg.keyboardHidden + "\n");
        status.append("locale获取用户当前的语言环境:" + cfg.locale + "\n");
        status.append("mcc获取移动信号的国家码:" + cfg.mcc + "\n");
        status.append("mnc获取移动信号的网络码 :" + cfg.mnc + "\n");
        status.append("navigation判断系统上方向导航设备的类型。:" + cfg.navigation + "\n");
        status.append("navigationHidden:" + cfg.navigationHidden + "\n");
        status.append("orientation:获取系统屏幕的方向:" + cfg.orientation + "\n");
        status.append("screenHeightDp屏幕可用高和宽，:" + cfg.screenHeightDp + "\n");
        status.append("screenWidthDp:" + cfg.screenWidthDp + "\n");
        status.append("screenLayout:" + cfg.screenLayout + "\n");
        status.append("smallestScreenWidthDp:" + cfg.densityDpi + "\n");
        status.append("touchscreen获取系统触摸屏的触摸方式:" + cfg.densityDpi + "\n");
        status.append("uiMode:" + cfg.densityDpi + "\n");
        txtResult.setText(status.toString());

        Button btn = (Button) findViewById(R.id.btncahange);
        btn.setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View v) {
                Configuration config = getResources().getConfiguration();
                //如果是横屏的话切换成竖屏
                if(config.orientation == Configuration.ORIENTATION_LANDSCAPE)
                {
                    ConfigurationActivity.this.setRequestedOrientation(ActivityInfo.SCREEN_ORIENTATION_UNSPECIFIED);
                }
                //如果竖屏的话切换成横屏
                if(config.orientation == Configuration.ORIENTATION_PORTRAIT)
                {
                    ConfigurationActivity.this.setRequestedOrientation(ActivityInfo.SCREEN_ORIENTATION_UNSPECIFIED);
                }
            }
        });

    }


    @Override
    public void onConfigurationChanged(Configuration newConfig) {
        super.onConfigurationChanged(newConfig);
        String screen = newConfig.orientation == Configuration.ORIENTATION_LANDSCAPE?"横屏":"竖屏";
        Toast.makeText(ConfigurationActivity.this, "系统屏幕方向发生改变 \n 修改后的方向为" + screen, Toast.LENGTH_SHORT).show();
    }

}
