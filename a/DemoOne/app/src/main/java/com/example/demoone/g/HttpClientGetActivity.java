package com.example.demoone.g;

import android.os.Handler;
import android.os.Message;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.webkit.WebView;
import android.widget.Button;

import com.example.demoone.R;


import java.io.IOException;

import okhttp3.Call;
import okhttp3.Callback;
import okhttp3.OkHttpClient;
import okhttp3.Request;
import okhttp3.Response;

public class HttpClientGetActivity extends AppCompatActivity implements View.OnClickListener {

    private Button btnGet;
    private WebView wView;
    public static final int SHOW_DATA = 0X123;
    private String detail = "";

    private Handler handler = new Handler() {
        public void handleMessage(Message msg) {
            if(msg.what == SHOW_DATA)
            {
                wView.loadDataWithBaseURL("",detail, "text/html","UTF-8","");
            }
        };
    };

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_http_client_get);
        initView();
        setView();
    }

    private void initView() {
        btnGet = (Button) findViewById(R.id.btnGet);
        wView = (WebView) findViewById(R.id.wView);
    }

    private void setView() {
        btnGet.setOnClickListener(this);
        wView.getSettings().setDomStorageEnabled(true);
    }
    @Override
    public void onClick(View v) {
        if (v.getId() == R.id.btnGet) {
            GetByHttpClient();
        }
    }


    private void GetByHttpClient() {

        new Thread() {
            public void run() {
                    String url = "http://wwww.baidu.com";
                    OkHttpClient okHttpClient = new OkHttpClient();
                    final Request request = new Request.Builder().url(url)
                            .get()//默认就是GET请求，可以不写
                            .build();
                    Call call = okHttpClient.newCall(request);
                    call.enqueue(new Callback() {
                        @Override
                        public void onFailure(Call call, IOException e) {
                            Log.d("a--", "onFailure: "+e.getMessage());
                        }
                        @Override
                        public void onResponse(Call call, Response response) throws IOException {
                            // 来将我们的数据转换成字符串
                            detail = response.body().string();
                            handler.sendEmptyMessage(SHOW_DATA);
//                            Log.d("b--", "onResponse: " + detail);
                        }
                    });
            };
        }.start();
    }


}
