package com.example.demoone.i;

import android.Manifest;
import android.content.Context;
import android.content.pm.PackageManager;
import android.support.v4.app.ActivityCompat;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.telephony.PhoneStateListener;
import android.telephony.SignalStrength;
import android.telephony.TelephonyManager;
import android.widget.TextView;

import com.example.demoone.R;

import java.io.FileNotFoundException;
import java.io.OutputStream;
import java.io.PrintStream;
import java.util.Date;

public class TelephonyManagerActivity extends AppCompatActivity {


    public static final int MY_PERMISSIONS_REQUEST_STORAGE = 12;
    private TextView tv_phone1;
    private TextView tv_phone2;
    private TextView tv_phone3;
    private TextView tv_phone4;
    private TextView tv_phone5;
    private TextView tv_phone6;
    private TextView tv_phone7;
    private TextView tv_phone8;
    private TextView tv_phone9;
    private TelephonyManager tManager;
    private String[] phoneType = {"未知", "2G", "3G", "4G"};
    private String[] simState = {"状态未知", "无SIM卡", "被PIN加锁", "被PUK加锁",
            "被NetWork PIN加锁", "已准备好"};

    private TextView tv_rssi;
    private MyPhoneStateListener mpsListener;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_telephony_manager);
        //①获得系统提供的TelphonyManager对象的实例
        tManager = (TelephonyManager) getSystemService(Context.TELEPHONY_SERVICE);
        bindViews();

        tv_rssi = (TextView) findViewById(R.id.tv_rssi);
        mpsListener  = new MyPhoneStateListener();
        tManager.listen(mpsListener,290);
        // 取得TelephonyManager对象
        tManager = (TelephonyManager)
                getSystemService(Context.TELEPHONY_SERVICE);
        // 创建一个通话状态监听器
        PhoneStateListener listener = new PhoneStateListener()
        {
            @Override
            public void onCallStateChanged(int state, String number)
            {
                switch (state)
                {
                    // 无任何状态
                    case TelephonyManager.CALL_STATE_IDLE:
                        break;
                    case TelephonyManager.CALL_STATE_OFFHOOK:
                        break;
                    // 来电铃响时
                    case TelephonyManager.CALL_STATE_RINGING:
                        OutputStream os = null;
                        try
                        {
                            os = openFileOutput("phoneList", MODE_APPEND);
                        }
                        catch (FileNotFoundException e)
                        {
                            e.printStackTrace();
                        }
                        PrintStream ps = new PrintStream(os);
                        // 将来电号码记录到文件中
                        ps.println(new Date() + " 来电：" + number);
                        ps.close();
                        break;
                    default:
                        break;
                }
                super.onCallStateChanged(state, number);
            }
        };
        // 监听电话通话状态的改变
        tManager.listen(listener, PhoneStateListener.LISTEN_CALL_STATE);
    }

    private class MyPhoneStateListener extends PhoneStateListener {
        private int asu = 0,lastSignal = 0;
        @Override
        public void onSignalStrengthsChanged(SignalStrength signalStrength) {
            asu = signalStrength.getGsmSignalStrength();
            lastSignal = -113 + 2 * asu;
            tv_rssi.setText("当前手机的信号强度：" + lastSignal + " dBm" );
            super.onSignalStrengthsChanged(signalStrength);
        }
    }

    private void bindViews() {
        tv_phone1 = (TextView) findViewById(R.id.tv_phone1);
        tv_phone2 = (TextView) findViewById(R.id.tv_phone2);
        tv_phone3 = (TextView) findViewById(R.id.tv_phone3);
        tv_phone4 = (TextView) findViewById(R.id.tv_phone4);
        tv_phone5 = (TextView) findViewById(R.id.tv_phone5);
        tv_phone6 = (TextView) findViewById(R.id.tv_phone6);
        tv_phone7 = (TextView) findViewById(R.id.tv_phone7);
        tv_phone8 = (TextView) findViewById(R.id.tv_phone8);
        tv_phone9 = (TextView) findViewById(R.id.tv_phone9);

        if (ActivityCompat.checkSelfPermission(this, Manifest.permission.READ_PHONE_STATE) != PackageManager.PERMISSION_GRANTED) {
            // TODO: Consider calling
            //    ActivityCompat#requestPermissions
            // here to request the missing permissions, and then overriding
            //   public void onRequestPermissionsResult(int requestCode, String[] permissions,
            //                                          int[] grantResults)
            // to handle the case where the user grants the permission. See the documentation
            // for ActivityCompat#requestPermissions for more details.
//            ActivityCompat.requestPermissions(this,
//                    new String[]{
//                            Manifest.permission.WRITE_EXTERNAL_STORAGE,
//                            Manifest.permission.READ_EXTERNAL_STORAGE,
//                    },
//                    MY_PERMISSIONS_REQUEST_STORAGE);
            return ;
        }
        tv_phone1.setText("设备编号：" + tManager.getDeviceId());
        tv_phone2.setText("软件版本：" + (tManager.getDeviceSoftwareVersion()!= null? tManager.getDeviceSoftwareVersion():"未知"));
        tv_phone3.setText("运营商代号：" + tManager.getNetworkOperator());
        tv_phone4.setText("运营商名称：" + tManager.getNetworkOperatorName());
        tv_phone5.setText("网络类型：" + phoneType[tManager.getPhoneType()]);
        tv_phone6.setText("设备当前位置：" + (tManager.getCellLocation() != null ? tManager.getCellLocation().toString() : "未知位置"));
        tv_phone7.setText("SIM卡的国别：" + tManager.getSimCountryIso());
        tv_phone8.setText("SIM卡序列号：" + tManager.getSimSerialNumber());
        tv_phone9.setText("SIM卡状态：" + simState[tManager.getSimState()]);
    }
}
