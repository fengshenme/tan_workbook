package com.example.demoone;

import android.Manifest;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.os.Build;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.view.WindowManager;

import com.example.demoone.base.Button2Activity;
import com.example.demoone.base.ButtonActivity;
import com.example.demoone.base.ImgageActivity;
import com.example.demoone.base.ProgressBarActivity;
import com.example.demoone.base.RadioButtonActivity;
import com.example.demoone.base.RatingBarActivity;
import com.example.demoone.base.ScrollViewActivity;
import com.example.demoone.base.SeekBarActivity;
import com.example.demoone.base.Text2Activity;
import com.example.demoone.base.TextActivity;
import com.example.demoone.alayout.Frame2Activity;
import com.example.demoone.alayout.Frame3Activity;
import com.example.demoone.alayout.FrameActivity;
import com.example.demoone.alayout.GridActivity;
import com.example.demoone.alayout.LinearLayout2Activity;
import com.example.demoone.alayout.LinearLayoutActivity;
import com.example.demoone.alayout.LoginTabActivity;
import com.example.demoone.alayout.Relati3Activity;
import com.example.demoone.alayout.Relative2Activity;
import com.example.demoone.alayout.RelativeActivity;
import com.example.demoone.alayout.ShrinkColumnsActivity;
import com.example.demoone.alayout.StretchColumnsActivity;
import com.example.demoone.alayout.TableActivity;
import com.example.demoone.base.TextinfoActivity;
import com.example.demoone.base.ToggleButtonActivity;
import com.example.demoone.c.AlertDialogActivity;
import com.example.demoone.c.DatePickerDialogActivity;
import com.example.demoone.c.NotificationActivity;
import com.example.demoone.c.OptionMenuActivity;
import com.example.demoone.c.PopupWindowActivity;
import com.example.demoone.c.ProgressDialogActivity;
import com.example.demoone.c.ToastActivity;
import com.example.demoone.c.ViewFlipper2Activity;
import com.example.demoone.c.ViewFlipperActivity;
import com.example.demoone.component.ArrayAdapterActivity;
import com.example.demoone.component.AutoCompleteTextViewActivity;
import com.example.demoone.component.DatePickerActivity;
import com.example.demoone.component.ExpandableListViewActivity;
import com.example.demoone.component.GridViewActivity;
import com.example.demoone.component.ListViewActivity;
import com.example.demoone.component.ListViewDataActivity;
import com.example.demoone.component.ListViewItemActivity;
import com.example.demoone.component.SpinnerActivity;
import com.example.demoone.component.TextClockActivity;
import com.example.demoone.component.TimePickerActivity;
import com.example.demoone.d.DrawerLayout2Activity;
import com.example.demoone.d.DrawerLayoutActivity;
import com.example.demoone.d.ViewPagerActivity;
import com.example.demoone.e.AsyncTaskActivity;
import com.example.demoone.e.CallbackEventActivity;
import com.example.demoone.e.ConfigurationActivity;
import com.example.demoone.e.EditText2Activity;
import com.example.demoone.e.EditTextActivity;
import com.example.demoone.e.HandlerActivity;
import com.example.demoone.e.HandlerMessageActivity;
import com.example.demoone.e.HandlingEventsActivity;
import com.example.demoone.e.MotionEventActivity;
import com.example.demoone.e.TouchEventActivity;
import com.example.demoone.e.TouchListenerActivity;
import com.example.demoone.f.DynaRegisterActivity;
import com.example.demoone.f.Fragment1Activity;
import com.example.demoone.f.Fragment2Activity;
import com.example.demoone.f.Fragment3Activity;
import com.example.demoone.f.Fragment4Activity;
import com.example.demoone.f.Message3Activity;
import com.example.demoone.f.MessageActivity;
import com.example.demoone.f.StartSerActivity;
import com.example.demoone.g.File2Activity;
import com.example.demoone.g.File3Activity;
import com.example.demoone.g.HttpClientGetActivity;
import com.example.demoone.g.HttpGetActivity;
import com.example.demoone.g.SQLiteActivity;
import com.example.demoone.g.SharedPreferences2Activity;
import com.example.demoone.g.SharedPreferencesActivity;
import com.example.demoone.g.SocketClientActivity;
import com.example.demoone.g.TestPostActivity;
import com.example.demoone.g.WebView2Activity;
import com.example.demoone.g.WebView3Activity;
import com.example.demoone.g.WebView4Activity;
import com.example.demoone.g.WebViewActivity;
import com.example.demoone.g.WebViewCacheActivity;
import com.example.demoone.g.WebViewErrorActivity;
import com.example.demoone.g.XmlParseActivity;
import com.example.demoone.h.AlphaAnimationActivity;
import com.example.demoone.h.AnimationDrawableActivity;
import com.example.demoone.h.Drawable0Activity;
import com.example.demoone.h.DrawingActivity;
import com.example.demoone.h.FileUploadActivity;
import com.example.demoone.h.FloatEvaluatorActivity;
import com.example.demoone.h.LoginRegisterActivity;
import com.example.demoone.h.MaskFilterActivity;
import com.example.demoone.h.PropertyAnimationActivity;
import com.example.demoone.i.AlarmManagerActivity;
import com.example.demoone.i.AudioManagerActivity;
import com.example.demoone.i.CameraDemoActivity;
import com.example.demoone.i.DirectionSensorActivity;
import com.example.demoone.i.LayoutInflaterActivity;
import com.example.demoone.i.MediaPlayerActivity;
import com.example.demoone.i.MediaRecordActivity;
import com.example.demoone.i.SensorDemoActivity;
import com.example.demoone.i.SoundPoolActivity;
import com.example.demoone.i.TelephonyManagerActivity;
import com.example.demoone.i.VibratorDemoActivity;
import com.example.demoone.i.WindowManagerActivity;

