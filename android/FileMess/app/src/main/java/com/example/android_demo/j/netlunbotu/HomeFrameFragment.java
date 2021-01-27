package com.example.android_demo.j.netlunbotu;

import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ListView;

import com.example.android_demo.R;

import java.util.ArrayList;

public class HomeFrameFragment extends BaseFragment {

    private ListView mListView;

    private String[] datas;

    private HomeFrameFragmentAdapter adapter;

    private static final String TAG = HomeFrameFragment.class.getSimpleName();//"CommonFrameFragment"
    private static final int GET = 1;
    private Handler handler = new Handler() {
        @Override
        public void handleMessage(Message msg) {
            super.handleMessage(msg);
            switch (msg.what) {
                case GET:
                    //获取数据
                    Bundle bd = new Bundle();
                    bd.putStringArrayList("imageId", (ArrayList<String>) msg.obj);
                    // 轮播图
                    Intent intent = new Intent(mContext, ViewPagerActivity.class);
                    intent.putExtras(bd);
                    mContext.startActivity(intent);
                    break;
            }
            //隐藏加载框
            ProgressDialogUtil.dismiss();
        }

    };

    @Override
    protected View initView() {
        View view = View.inflate(mContext, R.layout.fragment_home,null);
        mListView = view.findViewById(R.id.listview);
        mListView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view1, int position, long id) {
                String data = datas[position];
                switch (data.toLowerCase()) {
                    case "viewpager":
                        //显示对话框
                        ProgressDialogUtil.showProgressDialog(mContext);
                        HttpUtil.getInstance().get( handler,GET);
                        break;
                }
            }
        });
        return view;
    }

    @Override
    protected void initData() {
        super.initData();
        //准备数据
        datas = new String[]{"viewpager","OKHttp", "Jni-NDK"};
        //设置适配器
        adapter = new HomeFrameFragmentAdapter(mContext,datas);
        mListView.setAdapter(adapter);
    }


}
