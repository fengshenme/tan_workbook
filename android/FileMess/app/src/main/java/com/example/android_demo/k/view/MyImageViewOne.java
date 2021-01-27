package com.example.android_demo.k.view;

import android.content.Context;
import android.content.res.TypedArray;
import android.util.AttributeSet;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.TextView;

import com.example.android_demo.R;

public class MyImageViewOne extends LinearLayout {

    ImageView iv ;
    TextView tv ;

    public MyImageViewOne(Context context) {
        super(context);
        View view = LayoutInflater.from(context).inflate(R.layout.view_header_k, this, true);

    }

    public MyImageViewOne(Context context, AttributeSet attrs) {
        super(context, attrs);
        View view = LayoutInflater.from(context).inflate(R.layout.image_text_k, this, true);

        int resourceId = -1;
        TypedArray typedArray = context.obtainStyledAttributes(attrs, R.styleable.MyImageView);
         iv = view.findViewById(R.id.top_image_k);
         tv = view.findViewById(R.id.bottom_text_k);

        int N = typedArray.getIndexCount();
        for (int i = 0; i < N; i++) {
            int attr = typedArray.getIndex(i);

            switch (attr) {
                case R.styleable.MyImageView_Oriental:
                    resourceId = typedArray.getInt( R.styleable.MyImageView_Oriental, 0);
                    this.setOrientation(resourceId == 1 ? LinearLayout.HORIZONTAL : LinearLayout.VERTICAL);
                    break;

                case R.styleable.MyImageView_Text:
                    resourceId = typedArray.getResourceId(  R.styleable.MyImageView_Text, 0);
                    tv.setText(resourceId > 0 ? typedArray.getResources().getText( resourceId)
                            : typedArray.getString(R.styleable.MyImageView_Text));
                    break;
                case R.styleable.MyImageView_Src:
                    resourceId = typedArray.getResourceId( R.styleable.MyImageView_Src, 0);
                    iv.setImageResource(resourceId > 0 ?resourceId:R.drawable.ic_launcher);
                    break;
            }

        }

        typedArray.recycle();

    }

}
