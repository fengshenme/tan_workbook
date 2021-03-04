package cn.waps.mytest;

import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;
import androidx.core.content.ContextCompat;

import android.Manifest;
import android.app.AlertDialog;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.os.Handler;
import android.os.Looper;
import android.os.Message;
import android.util.Log;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;

import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.lang.reflect.Method;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.UUID;

public class MainActivity extends AppCompatActivity {

    private final String TAG = MainActivity.class.getSimpleName();

    private static final UUID BT_MODULE_UUID = UUID.fromString("00001101-0000-1000-8000-00805F9B34FB"); // "random" unique identifier

    // #defines for identifying shared types between calling functions
    private final static int REQUEST_ENABLE_BT = 1; // used to identify adding bluetooth names
    public final static int MESSAGE_READ = 2; // used in bluetooth handler to identify message update
    private final static int CONNECTING_STATUS = 3; // used in bluetooth handler to identify message status

    // GUI Components
    private TextView mBluetoothStatus;
    private TextView mSendText;
    private Button mScanBtn;
    private Button mOffBtn;
    private Button mListPairedDevicesBtn;
    private ListView mReadListView;
    private Button mbtSend;

    private BluetoothAdapter mBTAdapter;
    private Set<BluetoothDevice> mPairedDevices;
    private ArrayAdapter<String> mBTArrayAdapter;

    private ArrayAdapter<String> mReadArrayAdapter;

    private Handler mHandler; // Our main handler that will receive callback notifications
    private ConnectedThread mConnectedThread; // bluetooth background worker thread to send and receive data
    private BluetoothSocket mBTSocket = null; // bi-directional client-to-client data path

    private Map cmdMap = new HashMap<Integer, String>(8);

    private String find_name = "";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        mBluetoothStatus = findViewById(R.id.bluetooth_status);
        mSendText = findViewById(R.id.editText_send);
        mScanBtn = findViewById(R.id.on_bt);
        mOffBtn = findViewById(R.id.off_bt);
        mListPairedDevicesBtn = findViewById(R.id.paired_btn);
        mbtSend = findViewById(R.id.bt_send);

        cmdMap.put(R.id.findTemp_bt, "temp");
        cmdMap.put(R.id.find_distance_bt, "getdistance");
        cmdMap.put(R.id.gas_strength_bt, "comgas");
        cmdMap.put(R.id.register_card_bt, "card_reg");
        cmdMap.put(R.id.led1_bt, "led1");
        cmdMap.put(R.id.led2_bt, "led2");
        cmdMap.put(R.id.beep_bt, "beep");

        mBTArrayAdapter = new ArrayAdapter<>(this, android.R.layout.simple_list_item_1);
        mBTAdapter = BluetoothAdapter.getDefaultAdapter(); //  get a handle on the bluetooth radio

        mReadArrayAdapter = new ArrayAdapter<>(this, android.R.layout.simple_list_item_1);
        mReadListView = findViewById(R.id.read_list_view);
        mReadListView.setAdapter(mReadArrayAdapter);
        mReadListView.setOnItemClickListener(mReadClickListener);

        // 如果没有被允许，请求许可
        if (ContextCompat.checkSelfPermission(this, Manifest.permission.BLUETOOTH) != PackageManager.PERMISSION_GRANTED)
            ActivityCompat.requestPermissions(this, new String[]{Manifest.permission.BLUETOOTH}, 1);
        if (ContextCompat.checkSelfPermission(this, Manifest.permission.BLUETOOTH_ADMIN) != PackageManager.PERMISSION_GRANTED)
            ActivityCompat.requestPermissions(this, new String[]{Manifest.permission.BLUETOOTH_ADMIN}, 1);