public class MainActivity extends AppCompatActivity {

    public static final String EXTRA_MESSAGE = "com.example.demoone.MESSAGE" ;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

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


    /** Called when the user taps the Send button */
    public void sendMessage(View view) {
        Intent intent = new Intent(this, LinearLayoutActivity.class);
//        EditText editText = (EditText) findViewById(R.id.editText);
//        String message = editText.getText().toString();
//        intent.putExtra(EXTRA_MESSAGE, message);
        startActivity(intent);
    }

    public void sendMessage2(View view) {
        Intent intent = new Intent(this, LinearLayout2Activity.class);
        startActivity(intent);
    }

    public void send3(View view) {
        Intent intent = new Intent(this, RelativeActivity.class);
        startActivity(intent);
    }

    public void send4(View view) {
        Intent intent = new Intent(this, Relative2Activity.class);
        startActivity(intent);
    }
    public void send5(View view) {
        Intent intent = new Intent(this, Relati3Activity.class);
        startActivity(intent);
    }
    public void sendTable(View view) {
        Intent intent = new Intent(this, TableActivity.class);
        startActivity(intent);
    }
  public void sendTable2(View view) {
        Intent intent = new Intent(this, StretchColumnsActivity.class);
        startActivity(intent);
    }
  public void sendTable3(View view) {
        Intent intent = new Intent(this, ShrinkColumnsActivity.class);
        startActivity(intent);
    }

  public void sendTable4(View view) {
        Intent intent = new Intent(this, LoginTabActivity.class);
        startActivity(intent);
    }

    public void sendFrame(View view) {
        Intent intent = new Intent(this, FrameActivity.class);
        startActivity(intent);
    }

