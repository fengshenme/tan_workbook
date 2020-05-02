package com.example.android_demo;

import android.Manifest;
import android.content.Context;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.os.Build;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.BaseAdapter;
import android.widget.GridView;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

import com.example.android_demo.a.Frame2Activity;
import com.example.android_demo.a.Frame3Activity;
import com.example.android_demo.a.FrameActivity;
import com.example.android_demo.a.GridActivity;
import com.example.android_demo.a.LinearLayoutActivity;
import com.example.android_demo.a.LoginTabActivity;
import com.example.android_demo.a.Relati3Activity;
import com.example.android_demo.a.Relative2Activity;
import com.example.android_demo.a.RelativeActivity;
import com.example.android_demo.a.ShrinkColumnsActivity;
import com.example.android_demo.a.StretchColumnsActivity;
import com.example.android_demo.a.TableActivity;
import com.example.android_demo.b.Button2Activity;
import com.example.android_demo.b.ButtonActivity;
import com.example.android_demo.b.ImgageActivity;
import com.example.android_demo.b.ProgressBarActivity;
import com.example.android_demo.b.RadioButtonActivity;
import com.example.android_demo.b.RatingBarActivity;
import com.example.android_demo.b.ScrollViewActivity;
import com.example.android_demo.b.SeekBarActivity;
import com.example.android_demo.b.Text2Activity;
import com.example.android_demo.b.TextActivity;
import com.example.android_demo.b.TextinfoActivity;
import com.example.android_demo.b.ToggleButtonActivity;
import com.example.android_demo.c.AlertDialogActivity;
import com.example.android_demo.c.ArrayAdapterActivity;
import com.example.android_demo.c.AutoCompleteTextViewActivity;
import com.example.android_demo.c.DatePickerActivity;
import com.example.android_demo.c.DatePickerDialogActivity;
import com.example.android_demo.c.ExpandableListViewActivity;
import com.example.android_demo.c.GridViewActivity;
import com.example.android_demo.c.ListViewActivity;
import com.example.android_demo.c.ListViewDataActivity;
import com.example.android_demo.c.ListViewItemActivity;
import com.example.android_demo.c.NotificationActivity;
import com.example.android_demo.c.OptionMenuActivity;
import com.example.android_demo.c.PopupWindowActivity;
import com.example.android_demo.c.ProgressDialogActivity;
import com.example.android_demo.c.SpinnerActivity;
import com.example.android_demo.c.TextClockActivity;
import com.example.android_demo.c.TimePickerActivity;
import com.example.android_demo.c.ToastActivity;
import com.example.android_demo.c.ViewFlipper2Activity;
import com.example.android_demo.c.ViewFlipperActivity;
import com.example.android_demo.c.entity.MyAdapterGrid;
import com.example.android_demo.d.DrawerLayout2Activity;
import com.example.android_demo.d.DrawerLayoutActivity;
import com.example.android_demo.d.ViewPagerActivity;
import com.example.android_demo.e.AsyncTaskActivity;
import com.example.android_demo.e.CallbackEventActivity;
import com.example.android_demo.e.ConfigurationActivity;
import com.example.android_demo.e.EditText2Activity;
import com.example.android_demo.e.EditTextActivity;
import com.example.android_demo.e.HandlerActivity;
import com.example.android_demo.e.HandlerMessageActivity;
import com.example.android_demo.e.HandlingEventsActivity;
import com.example.android_demo.e.MotionEventActivity;
import com.example.android_demo.e.TouchEventActivity;
import com.example.android_demo.e.TouchListenerActivity;
import com.example.android_demo.f.DynaRegisterActivity;
import com.example.android_demo.f.Fragment1Activity;
import com.example.android_demo.f.Fragment2Activity;
import com.example.android_demo.f.Fragment3Activity;
import com.example.android_demo.f.Fragment4Activity;
import com.example.android_demo.f.Message3Activity;
import com.example.android_demo.f.MessageActivity;
import com.example.android_demo.f.StartSerActivity;
import com.example.android_demo.g.File2Activity;
import com.example.android_demo.g.File3Activity;
import com.example.android_demo.g.HttpClientGetActivity;
import com.example.android_demo.g.HttpGetActivity;
import com.example.android_demo.g.SQLiteActivity;
import com.example.android_demo.g.SharedPreferences2Activity;
import com.example.android_demo.g.SharedPreferencesActivity;
import com.example.android_demo.g.SocketClientActivity;
import com.example.android_demo.g.TestPostActivity;
import com.example.android_demo.g.WebView2Activity;
import com.example.android_demo.g.WebView3Activity;
import com.example.android_demo.g.WebView4Activity;
import com.example.android_demo.g.WebViewActivity;
import com.example.android_demo.g.WebViewCacheActivity;
import com.example.android_demo.g.WebViewErrorActivity;
import com.example.android_demo.g.XmlParseActivity;
import com.example.android_demo.h.AlphaAnimationActivity;
import com.example.android_demo.h.AnimationDrawableActivity;
import com.example.android_demo.h.Drawable0Activity;
import com.example.android_demo.h.DrawingActivity;
import com.example.android_demo.h.FileUploadActivity;
import com.example.android_demo.h.FloatEvaluatorActivity;
import com.example.android_demo.h.LoginRegisterActivity;
import com.example.android_demo.h.MaskFilterActivity;
import com.example.android_demo.h.PropertyAnimationActivity;
import com.example.android_demo.i.AlarmManagerActivity;
import com.example.android_demo.i.AudioManagerActivity;
import com.example.android_demo.i.CameraDemoActivity;
import com.example.android_demo.i.DirectionSensorActivity;
import com.example.android_demo.i.LayoutInflaterActivity;
import com.example.android_demo.i.MediaPlayerActivity;
import com.example.android_demo.i.MediaRecordActivity;
import com.example.android_demo.i.SensorDemoActivity;
import com.example.android_demo.i.SoundPoolActivity;
import com.example.android_demo.i.TelephonyManagerActivity;
import com.example.android_demo.i.VibratorDemoActivity;
import com.example.android_demo.i.WindowManagerActivity;
import com.example.android_demo.j.JniActivity;
import com.example.android_demo.j.netlunbotu.LunBoTuActivity;
import com.example.android_demo.k.ZiDingYiViewActivity;

