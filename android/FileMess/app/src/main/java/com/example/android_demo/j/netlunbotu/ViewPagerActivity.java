package com.example.android_demo.j.netlunbotu;

import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.view.View;
import android.widget.LinearLayout;

import androidx.appcompat.app.AppCompatActivity;
import androidx.viewpager.widget.ViewPager;

import com.example.android_demo.R;

import java.util.ArrayList;
import java.util.List;

public class ViewPagerActivity extends AppCompatActivity {

    private ViewPager viewPager;
    private static List<String> adlist = new ArrayList<>(3);
    private LinearLayout linearDot;
    private Handler handler = new Handler() {
        @Override
        public void handleMessage(Message msg) {
            viewPager.setCurrentItem(viewPager.getCurrentItem() + 1);
            handler.sendEmptyMessageDelayed(0, 3000);

        }
    };

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_view_pager_lunbotu);

        viewPager =  findViewById(R.id.viewpager);
        linearDot =  findViewById(R.id.dot);

        initListener();
        initData();

    }

    private void initListener() {
        viewPager.addOnPageChangeListener(new ViewPager.OnPageChangeListener() {
            @Override
            public void onPageSelected(int position) { updateTextAndDot(); }
            @Override
            public void onPageScrolled(int position, float positionOffset, int positionOffsetPixels) { }
            @Override
            public void onPageScrollStateChanged(int state) {  }
        });
    }


    private void initData()  {
        //获得Intent对象,并且用Bundle出去里面的数据
        Intent it = getIntent();
        Bundle bd = it.getExtras();
        //按键值的方式取出Bundle中的数据
        adlist = bd.getStringArrayList("imageId");
        for (int i = 0; i < adlist.size(); i++) {
            View view = new View(this);
            LinearLayout.LayoutParams params = new LinearLayout.LayoutParams(8,8);
            if(i!=0){
                params.leftMargin=5;
            }
            view.setLayoutParams(params);
            view.setBackgroundResource(R.drawable.selecter_dot);
            linearDot.addView(view);
        }

        // 通过适配器引入图片
        viewPager.setAdapter(new MyViewPager(ViewPagerActivity.this,adlist));
        int centerValue = Integer.MAX_VALUE / 2;
        int value = centerValue % adlist.size();
        viewPager.setCurrentItem(centerValue - value);

        // 更新文本内容
        updateTextAndDot();

        handler.sendEmptyMessageDelayed(0, 3000);
    }

    private void updateTextAndDot() {
        int currentPage = viewPager.getCurrentItem() % adlist.size();

        // 改变dot
        for (int i = 0; i < linearDot.getChildCount(); i++) {
            linearDot.getChildAt(i).setEnabled(i == currentPage);
        }
    }


}