    public void sendFrame2(View view) {
        Intent intent = new Intent(this, Frame2Activity.class);
        startActivity(intent);
    }
    public void sendFrame3(View view) {
        Intent intent = new Intent(this, Frame3Activity.class);
        startActivity(intent);
    }
    public void sendGrid(View view) {
        Intent intent = new Intent(this, GridActivity.class);
        startActivity(intent);
    }
    public void skipText(View view) {
        Intent intent = new Intent(this, TextActivity.class);
        startActivity(intent);
    }
    public void skipText2(View view) {
        Intent intent = new Intent(this, TextinfoActivity.class);
        startActivity(intent);
    }
    public void skipText3(View view) {
        Intent intent = new Intent(this, Text2Activity.class);
        startActivity(intent);
    }
    public void skipButton(View view) {
        Intent intent = new Intent(this, ButtonActivity.class);
        startActivity(intent);
    }
    public void skipButton2(View view) {
        Intent intent = new Intent(this, Button2Activity.class);
        startActivity(intent);
    }
    public void skipImage(View view) {
        Intent intent = new Intent(this, ImgageActivity.class);
        startActivity(intent);
    }
    public void skipRadio(View view) {
        Intent intent = new Intent(this, RadioButtonActivity.class);
        startActivity(intent);
    }
    public void skipSeekBar(View view) {
        Intent intent = new Intent(this, SeekBarActivity.class);
        startActivity(intent);
    }
    public void skipToggleButton(View view) {
        Intent intent = new Intent(this, ToggleButtonActivity.class);
        startActivity(intent);
    }
    public void ProgressBar(View view) {
        Intent intent = new Intent(this, ProgressBarActivity.class);
        startActivity(intent);
    }
    public void RatingBar(View view) {
        Intent intent = new Intent(this, RatingBarActivity.class);
        startActivity(intent);
    }
    public void ScrollView(View view) {
        Intent intent = new Intent(this, ScrollViewActivity.class);
        startActivity(intent);
    }
    public void TextClock(View view) {
        Intent intent = new Intent(this, TextClockActivity.class);
        startActivity(intent);
    }
    public void DatePicker(View view) {
        Intent intent = new Intent(this, DatePickerActivity.class);
        startActivity(intent);
    }
    public void TimePicker(View view) {
        Intent intent = new Intent(this, TimePickerActivity.class);
        startActivity(intent);
    }
    public void ArrayAdapter(View view) {
        Intent intent = new Intent(this, ArrayAdapterActivity.class);
        startActivity(intent);
    }
    public void ListView(View view) {
        Intent intent = new Intent(this, ListViewActivity.class);
        startActivity(intent);
    }
    public void ListViewData(View view) {
        Intent intent = new Intent(this, ListViewDataActivity.class);
        startActivity(intent);
    }
    public void ListViewItem(View view) {
        Intent intent = new Intent(this, ListViewItemActivity.class);
        startActivity(intent);
    }
    public void GridView(View view) {
        Intent intent = new Intent(this, GridViewActivity.class);
        startActivity(intent);
    }
    public void Spinner(View view) {
        Intent intent = new Intent(this, SpinnerActivity.class);
        startActivity(intent);
    }
    public void AutoCompleteTextView(View view) {
        Intent intent = new Intent(this, AutoCompleteTextViewActivity.class);
        startActivity(intent);
    }
    public void ExpandableListView(View view) { // ExpandableListViewActivity
        Intent intent = new Intent(this, ExpandableListViewActivity.class);
        startActivity(intent);
    }
    public void ViewFlipper(View view) { // ExpandableListViewActivity
        Intent intent = new Intent(this, ViewFlipperActivity.class);
        startActivity(intent);
    }
    public void ViewFlipper2(View view) { // ExpandableListViewActivity
        Intent intent = new Intent(this, ViewFlipper2Activity.class);
        startActivity(intent);
    }
    public void Toasta(View view) { // ExpandableListViewActivity
        Intent intent = new Intent(this, ToastActivity.class);
        startActivity(intent);
    }
    public void Notification(View view) { // ExpandableListViewActivity
        Intent intent = new Intent(this, NotificationActivity.class);
        startActivity(intent);
    }
    public void AlertDialog(View view) { // ExpandableListViewActivity
        Intent intent = new Intent(this, AlertDialogActivity.class);
        startActivity(intent);
    }
    public void progressDialog(View view) { // ExpandableListViewActivity
        Intent intent = new Intent(this, ProgressDialogActivity.class);
        startActivity(intent);
    }
    public void datePickerDialog(View view) { // ExpandableListViewActivity
        Intent intent = new Intent(this, DatePickerDialogActivity.class);
        startActivity(intent);
    }
    public void PopupWindow(View view) {
        Intent intent = new Intent(this, PopupWindowActivity.class);
        startActivity(intent);
    }
    // 选项菜单 上下文菜单 子菜单
    public void OptionMenu(View view) {
        Intent intent = new Intent(this, OptionMenuActivity.class);
        startActivity(intent);
    }
    // 视图滑动切换
    public void ViewPager(View view) {
        Intent intent = new Intent(this, ViewPagerActivity.class);
        startActivity(intent);
    }
    //官方侧滑菜单
    public void DrawerLayout(View view) {
        Intent intent = new Intent(this, DrawerLayoutActivity.class);
        startActivity(intent);
    }
    // 左右两个侧滑菜单的实现
    public void DrawerLayout2(View view) {
        Intent intent = new Intent(this, DrawerLayout2Activity.class);
        startActivity(intent);
    }
    //基于监听的事件处理机制
    public void HandlingEvents(View view) {
        Intent intent = new Intent(this, HandlingEventsActivity.class);
        startActivity(intent);
    }
    //基于回调的事件处理机制
    public void CallbackEvent(View view) {
        Intent intent = new Intent(this, CallbackEventActivity.class);
        startActivity(intent);
    }
    // Handler消息传递机制浅析
    public void HandlerMessage(View view) {
        Intent intent = new Intent(this, HandlerMessageActivity.class);
        startActivity(intent);
    }
    // Handler写在子线程中
    public void Handler0(View view) {
        Intent intent = new Intent(this, HandlerActivity.class);
        startActivity(intent);
    }
    public void TouchListener(View view) {
        Intent intent = new Intent(this, TouchListenerActivity.class);
        startActivity(intent);
    }
    // 基于回调的onTouchEvent( )方法
    public void TouchEvent(View view) {
        Intent intent = new Intent(this, TouchEventActivity.class);
        startActivity(intent);
    }
    // 多点触控
    public void MotionEvent(View view) {
        Intent intent = new Intent(this, MotionEventActivity.class);
        startActivity(intent);
    }
    // 监听EditText的内容变化
    public void EditText(View view) {
        Intent intent = new Intent(this, EditTextActivity.class);
        startActivity(intent);
    }
    // 密码是否可见
    public void EditText2(View view) {
        Intent intent = new Intent(this, EditText2Activity.class);
        startActivity(intent);
    }
    // 查询配置
    public void Configuration(View view) {
        Intent intent = new Intent(this, ConfigurationActivity.class);
        startActivity(intent);
    }
    // 一个异步操作
    public void AsyncTask(View view) {
        Intent intent = new Intent(this, AsyncTaskActivity.class);
        startActivity(intent);
    }