import java.util.Arrays;
import java.util.List;

public class MainActivity extends AppCompatActivity {



    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        initView2();

        if (Build.VERSION.SDK_INT >= 23) {
            int REQUEST_CODE_CONTACT = 101;
            String[] permissions = {
                    Manifest.permission.WRITE_EXTERNAL_STORAGE,
                    Manifest.permission.READ_SMS,
                    Manifest.permission.INTERNET,
                    Manifest.permission.ACCESS_COARSE_LOCATION,
                    Manifest.permission.READ_PHONE_STATE,
                    Manifest.permission.RECORD_AUDIO,
                    Manifest.permission.READ_CONTACTS,
                    Manifest.permission.CALL_PHONE,
                    Manifest.permission.SYSTEM_ALERT_WINDOW,
                    Manifest.permission.WRITE_CONTACTS,
                    Manifest.permission.VIBRATE,
                    Manifest.permission.CAMERA
            };
            //验证是否许可权限
            for (String str : permissions) {
                if (this.checkSelfPermission(str) != PackageManager.PERMISSION_GRANTED) {
                    //申请权限
                    this.requestPermissions(permissions, REQUEST_CODE_CONTACT);
                    //ActivityCompat.requestPermissions(MainActivity.this,permissions,REQUEST_CODE_CONTACT);
                    return;
                }
            }
        }

    }

    private GridView grid_main;
    private BaseAdapter mAdapter = null;
    private List<String> mData = null;
    public void initView2(){
        grid_main = findViewById(R.id.grid_main);

        mData =  Arrays.asList(getResources().getStringArray(R.array.main_grid_list));

        mAdapter = new MyAdapterGrid<String>(mData, R.layout.main_grid) {
            @Override
            public void bindView(MyAdapterGrid.ViewHolder holder, String obj) {
                holder.setText(R.id.main_text_grid, obj);
            }
        };



        grid_main.setAdapter(mAdapter);
        grid_main.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {

                Toast.makeText(MainActivity.this, "你点击了~" + position + "~项", Toast.LENGTH_SHORT).show();
                Intent intent = new Intent();
                Context con = MainActivity.this;
                intent.setClass(con, a.get(position));
                startActivity(intent);
            }

        });
    }
    private static final List<Class> a = Arrays.asList(new Class[]{LinearLayoutActivity.class, LinearLayoutActivity.class,RelativeActivity.class,Relative2Activity.class,
            Relati3Activity.class,TableActivity.class,StretchColumnsActivity.class,ShrinkColumnsActivity.class,LoginTabActivity.class,FrameActivity.class,
            Frame2Activity.class,Frame3Activity.class,GridActivity.class,TextActivity.class,TextinfoActivity.class,Text2Activity.class,ButtonActivity.class,
            Button2Activity.class,ImgageActivity.class,RadioButtonActivity.class,SeekBarActivity.class,ToggleButtonActivity.class,ProgressBarActivity.class,
            RatingBarActivity.class,ScrollViewActivity.class,TextClockActivity.class,DatePickerActivity.class,TimePickerActivity.class,ArrayAdapterActivity.class,
            ListViewActivity.class,ListViewDataActivity.class,ListViewItemActivity.class,GridViewActivity.class,SpinnerActivity.class, AutoCompleteTextViewActivity.class,
            ExpandableListViewActivity.class, ViewFlipperActivity.class,ViewFlipper2Activity.class,ToastActivity.class,NotificationActivity.class,AlertDialogActivity.class,
            ProgressDialogActivity.class,DatePickerDialogActivity.class,PopupWindowActivity.class,OptionMenuActivity.class,ViewPagerActivity.class,DrawerLayoutActivity.class,
            DrawerLayout2Activity.class, HandlingEventsActivity.class,CallbackEventActivity.class, HandlerMessageActivity.class,HandlerActivity.class,TouchListenerActivity.class,
            TouchEventActivity.class,MotionEventActivity.class,EditTextActivity.class,EditText2Activity.class,ConfigurationActivity.class,AsyncTaskActivity.class,
            MessageActivity.class, Message3Activity.class,StartSerActivity.class,DynaRegisterActivity.class,Fragment1Activity.class,Fragment2Activity.class,Fragment3Activity.class,
            Fragment4Activity.class,File2Activity.class,File3Activity.class,SharedPreferencesActivity.class,SharedPreferences2Activity.class,SQLiteActivity.class
            ,HttpGetActivity.class,TestPostActivity.class,HttpClientGetActivity.class,XmlParseActivity.class,WebViewActivity.class,WebView2Activity.class, WebView3Activity.class
            , WebView4Activity.class,WebViewCacheActivity.class,WebViewErrorActivity.class,SocketClientActivity.class,FileUploadActivity.class,Drawable0Activity.class
            ,DrawingActivity.class,MaskFilterActivity.class,AnimationDrawableActivity.class,AlphaAnimationActivity.class,LoginRegisterActivity.class, PropertyAnimationActivity.class
            ,FloatEvaluatorActivity.class,SoundPoolActivity.class,MediaPlayerActivity.class,CameraDemoActivity.class,MediaRecordActivity.class,TelephonyManagerActivity.class
            ,AudioManagerActivity.class,VibratorDemoActivity.class,AlarmManagerActivity.class,WindowManagerActivity.class,LayoutInflaterActivity.class,
            SensorDemoActivity.class,DirectionSensorActivity.class,JniActivity.class,LunBoTuActivity.class,ZiDingYiViewActivity.class

    });
    //XML数据解析 XmlParseActivity.class
    // web视图WebViewActivity.class
    // web视图
    // 电话管理器TelephonyManagerActivity
    // 振动器
    // 闹钟服务AlarmManagerActivity.class
    // 窗口管理WindowManagerActivity.class
    // 传感器SensorDemoActivity.class
    // 方向传感器DirectionSensorActivity.class
    // Jni - c c++ demoJniActivity.class
    // 轮播图 okhttp
    // 自定义view
    // 进度条对话框// ExpandableListViewActivity // 选项菜单 上下文菜单 子菜单OptionMenuActivity
    // 视图滑动切换ViewPagerActivity//官方侧滑菜单DrawerLayoutActivity.class // 左右两个侧滑菜单的实现DrawerLayout2Activity.class
    //基于监听的事件处理机制HandlingEventsActivity.class
    //基于回调的事件处理机制CallbackEventActivity.class
    // Handler消息传递机制浅析 HandlerMessageActivity.class
    // Handler写在子线程中HandlerActivity.class
    // 基于回调的onTouchEvent( )方法TouchEventActivity.class
    // 多点触控MotionEventActivity.class
    // 监听EditText的内容变化EditTextActivity.class)
    // 密码是否可见EditText2Activity.class
    // 查询配置ConfigurationActivity.class
    // 一个异步操作AsyncTaskActivity.class

    // 活动之间的消息传递MessageActivity.class
    // 消息回馈  Message3Activity.class
    // 验证StartService启动Service的调用顺序StartSerActivity.class
    // 动态广播 DynaRegisterActivity.class
    // 底部栏实现Fragment1Activity.class
    // 底部栏实现2 Fragment2Activity
    // 底部栏实现3Fragment3Activity
    // 文件读写 File3Activity.class
    //  数据存储与访问 SharedPreferencesActivity.class
    //  数据加密存储与访问 SharedPreferences2Activity.class
    // http get demo HttpGetActivity.class


}

