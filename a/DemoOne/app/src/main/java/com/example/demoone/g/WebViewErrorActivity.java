package com.example.demoone.g;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.webkit.WebView;
import android.webkit.WebViewClient;
import android.widget.Button;
import android.widget.ImageView;

import com.example.demoone.R;

import java.net.InetAddress;
import java.net.UnknownHostException;
import java.util.Arrays;

public class WebViewErrorActivity extends AppCompatActivity implements View.OnClickListener{

    private WebView wView;
    private ImageView img_error_back;
    private Button btn_refresh;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_web_view_error);

        wView = findViewById(R.id.wView);
        img_error_back = findViewById(R.id.img_error_back);
        btn_refresh = findViewById(R.id.btn_refresh);
        wView.loadUrl("http://www.baidu.com");
        wView.setWebViewClient(new WebViewClient() {
            //设置在webView点击打开的新网页在当前界面显示,而不跳转到新的浏览器中
            @Override
            public boolean shouldOverrideUrlLoading(WebView view, String url) {
                view.loadUrl(url);
                return true;
            }

            @Override
            public void onReceivedError(WebView view, int errorCode, String description, String failingUrl) {
                super.onReceivedError(view, errorCode, description, failingUrl);
                wView.setVisibility(View.GONE);
                img_error_back.setVisibility(View.VISIBLE);
            }
        });
        btn_refresh.setOnClickListener(this);
    }

    @Override
    public void onClick(View v) {
        wView.loadUrl("http://www.baidu.com");
        img_error_back.setVisibility(View.GONE);
        wView.setVisibility(View.VISIBLE);
    }

}
