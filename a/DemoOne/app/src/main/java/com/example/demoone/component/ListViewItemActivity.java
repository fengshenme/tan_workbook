package com.example.demoone.component;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.ListView;

import com.example.demoone.R;
import com.example.demoone.entity.App;
import com.example.demoone.entity.Book;
import com.example.demoone.entity.MutiLayoutAdapter;

import java.util.ArrayList;

public class ListViewItemActivity extends AppCompatActivity {

    private static final int TYPE_BOOK = 0;
    private static final int TYPE_APP = 1;
    private ListView list_content;
    private ArrayList<Object> mData = null;
    private MutiLayoutAdapter myAdapter = null;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_list_view_item);

        //数据准备：
        mData = new ArrayList<Object>();
        for(int i = 0;i < 20;i++){
            switch ((int)(Math.random() * 2)){
                case TYPE_BOOK:
                    mData.add(new Book("《第一行代码》","郭霖"));
                    break;
                case TYPE_APP:
                    mData.add(new App(R.mipmap.iv_icon_baidu,"百度"));
                    break;
            }
        }

        list_content =  findViewById(R.id.list_content);
        myAdapter = new MutiLayoutAdapter(ListViewItemActivity.this,mData);
        list_content.setAdapter(myAdapter);
    }
}