        mHandler = new Handler(Looper.getMainLooper()) {
            @Override
            public void handleMessage(Message msg) {
                if (msg.what == MESSAGE_READ) {
                    String readMessage = null;
                    try {
                        readMessage = new String((byte[]) msg.obj, "UTF-8");
                    } catch (UnsupportedEncodingException e) {
                        e.printStackTrace();
                    }
                    mReadArrayAdapter.add(find_name + ":" + readMessage);
                    find_name = "";
                }

                if (msg.what == CONNECTING_STATUS) {
                    if (msg.arg1 == 1)
                        mBluetoothStatus.setText("连接到设备: " + msg.obj);
                    else
                        mBluetoothStatus.setText("连接失败");
                }
            }
        };

        if (mBTArrayAdapter == null) {
            // 设备不支持蓝牙
            mBluetoothStatus.setText("Status: Bluetooth not found");
            Toast.makeText(getApplicationContext(), "没有找到蓝牙设备!", Toast.LENGTH_SHORT).show();
        } else {

            mbtSend.setOnClickListener(v -> send_cmd(mSendText.getText().toString()));

            mScanBtn.setOnClickListener((v) -> bluetoothOn());

            mOffBtn.setOnClickListener((View v) -> bluetoothOff());

            mListPairedDevicesBtn.setOnClickListener(v -> listPairedDevices(v));

        }
    }

    private void bluetoothOn() {
        if (!mBTAdapter.isEnabled()) {
            Intent enableBtIntent = new Intent(BluetoothAdapter.ACTION_REQUEST_ENABLE);
            startActivityForResult(enableBtIntent, REQUEST_ENABLE_BT);
            mBluetoothStatus.setText("Bluetooth enabled");
            Toast.makeText(getApplicationContext(), "蓝牙打开", Toast.LENGTH_SHORT).show();
        } else {
            Toast.makeText(getApplicationContext(), "蓝牙已经开启", Toast.LENGTH_SHORT).show();
        }
    }

    // 当用户选择“是”或“否”来启用无线电时，请输入此处
    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent Data) {
        // Check which request we're responding to
        super.onActivityResult(requestCode, resultCode, Data);
        if (requestCode == REQUEST_ENABLE_BT) {
            // Make sure the request was successful
            if (resultCode == RESULT_OK) {
                // The user picked a contact.
                // The Intent's data Uri identifies which contact was selected.
                mBluetoothStatus.setText("已开启");
            } else
                mBluetoothStatus.setText("已关闭");
        }
    }

    private void bluetoothOff() {
        mBTAdapter.disable(); // turn off
        mBluetoothStatus.setText("关闭蓝牙");
        Toast.makeText(getApplicationContext(), "蓝牙已关闭", Toast.LENGTH_SHORT).show();
    }


    private void listPairedDevices(View v) {
        mBTArrayAdapter.clear();

        mPairedDevices = mBTAdapter.getBondedDevices();
        if (mBTAdapter.isEnabled()) {
            // 把它放到适配器上
            for (BluetoothDevice device : mPairedDevices)
                mBTArrayAdapter.add(device.getName() + "\n" + device.getAddress());

            Toast.makeText(getApplicationContext(), "已配对的设备", Toast.LENGTH_SHORT).show();
        } else
            Toast.makeText(getApplicationContext(), "蓝牙没有打开", Toast.LENGTH_SHORT).show();

        if(mConnectedThread != null){
            mConnectedThread.cancel();
            mBluetoothStatus.setText("未连接");
            mConnectedThread = null;
        }
        new AlertDialog.Builder(MainActivity.this)
                .setTitle("点击要连接的蓝牙")
                .setAdapter(mBTArrayAdapter, (dialog, which) -> {

                    if (!mBTAdapter.isEnabled()) {
                        Toast.makeText(getBaseContext(), "蓝牙没有打开", Toast.LENGTH_SHORT).show();
                        return;
                    }

                    mBluetoothStatus.setText("连接中...");
                    // 获取设备MAC地址，它是视图中的最后17个字符
                    String info = mBTArrayAdapter.getItem(which).toString();
                    Log.i("%s", info);
                    final String address = info.substring(info.length() - 17);
                    final String name = info.substring(0, info.length() - 17);

                    // 生成一个新线程以避免阻塞GUI线程
                    new Thread() {
                        @Override
                        public void run() {
                            boolean fail = false;

                            BluetoothDevice device = mBTAdapter.getRemoteDevice(address);

                            try {
                                mBTSocket = createBluetoothSocket(device);
                            } catch (IOException e) {
                                fail = true;
                                Toast.makeText(getBaseContext(), "套接字创建失败", Toast.LENGTH_SHORT).show();
                            }
                            // 建立蓝牙socket连接。
                            try {
                                mBTSocket.connect();
                            } catch (IOException e) {
                                Log.e(TAG, "连接失败", e);
                                try {
                                    fail = true;
                                    mBTSocket.close();
                                    mHandler.obtainMessage(CONNECTING_STATUS, -1, -1)
                                            .sendToTarget();
                                } catch (IOException e2) {
                                    //insert code to deal with this
                                    Toast.makeText(getBaseContext(), "套接字创建失败", Toast.LENGTH_SHORT).show();
                                }
                            }
                            if (!fail) {
                                mConnectedThread = new ConnectedThread(mBTSocket, mHandler);
                                mConnectedThread.start();

                                mHandler.obtainMessage(CONNECTING_STATUS, 1, -1, name)
                                        .sendToTarget();
                            }


                        }
                    }.start();
                })
                .setNegativeButton(android.R.string.cancel, (dialog, which) -> dialog.dismiss())
                .show();


    }

    private AdapterView.OnItemClickListener mReadClickListener = new AdapterView.OnItemClickListener() {
        @Override
        public void onItemClick(AdapterView<?> parent, View view, int position, long id) {

            new AlertDialog.Builder(MainActivity.this)
                    .setTitle("是否清除接收")

                    .setPositiveButton("确定", (dialog, which) -> mReadArrayAdapter.clear())
                    // 第一个对话框有个 取消 按钮
                    .setNegativeButton(android.R.string.cancel, (dialog, which) -> dialog.dismiss())
                    .show();
        }
    };

    private BluetoothSocket createBluetoothSocket(BluetoothDevice device) throws IOException {
        try {
            final Method m = device.getClass().getMethod("createInsecureRfcommSocketToServiceRecord", UUID.class);
            return (BluetoothSocket) m.invoke(device, BT_MODULE_UUID);
        } catch (Exception e) {
            Log.e(TAG, "无法创建不安全的RFComm连接", e);
        }
        return device.createRfcommSocketToServiceRecord(BT_MODULE_UUID);
    }

    /**
     * 要发送的指令文本
     *
     * @param sendText
     */
    private void send_cmd(String sendText) {


        if (mConnectedThread != null && mBTSocket != null) // 首先检查以确保线程已创建
        {
            mConnectedThread.wr_stop();
            mConnectedThread = new ConnectedThread(mBTSocket, mHandler);
            mConnectedThread.start();
            Toast.makeText(getApplicationContext(), sendText, Toast.LENGTH_SHORT).show();
            mConnectedThread.write(sendText);
            time_cou();
        } else
            Toast.makeText(getBaseContext(), "没有连接设备", Toast.LENGTH_SHORT).show();
    }

    public void send_cmd_bt(View v) {

        if (mBTArrayAdapter == null) {
            Toast.makeText(getApplicationContext(), "蓝牙设备没有连接!", Toast.LENGTH_SHORT).show();
            return;
        }

        Button bt = (Button) v;
        find_name = bt.getText().toString();
        send_cmd(cmdMap.get(v.getId()) + "\r\n");

    }

    private void time_cou() {
        // 生成一个新线程以避免阻塞GUI线程 读取信息10秒时
        new Thread() {
            @Override
            public void run() {
                for (int i = 0; i < 11; i++) {
                    try {
                        sleep(1000);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
                if(mConnectedThread != null)
                mConnectedThread.wr_stop();

            }
        }.start();
    }
}