package com.example.demoone.g;

import android.os.Handler;
import android.os.Message;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import com.example.demoone.R;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.InetAddress;
import java.net.Socket;

public class SocketClientActivity extends AppCompatActivity   {

    //定义相关变量,完成初始化
    private TextView txtshow;
    private EditText editsend;
    private Button btnsend;
    private static final String HOST = "192.168.0.69";
    private static final int PORT = 12345;
    private Socket socket = null;
    private BufferedReader in = null;
    private PrintWriter out = null;
    private String content = "";
    private StringBuilder sb = null;

    //定义一个handler对象,用来刷新界面
    public Handler handler = new Handler() {
        public void handleMessage(Message msg) {
            if (msg.what == 0x123) {
                sb.append(content);
                txtshow.setText(sb.toString());
            }
        }
    };


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_socket_client);
        sb = new StringBuilder();
        txtshow = findViewById(R.id.txtshow);
        editsend = findViewById(R.id.editsend);
        btnsend = findViewById(R.id.btnsend);

        //当程序一开始运行的时候就实例化Socket对象,与服务端进行连接,获取输入输出流
        //因为4.0以后不能再主线程中进行网络操作,所以需要另外开辟一个线程
        new Thread() {
            public void run() {
                try {
                    socket = new Socket(HOST, PORT);
                    in = new BufferedReader(new InputStreamReader(socket.getInputStream(), "UTF-8"));
                    out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(socket.getOutputStream())), true);
                    while (true) {
                        if (socket.isConnected()) {
                            if (!socket.isInputShutdown()) {
                                if ((content = in.readLine()) != null) {
                                    content += "\n";
                                    handler.sendEmptyMessage(0x123);
                                }
                            }
                        }
                    }
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }.start();
        //为发送按钮设置点击事件
        btnsend.setOnClickListener(v -> {

            String msg = editsend.getText().toString();
            // 不能再主线程中进行网络操作,所以需要另外开辟一个线程
            new Thread(){
                public void run() {
                    if (socket.isConnected()) {
                        if (!socket.isOutputShutdown()) {
                            out.println(msg);
                        }
                    }
                }
            }.start();
        });
    }

}
