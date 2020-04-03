package com.example.demoone.g;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.webkit.CookieManager;
import android.webkit.WebSettings;
import android.webkit.WebView;
import android.webkit.WebViewClient;
import android.widget.Button;
import android.widget.Toast;

import com.example.demoone.R;
import com.example.demoone.g.entity.MyWebView;

public class WebView2Activity extends AppCompatActivity {

    private MyWebView wView;
    private Button btn_icon;
    private long exitTime = 0;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_web_view2);
        btn_icon = (Button) findViewById(R.id.btn_icon);
        wView = (MyWebView) findViewById(R.id.wViewa);
//        wView.loadUrl("http://blog.csdn.net/coder_pig");
        wView.loadUrl("http://www.baidu.com");
        wView.setWebViewClient(new WebViewClient() {
            //在webview里打开新链接
            @Override
            public boolean shouldOverrideUrlLoading(WebView view, String url) {
                view.loadUrl(url);
                return true;
            }

            @Override
            public void onPageFinished(WebView view, String url) {
                //获取屏幕高度，另外因为网页可能进行缩放了，所以需要乘以缩放比例得出的才是实际的尺寸
                Log.e("HEHE", wView.getContentHeight() * wView.getScale() + "");
                CookieManager cookieManager = CookieManager.getInstance();
                String CookieStr = cookieManager.getCookie(url);
                Log.e("HEHE", "Cookies = " + CookieStr);
                super.onPageFinished(view, url);

            }
        });

        //比如这里做一个简单的判断，当页面发生滚动，显示那个Button
        wView.setOnScrollChangedCallback(new MyWebView.OnScrollChangedCallback() {
            @Override
            public void onScroll(int dx, int dy) {
                if (dy > 0) {
                    btn_icon.setVisibility(View.VISIBLE);
                } else {
                    btn_icon.setVisibility(View.GONE);
                }
            }
        });

        btn_icon.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                wView.setScrollY(0);
                btn_icon.setVisibility(View.GONE);
            }
        });
        WebSettings settings = wView.getSettings();
        settings.setUseWideViewPort(true);//设定支持viewport
        settings.setLoadWithOverviewMode(true);   //自适应屏幕
        settings.setBuiltInZoomControls(true);
        settings.setDisplayZoomControls(false);
        settings.setSupportZoom(true);//设定支持缩放

        CookieManager cm = CookieManager.getInstance();




    }

    @Override
    public void onBackPressed() {
        if (wView.canGoBack()) {
            wView.goBack();
        } else {
            if ((System.currentTimeMillis() - exitTime) > 2000) {
                Toast.makeText(getApplicationContext(), "再按一次退出程序",
                        Toast.LENGTH_SHORT).show();
                exitTime = System.currentTimeMillis();
            } else {
                finish();
            }

        }
    }

}
