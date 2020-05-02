package com.example.android_demo.g;

import android.os.Bundle;
import android.os.Handler;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

import com.alibaba.fastjson.JSON;
import com.alibaba.fastjson.JSONObject;
import com.example.android_demo.R;

import java.io.IOException;
import java.util.Map;

import okhttp3.Call;
import okhttp3.Callback;
import okhttp3.MediaType;
import okhttp3.OkHttpClient;
import okhttp3.Request;
import okhttp3.RequestBody;
import okhttp3.Response;

public class TestPostActivity extends AppCompatActivity implements View.OnClickListener {

    private final static String LOGIN_URL = "";
    private EditText editNum, editPawd;
    private Button btnLogin;
    private String result = "";

    private Handler handler = new Handler() {
        public void handleMessage(android.os.Message msg) {
            Toast.makeText(TestPostActivity.this, result, Toast.LENGTH_SHORT).show();
        };
    };


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_test_post);
        initView();
        setView();

    }

    private void initView() {
        editNum = (EditText) findViewById(R.id.editNum);
        editPawd = (EditText) findViewById(R.id.editPawd);
        btnLogin = (Button) findViewById(R.id.btnLogin);
    }

    private void setView() {
        btnLogin.setOnClickListener(this);
    }

    @Override
    public void onClick(View v) {
        String url = "http://47.94.241.234:9066/user/login/";
        new Thread() {
            public void run() {
                result = checkUsernameAndPassword(editNum.getText().toString(), editPawd.getText().toString(),url);
                handler.sendEmptyMessage(0x123);
            };
        }.start();
    }


//    public Map<String,String> checkUsernameAndPassword(String phone, String password, String url) {
    public String checkUsernameAndPassword(String phone, String password, String url) {
        //临时数据类型
        JSONObject json = new JSONObject();
        OkHttpClient okHttpClient = new OkHttpClient();
        json.put("mobile", phone);
        json.put("password", password);

        RequestBody body = RequestBody.create(MediaType.parse("application/json; charset=utf-8"), json.toString());
        Request request = new Request.Builder()
                    .addHeader("content-type", "application/json;charset:utf-8")
                    .url(url).post(body).build();

            Call call = okHttpClient.newCall(request);
            call.enqueue(new Callback() {
                @Override
                public void onFailure(Call call, IOException e) {
                    Log.d("a--", "onFailure: "+e.getMessage());
                }
                @Override
                public void onResponse(Call call, Response response) throws IOException {
                    // 来将我们的数据转换成字符串
                    JSONObject jsona = JSON.parseObject(response.body().string());
                    Map mapTypes = jsona;
                    for (Object obj : mapTypes.keySet()){
                        System.out.println("key为："+obj+"值为："+mapTypes.get(obj));
                    }
                    Log.d("b--", "onResponse: " + jsona.get("token"));
                }
            });

        return "resultMap";
    }






}
