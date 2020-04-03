package com.example.demoone.d;

import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v4.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import com.example.demoone.R;

/**
 * Created by Jay on 2015/10/8 0008.
 */
public class ContentFragmentA extends Fragment {

    private TextView tv_content;
    private String strContent;
    private int bgColor;

    public ContentFragmentA(){}

    public static final ContentFragmentA newInstance(String strContent,int bgColor)
    {
        ContentFragmentA fragment = new ContentFragmentA();
        Bundle bundle = new Bundle();
        bundle.putInt("bgColor",bgColor);
        bundle.putString("strContent", strContent);
        fragment.setArguments(bundle);

        return fragment ;
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,@Nullable Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fg_content, container, false);
        view.setBackgroundColor(getArguments().getInt("bgColor"));
        tv_content = (TextView) view.findViewById(R.id.tv_content);
        tv_content.setText(getArguments().getString("strContent"));
        return view;
    }


}
