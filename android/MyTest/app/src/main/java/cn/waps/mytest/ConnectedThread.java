package cn.waps.mytest;

import android.bluetooth.BluetoothSocket;
import android.os.Handler;
import android.os.SystemClock;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

public class ConnectedThread extends Thread {
    private final BluetoothSocket mmSocket;
    private final InputStream mmInStream;
    private final OutputStream mmOutStream;
    private final Handler mHandler;

    public ConnectedThread(BluetoothSocket socket, Handler handler) {
        mmSocket = socket;
        mHandler = handler;
        InputStream tmpIn = null;
        OutputStream tmpOut = null;

        // 使用临时对象获取输入和输出流，因为
        // 成员流是最终的
        try {
            tmpIn = socket.getInputStream();
            tmpOut = socket.getOutputStream();
        } catch (IOException e) { }

        mmInStream = tmpIn;
        mmOutStream = tmpOut;
    }

    @Override
    public void run() {
        byte[] buffer ;  // 流的缓冲区存储
        int bytes; //read()返回的字节数
        // 一直监听InputStream，直到出现异常
        while (true) {
            try {
                // 从InputStream中读取
                bytes = mmInStream.available();
                if(bytes != 0) {
                    buffer = new byte[1024];
                    SystemClock.sleep(100); //暂停并等待剩余的数据。根据你的发送速度来调整。
                    bytes = mmInStream.available(); // 有多少字节准备被读取?
                    bytes = mmInStream.read(buffer, 0, bytes); // 记录我们实际读取了多少字节
                    mHandler.obtainMessage(MainActivity.MESSAGE_READ, bytes, -1, buffer)
                            .sendToTarget(); //将获得的字节发送到UI活动
                }
            } catch (IOException e) {
                e.printStackTrace();

                break;
            }
        }
    }

    /* 从主活动中调用此函数，将数据发送到远程设备 */
    public void write(String input) {
        byte[] bytes = input.getBytes();           //将输入的字符串转换为字节
        try {
            mmOutStream.write(bytes);
        } catch (IOException e) { }
    }

    /* 从主活动中调用这个函数来关闭连接 */
    public void cancel() {
        try {
            mmSocket.close();
        } catch (IOException e) { }
    }
}