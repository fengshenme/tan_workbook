package com.example.android_demo.j.netlunbotu;

import android.content.Context;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;

import androidx.viewpager.widget.PagerAdapter;

import com.bumptech.glide.Glide;
import com.example.android_demo.R;

import java.util.List;

public class MyViewPager extends PagerAdapter {

    private Context mcontext ;

    private List<String> adlist;

    public MyViewPager(Context mc, List alist){
        this.mcontext = mc;
        this.adlist = alist;
    }

        @Override
        public int getCount() {
            return Integer.MAX_VALUE;
        }

        /**
         * true表示无需创建 false表示需要创建
         */
        @Override
        public boolean isViewFromObject(View view, Object object) {
            return view == object;
        }

        /**
         * 设置view 最多3个界面
         */
        @Override
        public Object instantiateItem(ViewGroup container, int position) {
            String imageId = adlist.get(position % adlist.size());
            View view = View.inflate(mcontext, R.layout.vp_adapter, null);
            ImageView image = view.findViewById(R.id.image);
            Glide.with(mcontext).load(HttpUtil.baseHttp+"img/file/"+imageId).into(image);
            container.addView(view);
            return view;
        }

        /**
         * 销毁page position:当前要销毁第几个page object：当前需要销毁的page
         */
        @Override
        public void destroyItem(ViewGroup container, int position, Object object) {
            // super.destroyItem(container, position, object);
            container.removeView((View) object);
        }
    }