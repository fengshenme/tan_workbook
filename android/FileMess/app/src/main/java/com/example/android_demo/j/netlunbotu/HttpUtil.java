package com.example.android_demo.j.netlunbotu;

import android.os.Handler;
import android.os.Message;

import com.google.gson.Gson;

import java.io.IOException;
import java.util.List;

import retrofit2.Response;
import retrofit2.Retrofit;
import retrofit2.converter.gson.GsonConverterFactory;

public class HttpUtil {

    public  static final String baseHttp = "http://47.94.241.234:9066/";

    private static final HttpUtil instance = new HttpUtil() ;
    // 避免从外部实例化
    private HttpUtil(){}

    // 恶汉式单例
    public static HttpUtil getInstance() {
        return instance;
    }

    private static final Retrofit retrofit = new Retrofit.Builder()
            .addConverterFactory(GsonConverterFactory.create(new Gson()))
            .baseUrl(baseHttp).build();;

    public OkhttpService homeImageIdGet(){
        return retrofit.create(OkhttpService.class) ;
    }

    public void get(Handler handler, int GET){
        new Thread(){
            @Override
            public void run() {
                super.run();
                Response<List<String>> execute = null;
                try {
                    execute = HttpUtil.getInstance().homeImageIdGet().getImageId(6).execute();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                List<String> body = execute.body();
                Message msg = Message.obtain();
                msg.what = GET;
                msg.obj = body;
                handler.sendMessage(msg);
            }
        }.start();
    }



}