    // 活动之间的消息传递
    public void Message0(View view) {
        Intent intent = new Intent(this, MessageActivity.class);
        startActivity(intent);
    }
    // 消息回馈
    public void Message3(View view) {
        Intent intent = new Intent(this, Message3Activity.class);
        startActivity(intent);
    }
    // 验证StartService启动Service的调用顺序
    public void StartSer(View view) {
        Intent intent = new Intent(this, StartSerActivity.class);
        startActivity(intent);
    }
    // 动态广播
    public void DynaRegister(View view) {
        Intent intent = new Intent(this, DynaRegisterActivity.class);
        startActivity(intent);
    }
    // 底部栏实现
    public void Fragment1(View view) {
        Intent intent = new Intent(this, Fragment1Activity.class);
        startActivity(intent);
    }
    // 底部栏实现2
    public void Fragment2(View view) {
        Intent intent = new Intent(this, Fragment2Activity.class);
        startActivity(intent);

    }
    // 底部栏实现3
    public void Fragment3(View view) {
        Intent intent = new Intent(this, Fragment3Activity.class);
        startActivity(intent);

    }
    public void Fragment4(View view) {
        Intent intent = new Intent(this, Fragment4Activity.class);
        startActivity(intent);
    }
    public void File2(View view) {
        Intent intent = new Intent(this, File2Activity.class);
        startActivity(intent);
    }
    // 文件读写
    public void File3(View view) {
        Intent intent = new Intent(this, File3Activity.class);
        startActivity(intent);
    }
    //  数据存储与访问
    public void SharedPreferences(View view) {
        Intent intent = new Intent(this, SharedPreferencesActivity.class);
        startActivity(intent);
    }
    //  数据加密存储与访问
    public void SharedPreferences2(View view) {
        Intent intent = new Intent(this, SharedPreferences2Activity.class);
        startActivity(intent);
    }
    public void SQLiteDemo(View view) {
        Intent intent = new Intent(this, SQLiteActivity.class);
        startActivity(intent);
    }
    // http get demo
    public void HttpGet(View view) {
        Intent intent = new Intent(this, HttpGetActivity.class);
        startActivity(intent);
    }
    public void TestPost(View view) {
        Intent intent = new Intent(this, TestPostActivity.class);
        startActivity(intent);
    }
    public void HttpClientGet(View view) {
        Intent intent = new Intent(this, HttpClientGetActivity.class);
        startActivity(intent);
    }
    //XML数据解析
    public void XmlParse(View view) {
        Intent intent = new Intent(this, XmlParseActivity.class);
        startActivity(intent);
    }
    // web视图
    public void WebView(View view) {
        Intent intent = new Intent(this, WebViewActivity.class);
        startActivity(intent);
    }
    // web视图
    public void WebView2(View view) {
        Intent intent = new Intent(this, WebView2Activity.class);
        startActivity(intent);
    }
    public void WebView3(View view) {
        Intent intent = new Intent(this, WebView3Activity.class);
        startActivity(intent);
    }
    public void WebView4(View view) {
        Intent intent = new Intent(this, WebView4Activity.class);
        startActivity(intent);
    }
    public void WebViewCache(View view) {
        Intent intent = new Intent(this, WebViewCacheActivity.class);
        startActivity(intent);
    }
    public void WebViewError(View view) {
        Intent intent = new Intent(this, WebViewErrorActivity.class);
        startActivity(intent);
    }
    public void SocketClient(View view) {
        Intent intent = new Intent(this, SocketClientActivity.class);
        startActivity(intent);
    }
    public void FileUpload(View view) {
        Intent intent = new Intent(this, FileUploadActivity.class);
        startActivity(intent);
    }
    public void Drawable0(View view) {
        Intent intent = new Intent(this, Drawable0Activity.class);
        startActivity(intent);
    }
    public void Drawing(View view) {
        Intent intent = new Intent(this, DrawingActivity.class);
        startActivity(intent);
    }
    public void MaskFilter(View view) {
        Intent intent = new Intent(this, MaskFilterActivity.class);
        startActivity(intent);
    }
    public void AnimationDrawable(View view) {
        Intent intent = new Intent(this, AnimationDrawableActivity.class);
        startActivity(intent);
    }
    public void AlphaAnimation(View view) {
        Intent intent = new Intent(this, AlphaAnimationActivity.class);
        startActivity(intent);
    }
    public void LoginRegister(View view) {
        Intent intent = new Intent(this, LoginRegisterActivity.class);
        startActivity(intent);
    }
    public void PropertyAnimation(View view) {
        Intent intent = new Intent(this, PropertyAnimationActivity.class);
        startActivity(intent);
    }
    public void FloatEvaluator(View view) {
        Intent intent = new Intent(this, FloatEvaluatorActivity.class);
        startActivity(intent);
    }
    public void SoundPool(View view) {
        Intent intent = new Intent(this, SoundPoolActivity.class);
        startActivity(intent);
    }
    public void MediaPlayer(View view) {
        Intent intent = new Intent(this, MediaPlayerActivity.class);
        startActivity(intent);
    }
    public void CameraDemo(View view) {
        Intent intent = new Intent(this, CameraDemoActivity.class);
        startActivity(intent);
    }
    public void MediaRecord(View view) {
        Intent intent = new Intent(this, MediaRecordActivity.class);
        startActivity(intent);
    }
    // 电话管理器
    public void TelephonyManager(View view) {
        Intent intent = new Intent(this, TelephonyManagerActivity.class);
        startActivity(intent);
    }
    public void AudioManager(View view) {
        Intent intent = new Intent(this, AudioManagerActivity.class);
        startActivity(intent);
    }
    // 振动器
    public void VibratorDemo(View view) {
        Intent intent = new Intent(this, VibratorDemoActivity.class);
        startActivity(intent);
    }
    // 闹钟服务
    public void AlarmManager(View view) {
        Intent intent = new Intent(this, AlarmManagerActivity.class);
        startActivity(intent);
    }
    // 窗口管理
    public void WindowManager(View view) {
        Intent intent = new Intent(this, WindowManagerActivity.class);
        startActivity(intent);
    }
    public void LayoutInflater(View view) {
        Intent intent = new Intent(this, LayoutInflaterActivity.class);
        startActivity(intent);
    }
    // 传感器
    public void SensorDemo(View view) {
        Intent intent = new Intent(this, SensorDemoActivity.class);
        startActivity(intent);
    }
    // 方向传感器
    public void DirectionSensor(View view) {
        Intent intent = new Intent(this, DirectionSensorActivity.class);
        startActivity(intent);
    }



}
